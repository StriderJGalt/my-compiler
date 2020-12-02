extern bool DEBUG_PRINT;

class LoopInfo {
public:
    llvm::BasicBlock *after, *body;
    llvm::Value* condition;
    string loop_var;
    llvm::PHINode* phi_var;
    LoopInfo(llvm::BasicBlock *bb1, llvm::BasicBlock *bb2,
                llvm::Value* v, std::string s, llvm::PHINode* p)
             : after(bb1), body(bb2), condition(v), loop_var(s), phi_var(p) {}
};


class CodegenVisitor: public ASTvisitor {
public:
    llvm::LLVMContext Context;
    llvm::IRBuilder<> *Builder;
    llvm::Module *Module;
    std::map<std::string, llvm::AllocaInst*> NamedValues;
    std::stack<LoopInfo*> loops;

    CodegenVisitor()
    {
        Builder = new llvm::IRBuilder<>(Context);
        Module = new llvm::Module("Minic Compiler", Context);
    }

    llvm::AllocaInst* CreateEntryBlockAllocation(llvm::Function* function, std::string* v, type t)
    {
        std::string varName = *v;
        llvm::IRBuilder<> temp(&function->getEntryBlock(),function->getEntryBlock().begin());
        llvm::AllocaInst* allocate_instruction = nullptr;
        if(t == I)
        {
            allocate_instruction = temp.CreateAlloca(llvm::Type::getInt32Ty(Context), 0, varName);
        }
        else if (t == B)
        {
            allocate_instruction = temp.CreateAlloca(llvm::Type::getInt1Ty(Context), 0, varName);
        }
        return allocate_instruction;
    }
    
    llvm::Value* LogError(std::string err_str)
    {
        std::cerr << err_str << endl;
        return nullptr;
    }
    
    void generateCode()
    {
        Module->print(llvm::outs(), nullptr);
    }

    llvm::Value* visit(ASTProg &node)
    {
        llvm::Value* v;
        for(auto s : node.statements) 
        {
            v = s->accept(*this);
            if(!v) 
            {
                LogError("Invalid global statements");
            }
        }
        return v;
    }

    llvm::Value* visit(ASTStatementCompound &node)
    {
        llvm::Value *v = nullptr;
        for (auto stmt : node.statements) 
        {
            v = stmt->accept(*this);
            if(!v)
            {
                std::cerr << "Codegen exiting block due to invalid statement declaration\n";
                return nullptr;
            }
        }  
        return v;
    }

    llvm::Value* visit(ASTStatementVariableDeclaration &node)
    {
        llvm::Function *F = Builder->GetInsertBlock()->getParent();

        string varname = node.getId();
        string* ptr_var_name = &varname;
        

        // if(node.getType() == I) 
        // {
        //     initial_value = llvm::ConstantInt::get(Context, llvm::APInt(32, 0));
        // } 
        // else if (node.getType() == B) 
        // {
        //     initial_value = llvm::ConstantInt::get(Context, llvm::APInt(1, 0));
        // }

        llvm::Value* initial_value = node.getExpr()->accept(*this);

        llvm::AllocaInst* alloca = CreateEntryBlockAllocation(F, ptr_var_name, node.getType());

        Builder->CreateStore(initial_value, alloca);

        NamedValues[*ptr_var_name] = alloca;

        llvm::Value* v = llvm::ConstantInt::get(Context, llvm::APInt(32, 1));

        // assign
        // llvm::Value* lhs_location = NamedValues[*ptr_var_name];
        // if(!lhs_location) 
        // lhs_location = Module->getNamedGlobal(*ptr_var_name);
        // if(!lhs_location) 
        // {
        //     LogError("Could not find variable");
        //     return nullptr;
        // }
        // if(!lhs_location){

        //     std::cerr << "Codegen exiting Assignment Statement due to error in lvalue location\n";
        //     return nullptr;
        // }
        // llvm::Value* lhs_value = Builder->CreateLoad(lhs_location);

        // llvm::Value* rhs = node.getExpr()->accept(*this);
        // if(!rhs)
        // {
        //     std::cerr << "Codegen exiting Assignment Statement due to error in rvalue expression\n";
        //     return nullptr;
        // }

        // return Builder->CreateStore(rhs, lhs_location);

        return v;
    }

    llvm::Value* visit(ASTStatementArrayDeclaration &node)
    {
        return nullptr;
    }
    llvm::Value* visit(ASTStatementVariableAssignment &node)
    {
        llvm::Value* lhs_location = NamedValues[node.getId()];
        if(!lhs_location) 
            lhs_location = Module->getNamedGlobal(node.getId());;
        if(!lhs_location){

            std::cerr << "Codegen exiting Assignment Statement due to error in lvalue location\n";

            return nullptr;
        }

        llvm::Value* lhs_value = Builder->CreateLoad(lhs_location);

        llvm::Value* rhs = node.getExpr()->accept(*this);
        if(!rhs){

            std::cerr << "Codegen exiting Assignment Statement due to error in rvalue expression\n";

            return nullptr;
        }

        return Builder->CreateStore(rhs, lhs_location);
    }

