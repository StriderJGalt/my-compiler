#include "ast.h"

class CodegenVisitor: public ASTVisitor {
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
    llvm::Value* visit(ASTStatementCompound &node)   
    
    llvm::Value* visit(ASTStatementVariableDeclaration &node)
    {
        llvm::Function *F = Builder->GetInsertBlock()->getParent();
        std::string* ptr_var_name = &node.getId()
        
        llvm::Value* initial_val = nullptr;
        llvm::AllocaInst* alloca = nullptr;

        if(node.getType() == I) 
        {
            initial_val = llvm::ConstantInt::get(Context, llvm::APInt(32, 0));
        } 
        else if (node.getType() == B) 
        {
            initial_val = llvm::ConstantInt::get(Context, llvm::APInt(1, 0));
        }
        alloca = CreateEntryBlockAllocation(F, ptr_var_name, node.getType());
        Builder->CreateStore(initial_val, alloca);
        NamedValues[*ptr_var_name] = alloca;
    }

    llvm::Value* visit(ASTStatementArrayDeclaration &node)
    llvm::Value* visit(ASTStatementVariableAssignment &node)
    llvm::Value* visit(ASTStatement1DArrayElementAssignment &node)
    llvm::Value* visit(ASTStatement2DArrayElementAssignment &node)
    llvm::Value* visit(ASTStatementFunctionDeclaration &node)
    llvm::Value* visit(ASTStatementFunctionDeclarationArgumentVariable &node)
    llvm::Value* visit(ASTStatementFunctionDeclarationArgumentArray1D &node)
    llvm::Value* visit(ASTStatementFunctionDeclarationArgumentArray2D &node)
    llvm::Value* visit(ASTStatementIfElse &node)
    llvm::Value* visit(ASTStatementForLoop &node)
    llvm::Value* visit(ASTStatementWhileLoop &node)
    llvm::Value* visit(ASTStatementReturn &node)

    llvm::Value* visit(ASTExprFunctionCall &node)
    {
        llvm::Function* callee = Module->getFunction(*(node.getId()));
        if(!callee)
        {
            LogError("Unknown function name: " + (node.getId()));
            return nullptr;
        }
        if(callee->arg_size() != mcall.expr_args->size())
        {
            LogError("Mismatch in number of arguments in " + node.getId()+ ". Expected " +  std::to_string(callee->arg_size())+ ", but got " + std::to_string(node.arguments.size()));
            return nullptr;
        }

        std::vector<llvm::Value*> call_arguments;
        for(Expression* expr_arg : node.arguments)
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
        cout << "visiting string literal" << endl;
        llvm::Value* v = Builder->CreateGlobalStringPtr((node.getValue()));
        return v;
    }

    llvm::Value* visit(ASTExprIntegerLiteral &node)
    {
        cout << "visiting int literal" << endl;
        llvm::Value* v = llvm::ConstantInt::get(Context, llvm::APInt(32, static_cast<uint64_t>(node.getValue()), true));
        return v;
    }

    llvm::Value* visit(ASTExprCharLiteral &node)
    {
        // Dummy
        cout << "visiting char literal" << endl;
        return nullptr;
    }

    llvm::Value* visit(ASTExprVariable &node)       

    llvm::Value* visit(ASTExpr1DArrayElement &node)
    llvm::Value* visit(ASTExpr2DArrayElement &node)

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

    llvm::Value* visit(ASTExprTernaryOp &node)

    virtual ~CodegenVisitor() {};

}