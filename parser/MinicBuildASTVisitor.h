#include <iostream>
#include "ast.h"
#include <vector>
#include "MinicVisitor.h"

using namespace std;

class MinicBuildASTVisitor : public MinicVisitor
{
    bool infunc;
    bool print_visitfn_name = true;
    //bool print_visitfn_name = false;
    map<string, vardetails> global_variables;
    map<string, fndetails> global_fns;
    map<string, vardetails> current_local_scope;
    type type_of_last_eval_expr;

public:
    virtual antlrcpp::Any visitExprInt(MinicParser::ExprIntContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExprInt" << endl;
        ASTExprIntegerLiteral *node = new ASTExprIntegerLiteral( stoi(context->INT()->getText()) );

        // set type_of_last_eval_expr
        type_of_last_eval_expr = I;

        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprChar(MinicParser::ExprCharContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExprChar" << endl;
        string c = context->CHAR()->getText();
        ASTExprCharLiteral *node = new ASTExprCharLiteral(c[0]);

        // set type_of_last_eval_expr
        type_of_last_eval_expr = C;

        return (ASTExpr *) node;
    }

   virtual antlrcpp::Any visitExprVar(MinicParser::ExprVarContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExprVar" << endl;
        string id = context->ID()->getText();

        ASTExprVariable *node = new ASTExprVariable(id);

        // checking if var is declared
        if(!current_local_scope.count(id) && !global_variables.count(id))
        {
            cout << "Error: Variable "<< id <<" not declared" << endl;
        }
        if(current_local_scope.count(id) && global_variables.count(id))
        {
            cout << "Warning: Local variable " << id << "  overrides global variable" << endl;
        }

        // set type_of_last_eval_expr
        if(current_local_scope.count(id))
        {
            type_of_last_eval_expr = current_local_scope[id].datatype;
        }
        else if(global_variables.count(id))
        {
            type_of_last_eval_expr = global_variables[id].datatype;
        }

        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExpr2DArrayElement(MinicParser::Expr2DArrayElementContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExpr2DArrayElement" << endl;
        string id = context->ID()->getText();
        ASTExpr *rindex = visit(context->expr(0));
        ASTExpr *cindex = visit(context->expr(1));

        ASTExpr2DArrayElement *node = new ASTExpr2DArrayElement(id,rindex,cindex);

        // checking if var declared
        if(!current_local_scope.count(id) && !global_variables.count(id))
        {
            cout << "Error: Variable " << id << " not declared" << endl;
        }
        if(current_local_scope.count(id) && global_variables.count(id))
        {
            cout << "Warning: Local variable " << id << "  overrides global variable" << endl;
        }

        // set type_of_last_eval_expr
        if(current_local_scope.count(id))
        {
            type_of_last_eval_expr = current_local_scope[id].datatype;
        }
        else if(global_variables.count(id))
        {
            type_of_last_eval_expr = global_variables[id].datatype;
        }

        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExpr1DArrayElement(MinicParser::Expr1DArrayElementContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExpr1DArrayElement" << endl;
        string id;
        ASTExpr *rindex = visit(context->expr());

        ASTExpr1DArrayElement *node;

        id = context->ID()->getText();

        node = new ASTExpr1DArrayElement(id,rindex);

        // checking if var declared
        if(!current_local_scope.count(id) && !global_variables.count(id))
        {
            cout << "Error: Variable " << id << " not declared" << endl;
        }
        if(current_local_scope.count(id) && global_variables.count(id))
        {
            cout << "Warning: Local variable " << id << "  overrides global variable" << endl;
        }

        // set type_of_last_eval_expr
        if(current_local_scope.count(id))
        {
            type_of_last_eval_expr = current_local_scope[id].datatype;
        }
        else if(global_variables.count(id))
        {
            type_of_last_eval_expr = global_variables[id].datatype;
        }

        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprParenthesis(MinicParser::ExprParenthesisContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExprParenthesis" << endl;
        return visit(context->expr());
    }

    virtual antlrcpp::Any visitExprMulDivMod(MinicParser::ExprMulDivModContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExprMulDivMod" << endl;
        ASTExpr *left = visit(context->expr(0));
        type tleft = type_of_last_eval_expr;
        ASTExpr *right = visit(context->expr(1));
        type tright = type_of_last_eval_expr;
        
        ASTExprBinaryOp *node;

        string opstring = context->op->getText();

        if (opstring[0] == '*')
            node = new ASTExprBinaryOp(Multiply, left, right);

        if (opstring[0] == '/')
            node = new ASTExprBinaryOp(Divide, left, right);

        if (opstring[0] == '%')
            node = new ASTExprBinaryOp(Remainder, left, right);

        // type analysis
        if ( ((tleft == I) || (tleft == U)) && ((tright == I) || (tright == U)) )
        {
            if((tleft == I) && (tright == I))
            {
                type_of_last_eval_expr = I;
            }
            else
            {
                type_of_last_eval_expr = U;
            }
        }
        else
        {
            cout << "Error: Invalid Type In visitExprMulDivMod" << endl;
            type_of_last_eval_expr = I;
        }

        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprAddSub(MinicParser::ExprAddSubContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExprAddSub" << endl;

        ASTExpr *left = visit(context->expr(0));
        type tleft = type_of_last_eval_expr;
        ASTExpr *right = visit(context->expr(1));;
        type tright = type_of_last_eval_expr;        

        ASTExprBinaryOp *node;

        string opstring = context->op->getText();

        if (opstring[0] == '+')
            node = new ASTExprBinaryOp(Add, left, right);

        if (opstring[0] == '-')
            node = new ASTExprBinaryOp(Subtract, left, right);

        // type analysis
        if (((tleft == I) || (tleft == U)) && ((tright == I) || (tright == U)))
        {
            
            if((tleft == I) && (tright == I))
            {
                type_of_last_eval_expr = I;
            }
            else
            {
                type_of_last_eval_expr = U;
            }
        }
        else
        {
            cout << "Error: Invalid Type In visitExprAddSub" << endl;
            type_of_last_eval_expr = I;
        }

        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprGreaterLesser(MinicParser::ExprGreaterLesserContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExprGreaterLesser" << endl;

        ASTExpr *left = visit(context->expr(0));
        type tleft = type_of_last_eval_expr;
        ASTExpr *right = visit(context->expr(1));;
        type tright = type_of_last_eval_expr; 
       
        ASTExprBinaryOp *node;

        string opstring = context->op->getText();

        if (opstring[0] == '>')
        {
            if (opstring.length() == 1)
            node = new ASTExprBinaryOp(GreaterThan, left, right);
            else
            node = new ASTExprBinaryOp(GreaterThanOrEqualTo, left, right);
        }
        if (opstring[0] == '<')
        {
            if (opstring.length() == 1)
            node = new ASTExprBinaryOp(LessThan, left, right);
            else
            node = new ASTExprBinaryOp(LessThanOrEqualTo, left, right);
        }

        // type analysis
        if (!(((tleft == I) || (tleft == U)) && ((tright == I) || (tright == U))))
        {
            
            if((tleft == C) && (tright == C))
            {
                ;
            }
            else
            {
                cout << "Error: Invalid Type In Greater or Lesser Expression" << endl;
            }
        }
        type_of_last_eval_expr = B;

        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprEqualNotEqual(MinicParser::ExprEqualNotEqualContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExprEqualNotEqual" << endl;
        ASTExpr *left = visit(context->expr(0));
        type tleft = type_of_last_eval_expr;
        ASTExpr *right = visit(context->expr(1));;
        type tright = type_of_last_eval_expr; 
       
        ASTExprBinaryOp *node;

        string opstring = context->op->getText();

        if (opstring[0] == '=')
            node = new ASTExprBinaryOp(EqualTo, left, right);

        if (opstring[0] == '!')
            node = new ASTExprBinaryOp(NotEqualTo, left, right);

        // type analysis
        if (!(((tleft == I) || (tleft == U)) && ((tright == I) || (tright == U))))
        {
            
            if((tleft == C) && (tright == C))
            {
                ;
            }
            else
            {
                cout << "Error: Invalid Type In Equal or Notequal Expression" << endl;
            }
        }
        type_of_last_eval_expr = B;

        return (ASTExpr *) node;
    }   

    virtual antlrcpp::Any visitExprAnd(MinicParser::ExprAndContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExprAnd" << endl;
        
        ASTExpr *left = visit(context->expr(0));
        type tleft = type_of_last_eval_expr;
        ASTExpr *right = visit(context->expr(1));;
        type tright = type_of_last_eval_expr; 
       
        ASTExprBinaryOp *node;

        node = new ASTExprBinaryOp(AND, left, right);

        // Type Analysis
        if(!((tleft == B) && (tright == B)))
        {
            cout << "Error: Invalid Type In AND Expression" << endl;
        }
        type_of_last_eval_expr = B;
        
        return (ASTExpr *) node;
    }  

    virtual antlrcpp::Any visitExprOr(MinicParser::ExprOrContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExprOr" << endl;

        ASTExpr *left = visit(context->expr(0));
        type tleft = type_of_last_eval_expr;
        ASTExpr *right = visit(context->expr(1));;
        type tright = type_of_last_eval_expr; 
       
        ASTExprBinaryOp *node;

        node = new ASTExprBinaryOp(OR, left, right);

        // Type Analysis
        if(!((tleft == B) && (tright == B)))
        {
            cout << "Error: Invalid Type In OR Expression" << endl;
        }
        type_of_last_eval_expr = B;

        return (ASTExpr *) node;
    } 

    virtual antlrcpp::Any visitExprTernary(MinicParser::ExprTernaryContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExprTernary" << endl;
        ASTExpr *first;
        ASTExpr *second;
        ASTExpr *third;
       
        ASTExprTernaryOp *node;

        first = visit(context->expr(0));
        second = visit(context->expr(1));
        third = visit(context->expr(2));

        node = new ASTExprTernaryOp(first, second, third);

        return (ASTExpr *) node;
    } 

    virtual antlrcpp::Any visitExprNot(MinicParser::ExprNotContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExprNot" << endl;
        ASTExpr *expr;

        ASTExprUnaryOp *node;

        expr = visit(context->expr());

        node = new ASTExprUnaryOp(NOT, expr);

        // Type Analysis
        if(type_of_last_eval_expr != B)
        {
            cout << "Error: Invalid type in Not Expression" <<endl;
        }
        type_of_last_eval_expr = B;

        return (ASTExpr *) node;

    }

    virtual antlrcpp::Any visitExprFuncCall(MinicParser::ExprFuncCallContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitExprFuncCall" << endl;

        return visit(context->func_call());
    }

    virtual antlrcpp::Any visitFunc_call(MinicParser::Func_callContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitFuncCall" << endl;
        string fname;
        fname = context->ID()->getText();

        // cant do this as will show error on recursion
        
        // // checking if fn is declared
        // if(!global_fns.count(fname))
        // {
        //     if(fname != "scan" && fname != "print")
        //     cout << "Error: Function "<< fname <<" not declared before" << endl;
        // }

        ASTExprFunctionCall *node = new ASTExprFunctionCall(fname);

        ASTExpr *argumentNode;
        for(auto a : context->arg())
        {
            argumentNode = visit(a);
            if (argumentNode != nullptr)
            {
                node->arguments.push_back(argumentNode);
            }
        }

        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitProg(MinicParser::ProgContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitProg" << endl;

        infunc = false;
        current_local_scope.clear();

        ASTProg *node = new ASTProg();
        ASTStatement *statementNode;
        
        for (auto statement : context->declaration())
        {
            statementNode = visit(statement);
            if (statementNode != nullptr)
            {
                node->statements.push_back(statementNode);
            }
        }

        for (auto statement : context->assignment())
        {
            statementNode = visit(statement);
            if (statementNode != nullptr)
            {
                node->statements.push_back(statementNode);
            }
        }

        for (auto statement : context->func_decl())
        {
            statementNode = visit(statement);
            if (statementNode != nullptr)
            {
                node->statements.push_back(statementNode);
            }
        }

        node->global_variables = global_variables;
        node->global_fns = global_fns;

        return (ASTProg *) node;
    }

    virtual antlrcpp::Any visitFunc_decl(MinicParser::Func_declContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitFuncDecl" << endl;

        infunc = true;

        string rts = context->TYPE()->getText();
        type rt;
        switch (rts[0])
        {
            case 'B': rt = B;
                    break;
            case 'C': rt = C;
                    break;
            case 'I': rt = I;
                    break;
            case 'U': rt = U;
                    break;
        }
        
        string fname = context->ID()->getText();

        vector<ASTStatementFunctionDeclarationArgument *> arguments;
        ASTStatementFunctionDeclarationArgument *argNode;
        for (auto arg : context->decl_arg())
        {
            argNode = visit(arg);
            if (argNode != nullptr)
            {
                arguments.push_back(argNode);
            }
        }

        ASTStatement *statement = visit(context->statement());

        ASTStatementFunctionDeclaration * node = new ASTStatementFunctionDeclaration(rt, fname, statement, arguments);

        //add fn details to flobal_fns
        fndetails fd;
        fd.returntype = rt;
        fd.local_variables = current_local_scope;
        
        if(!current_local_scope.empty())
        {
            cout << "vars in scope of fn " << fname << ": ";
            for (auto elem : current_local_scope)
            {
                cout << elem.first << " ";
            }
            cout << endl;
        }
        
        global_fns.insert(pair<string, fndetails>(fname,fd));

        current_local_scope.clear();

        infunc = false;

        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitDecl_argSimple(MinicParser::Decl_argSimpleContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitDecl_argSimple" << endl;

        string rts = context->TYPE()->getText();
        type rt;
        if (rts[0] == 'B')
        {
            rt = B;
        }
        if (rts[0] == 'C')
        {
            rt = C;
        }
        if (rts[0] == 'I')
        {
            rt = I;
        }
        if (rts[0] == 'U')
        {
            rt = U;
        }
        string id = context->ID()->getText();

        ASTStatementFunctionDeclarationArgumentVariable *node = new ASTStatementFunctionDeclarationArgumentVariable(rt,id);

        //adding var to current_local_scope 
        if(current_local_scope.count(id))
        {
            cout << "Error : variable "<< id << " already declared in current scope" << endl;
        }
        else 
        {
          vardetails vd;
          vd.vartype = VAR;
          vd.datatype = rt;
          current_local_scope.insert(pair<string,vardetails>(id,vd));
        }

        return (ASTStatementFunctionDeclarationArgument *) node;
    }

    virtual antlrcpp::Any visitDecl_argArray1D(MinicParser::Decl_argArray1DContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitDecl_argArray1D" << endl;

        string rts = context->TYPE()->getText();
        type rt;
        if (rts[0] == 'B')
        {
            rt = B;
        }
        if (rts[0] == 'C')
        {
            rt = C;
        }
        if (rts[0] == 'I')
        {
            rt = I;
        }
        if (rts[0] == 'U')
        {
            rt = U;
        }
        string id = context->ID()->getText();

        ASTStatementFunctionDeclarationArgumentArray1D *node = new ASTStatementFunctionDeclarationArgumentArray1D(rt,id);
        
        //adding var to current_local_scope 
        if(current_local_scope.count(id))
        {
            cout << "Error : variable "<< id << " already declared in current scope" << endl;
        }
        else 
        {
          vardetails vd;
          vd.vartype = ARRAY1D;
          vd.datatype = rt;
          current_local_scope.insert(pair<string,vardetails>(id,vd));
        }

        return (ASTStatementFunctionDeclarationArgument *) node;
    }

    virtual antlrcpp::Any visitDecl_argArray2D(MinicParser::Decl_argArray2DContext *context) 
    {
        if (print_visitfn_name) 
            cout << "In visitDecl_argArray2D" << endl;
        string rts = context->TYPE()->getText();
        type rt;
        if (rts[0] == 'B')
        {
            rt = B;
        }
        if (rts[0] == 'C')
        {
            rt = C;
        }
        if (rts[0] == 'I')
        {
            rt = I;
        }
        if (rts[0] == 'U')
        {
            rt = U;
        }
        string id = context->ID()->getText();
        int nc = stoi(context->INT()->getText());

        ASTStatementFunctionDeclarationArgumentArray2D *node = new ASTStatementFunctionDeclarationArgumentArray2D(rt,id,nc);

        //adding var to current_local_scope 
        if(current_local_scope.count(id))
        {
            cout << "Error : variable "<< id << " already declared in current scope" << endl;
        }
        else 
        {
          vardetails vd;
          vd.vartype = ARRAY2D;
          vd.datatype = rt;
          current_local_scope.insert(pair<string,vardetails>(id,vd));
        }

        return (ASTStatementFunctionDeclarationArgument *) node;
    }

    virtual antlrcpp::Any visitArgString(MinicParser::ArgStringContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitArgString" << endl;
        string val = context->STRING()->getText();

        ASTExprStringLiteral *node = new ASTExprStringLiteral(val);

        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitArgExpr(MinicParser::ArgExprContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitArgExpr" << endl;
        
        return visit(context->expr());
    }


    // virtual antlrcpp::Any visitStatementFuncCall(MinicParser::StatementFuncCallContext *context)
    // {
    //     if (print_visitfn_name) 
    //       cout << "In visitStatementFuncCall" << endl;

    //     return visit(context->func_call()); 
    // }

    virtual antlrcpp::Any visitStatementIf(MinicParser::StatementIfContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitStatementIf" << endl;
        ASTExpr *cond = visit(context->expr());
        ASTStatement *ifs = visit(context->statement());

        ASTStatementIfElse *node = new ASTStatementIfElse(cond, ifs);
        
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitStatementIfElse(MinicParser::StatementIfElseContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitStatementIfElse" << endl;
        ASTExpr *cond = visit(context->expr());
        ASTStatement *ifs = visit(context->statement(0));
        ASTStatement *elses = visit(context->statement(1));

        ASTStatementIfElse *node = new ASTStatementIfElse(cond, ifs, elses);
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitStatementFor(MinicParser::StatementForContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitStatementFor" << endl;
        ASTStatement *init = visit(context->declaration());
        ASTExpr *cond = visit(context->expr());
        ASTStatement *inc = visit(context->assignment());
        ASTStatement *stat = visit(context->statement());

        ASTStatementForLoop *node = new ASTStatementForLoop(init, cond, inc, stat);

        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitStatementWhile(MinicParser::StatementWhileContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitStatementWhile" << endl;
        ASTExpr *cond = visit(context->expr());
        ASTStatement *stat = visit(context->statement());

        ASTStatementWhileLoop *node = new ASTStatementWhileLoop(cond, stat);

        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitStatementRet(MinicParser::StatementRetContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitStatementRet" << endl;
        ASTExpr *ret = visit(context->expr());

        ASTStatementReturn *node = new ASTStatementReturn(ret);
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitCompoundStatement(MinicParser::CompoundStatementContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitCompoundStatement" << endl;

        ASTStatementCompound *node = new ASTStatementCompound();
        ASTStatement *statementNode;
        for (auto statement : context->statement())
        {
            statementNode = visit(statement);
            if (statementNode != nullptr)
            {
                node->statements.push_back(statementNode);
            }
        }
        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitStatementAssignment(MinicParser::StatementAssignmentContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitStatementAssignment" << endl;

        return visit(context->assignment());
    }

    virtual antlrcpp::Any visitAssignmentSimple(MinicParser::AssignmentSimpleContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitAssignmentSimple" << endl;
        string id = context->ID()->getText();
        ASTExpr *ret = visit(context->expr());

        ASTStatementVariableAssignment *node = new ASTStatementVariableAssignment(id,ret);

        // checking if var is declared
        if(!current_local_scope.count(id) && !global_variables.count(id))
        {
            cout << "Error: Variable " << id << "  not declared" << endl;
        }
        if(current_local_scope.count(id) && global_variables.count(id))
        {
            cout << "Warning: Local variable " << id << "  overrides global variable" << endl;
        }

        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitAssignmentArrayElement1d(MinicParser::AssignmentArrayElement1dContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitAssignmentArrayElement1D" << endl;
        string id = context->ID()->getText();
        ASTExpr *index = visit(context->expr(0));
        ASTExpr *ret = visit(context->expr(1));

        ASTStatement1DArrayElementAssignment *node = new ASTStatement1DArrayElementAssignment(id,index,ret);

        // checking if var is declared
        if(!current_local_scope.count(id) && !global_variables.count(id))
        {
            cout << "Error: Variable " << id << "  not declared" << endl;
        }
        if(current_local_scope.count(id) && global_variables.count(id))
        {
            cout << "Warning: Local variable " << id << "  overrides global variable" << endl;
        }

        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitAssignmentArrayElement2d(MinicParser::AssignmentArrayElement2dContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitAssignmentArrayElement2D" << endl;
        string id = context->ID()->getText();
        ASTExpr *rindex = visit(context->expr(0));
        ASTExpr *cindex = visit(context->expr(1));
        ASTExpr *ret = visit(context->expr(2));

        ASTStatement2DArrayElementAssignment *node = new ASTStatement2DArrayElementAssignment(id, rindex, cindex, ret);

        // checking if var is declared
        if(!current_local_scope.count(id) && !global_variables.count(id))
        {
            cout << "Error: Variable " << id << "  not declared" << endl;
        }
        if(current_local_scope.count(id) && global_variables.count(id))
        {
            cout << "Warning: Local variable " << id << "  overrides global variable" << endl;
        }

        return (ASTStatement *) node;
    }


    virtual antlrcpp::Any visitStatementDeclaration(MinicParser::StatementDeclarationContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitStatementDeclaration" << endl;

        return visit(context->declaration());
    }

    virtual antlrcpp::Any visitDeclarationSimple(MinicParser::DeclarationSimpleContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitDeclarationSimple" << endl;
        string rts = context->TYPE()->getText();
        type rt;
        if (rts[0] == 'B')
        {
            rt = B;
        }
        if (rts[0] == 'C')
        {
            rt = C;
        }
        if (rts[0] == 'I')
        {
            rt = I;
        }
        if (rts[0] == 'U')
        {
            rt = U;
        }
        string id = context->ID()->getText();
        ASTExpr *val = visit(context->expr());

        ASTStatementVariableDeclaration *node = new ASTStatementVariableDeclaration(rt,id,val);

        if(infunc)
        {
            //adding var to current_local_scope 
            if(current_local_scope.count(id))
            {
                cout << "Error : variable "<< id <<" already declared in current scope" << endl;
            }
            else 
            {
                vardetails vd;
                vd.vartype = VAR;
                vd.datatype = rt;
                current_local_scope.insert(pair<string,vardetails>(id,vd));
            }
        }
        else
        {
            // adding var to global_vars
            vardetails vd;
            vd.vartype = VAR;
            vd.datatype = rt;
            global_variables.insert(pair<string,vardetails>(id,vd));
        }
        

        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitDeclarationArray1D(MinicParser::DeclarationArray1DContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitDeclarationArray1D" << endl;
        string rts = context->TYPE()->getText();
        type rt;
        if (rts[0] == 'B')
        {
            rt = B;
        }
        if (rts[0] == 'C')
        {
            rt = C;
        }
        if (rts[0] == 'I')
        {
            rt = I;
        }
        if (rts[0] == 'U')
        {
            rt = U;
        }
        string id = context->ID()->getText();
        int nr = stoi(context->INT()->getText());

        ASTStatementArrayDeclaration *node = new ASTStatementArrayDeclaration(rt,id,nr);

        if(infunc)
        {
            //adding var to current_local_scope 
            if(current_local_scope.count(id))
            {
                cout << "Error : variable "<< id << " already declared in current scope" << endl;
            }
            else 
            {
                vardetails vd;
                vd.vartype = ARRAY1D;
                vd.datatype = rt;
                current_local_scope.insert(pair<string,vardetails>(id,vd));
            }
        }
        else
        {
            // adding var to global_vars
            if(global_variables.count(id))
            {
                cout << "Error : variable "<< id << " already declared in current scope" << endl;
            }
            else
            {
                vardetails vd;
                vd.vartype = ARRAY1D;
                vd.datatype = rt;
                global_variables.insert(pair<string,vardetails>(id,vd));
            }
        }

        return (ASTStatement *) node;
    }

    virtual antlrcpp::Any visitDeclarationArray2D(MinicParser::DeclarationArray2DContext *context)
    {
        if (print_visitfn_name) 
            cout << "In visitDeclarationArray2D" << endl;
        string rts = context->TYPE()->getText();
        type rt;
        if (rts[0] == 'B')
        {
            rt = B;
        }
        if (rts[0] == 'C')
        {
            rt = C;
        }
        if (rts[0] == 'I')
        {
            rt = I;
        }
        if (rts[0] == 'U')
        {
            rt = U;
        }
        string id = context->ID()->getText();
        int nr = stoi(context->INT(0)->getText());
        int nc = stoi(context->INT(1)->getText());

        ASTStatementArrayDeclaration *node = new ASTStatementArrayDeclaration(rt,id,nr,nc);

        if(infunc)
        {
            //adding var to current_local_scope 
            if(current_local_scope.count(id))
            {
                cout << "Error : variable "<< id << " already declared in current scope" << endl;
            }
            else 
            {
                vardetails vd;
                vd.vartype = ARRAY2D;
                vd.datatype = rt;
                current_local_scope.insert(pair<string,vardetails>(id,vd));
            }
        }
        else
        {
            // adding var to global_vars
            if(global_variables.count(id))
            {
                cout << "Error : variable "<< id << " already declared in current scope" << endl;
            }
            else
            {
                vardetails vd;
                vd.vartype = ARRAY2D;
                vd.datatype = rt;
                global_variables.insert(pair<string,vardetails>(id,vd));
            }
        }

        return (ASTStatement *) node;
    }


};