    llvm::Value* visit(ASTStatement1DArrayElementAssignment &node)
    {
        return nullptr;
    }
    llvm::Value* visit(ASTStatement2DArrayElementAssignment &node)
    {
        return nullptr;
    }

    llvm::Value* visit(ASTStatementFunctionDeclaration &node)
    {
        std::vector<llvm::Type*> argument_types;
        for (auto argument : node.arguments) 
        {
            if (argument->getType() == I)
            {
                argument_types.push_back(llvm::Type::getInt32Ty(Context));
            } 
            else if (argument->getType() == B) 
            {
                argument_types.push_back(llvm::Type::getInt1Ty(Context));
            } 
            else 
            {
                std::cerr << "Invalid argument type\n";
                return nullptr;
            }
        }

        llvm::Type* returnType;
        if(node.getType() == I) 
        {
            returnType = llvm::Type::getInt32Ty(Context);
        } 
        else if (node.getType()  == B) 
        {
            returnType = llvm::Type::getInt1Ty(Context);
        } 
        else 
        {
            LogError("Invalid return type for function " + node.getId());
            return nullptr;
        }

        // Create the llvm function
        llvm::FunctionType* FT = llvm::FunctionType::get(
            returnType, argument_types, false);
        llvm::Function* F = llvm::Function::Create(
            FT, llvm::Function::ExternalLinkage, node.getId(), Module);

        // Set names for arguments
        std::vector<ASTStatementFunctionDeclarationArgument *>::iterator my_arg_it = node.arguments.begin();
        llvm::Function::arg_iterator llvm_arg_it = F->arg_begin();
        while(my_arg_it != node.arguments.end() and llvm_arg_it != F->arg_end()) {
            ASTStatementFunctionDeclarationArgument *my_arg = *my_arg_it;
            llvm_arg_it->setName(my_arg->getId());
            my_arg_it++; llvm_arg_it++;
        }

        // Create block for function
        llvm::BasicBlock *BB = llvm::BasicBlock::Create(Context, "entry", F);
        Builder->SetInsertPoint(BB);

        // Save old scope
        std::map<std::string, llvm::AllocaInst*> oldNamedValues = NamedValues;

        // Allocate stack memory
        my_arg_it = node.arguments.begin();
        llvm_arg_it = F->arg_begin();
        while(my_arg_it != node.arguments.end() and llvm_arg_it != F->arg_end())
        {
            ASTStatementFunctionDeclarationArgument* my_arg_ptr = *my_arg_it;
            string temp = my_arg_ptr->getId();
            llvm::AllocaInst* alloca = CreateEntryBlockAllocation(F, &(temp), my_arg_ptr->getType());
            Builder->CreateStore(llvm_arg_it, alloca);
            // Adding argument names to named values
            NamedValues[my_arg_ptr->getId()] = alloca;
            my_arg_it++; 
            llvm_arg_it++;
        }

        // Generate code for body with current named values
        llvm::Value* retval = node.getStatement()->accept(*this);

        // Reset old named values
        NamedValues = oldNamedValues;

        // Match and store return type
        if(!retval) {
            std::cerr << "Codegen exiting method declaration due to invalid return" << " type from function block\n";
            F->eraseFromParent();
            return nullptr;
        }

        llvm::verifyFunction(*F);
        return F;
    }

    llvm::Value* visit(ASTStatementFunctionDeclarationArgumentVariable &node)
    {
        return nullptr;
    }
    llvm::Value* visit(ASTStatementFunctionDeclarationArgumentArray1D &node)
    {
        return nullptr;
    }
    llvm::Value* visit(ASTStatementFunctionDeclarationArgumentArray2D &node)
    {
        return nullptr;
    }
    llvm::Value* visit(ASTStatementIfElse &node)
    {
        return nullptr;
    }
    llvm::Value* visit(ASTStatementForLoop &node)
    {
        return nullptr;
    }
    llvm::Value* visit(ASTStatementWhileLoop &node)
    {
        return nullptr;
    }

    llvm::Value* visit(ASTStatementReturn &node)
    {
        llvm::Function* F = Builder->GetInsertBlock()->getParent();
        llvm::Type* Ty = F->getReturnType();
        llvm::Value* v = llvm::ConstantInt::get(Context, llvm::APInt(32, 1));

        if(node.getExpr() == nullptr)
        {
            LogError("Void return statement in non-void function");
            return nullptr;
        }

        v = node.getExpr()->accept(*this);

        unsigned int v_size = v->getType()->getPrimitiveSizeInBits();
        if (v_size == 0)
            v_size = v->getType()->getContainedType(0)->getPrimitiveSizeInBits();

        if(Ty->getPrimitiveSizeInBits() != v_size) {
            std::cerr << "something went wrong\n";
            return nullptr;
        }

        if(!v){
            std::cerr << "Codegen exiting return statement due to error in " << "return expression" <<endl;
            return nullptr;
        }
        Builder->CreateRet(v);
        return v;
    }

    llvm::Value* visit(ASTExprFunctionCall &node)
    {
        llvm::Function* callee = Module->getFunction(node.getId());
        if(!callee)
        {
            // LogError("Callout: " + (node.getId()));
            llvm::IntegerType *t = llvm::Type::getInt32Ty(Context);
            llvm::FunctionType *ftype = llvm::FunctionType::get(t, true);
            callee = llvm::Function::Create(ftype, llvm::GlobalValue::ExternalLinkage, node.getId(), Module);
            
        }
        else if(callee->arg_size() != node.arguments.size())
        {
            LogError("Mismatch in number of arguments in " + node.getId()+ ". Expected " +  std::to_string(callee->arg_size())+ ", but got " + std::to_string(node.arguments.size()));
            return nullptr;
        }

        std::vector<llvm::Value*> call_arguments;
        for(ASTExpr * expr_arg : node.arguments)
        {
            llvm::Value* val = expr_arg->accept(*this);
            if(!val){
                std::cerr << "Codegen exiting method call with invalid argument\n";
                return nullptr;
            }
            call_arguments.push_back(val);
        }
        llvm::Value* v = Builder->CreateCall(callee, call_arguments);
        return v;
    }

    llvm::Value* visit(ASTExprStringLiteral &node)
    {
        if(DEBUG_PRINT)
        cout << "visiting string literal" << endl;
        llvm::Value* v = Builder->CreateGlobalStringPtr((node.getValue()));
        return v;
    }

    llvm::Value* visit(ASTExprIntegerLiteral &node)
    {
        if(DEBUG_PRINT)
        cout << "visiting int literal" << endl;
        llvm::Value* v = llvm::ConstantInt::get(Context, llvm::APInt(32, static_cast<uint64_t>(node.getValue()), true));
        return v;
    }

    llvm::Value* visit(ASTExprCharLiteral &node)
    {
        // Dummy
        if(DEBUG_PRINT)
        cout << "visiting char literal" << endl;
        return nullptr;
    }

    llvm::Value* visit(ASTExprVariable &node)
    {
        llvm::Value* v = NamedValues[node.getId()];
        if(!v) 
        v = Module->getNamedGlobal(node.getId());
        if(!v) {
            LogError("Could not find variable name: " + node.getId());
            std::cerr << "Codegen exiting location due to unknown variable name\n";
            return nullptr;
        }

        return v;
    }       

    llvm::Value* visit(ASTExprUnaryOp &node)
    {
        llvm::Value* v = node.getExpr()->accept(*this);
        if(!v) 
        {
            std::cerr << "Error in unary expression"<<endl;
            return v;
        }
            v = Builder->CreateNot(v, "nottmp");
        return v;
    }

    llvm::Value* visit(ASTExprBinaryOp &node)
    {
        llvm::Value* left = node.getLeft()->accept(*this);
        if(!left) {
            std::cerr << "Error in left expression" << endl;
            return nullptr;
        }
        llvm::Value* right = node.getRight()->accept(*this);
        if(!right) {
            std::cerr << "Error in right expression" << endl;
            return nullptr;
        }

        llvm::Value* v = nullptr;
        
        if (node.getOperator() == Add)
        {
            v = Builder->CreateAdd(left, right, "addtmp");
        } 
        else if (node.getOperator() == Subtract)
        {
            v = Builder->CreateSub(left, right, "subtmp");
        }
        else if (node.getOperator() == Multiply) 
        {
            v = Builder->CreateMul(left, right, "multmp");
        }
        else if (node.getOperator() == Divide) 
        {
            v = Builder->CreateSDiv(left, right, "divtmp");
        }
        else if (node.getOperator() == Remainder) 
        {
            v = Builder->CreateSRem(left, right, "modtmp");
        }
        else if (node.getOperator() == LessThan) 
        {
            v = Builder->CreateICmpSLT(left, right, "ltcmptmp");
        }
        else if (node.getOperator() == GreaterThan) 
        {
            v = Builder->CreateICmpSGT(left, right, "gtcmptmp");
        }
        else if (node.getOperator() == LessThanOrEqualTo) 
        {
            v = Builder->CreateICmpSLE(left, right, "lecmptmp");
        }
        else if (node.getOperator() == GreaterThanOrEqualTo) 
        {
            v = Builder->CreateICmpSGE(left, right, "gecmptmp");
        }
        else if (node.getOperator() == EqualTo) 
        {
            v = Builder->CreateICmpEQ(left, right, "equalcmptmp");
        }
        else if (node.getOperator() == NotEqualTo) 
        {
            v = Builder->CreateICmpNE(left, right, "notequalcmptmp");
        }
        else if (node.getOperator() == AND) 
        {
            v = Builder->CreateAnd(left, right, "andtmp");
        }
        else if (node.getOperator() == OR) 
        {
            v = Builder->CreateOr(left, right, "ortmp");
        }
        return v;
    }

    llvm::Value* visit(ASTExpr1DArrayElement &node)
    {
        return nullptr;
    }
    llvm::Value* visit(ASTExpr2DArrayElement &node)
    {
        return nullptr;
    }
    llvm::Value* visit(ASTExprTernaryOp &node)
    {
        return nullptr;
    }

    virtual ~CodegenVisitor() {};

};

