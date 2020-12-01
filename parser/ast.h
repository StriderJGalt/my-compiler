#include <string>
#include <vector>
#include <map>
#include <stack>
#include <set>

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/raw_ostream.h"


using namespace std;

enum type {B, C, I, U};
enum UnaryOP{NOT, Increment, Decrement};
enum BinaryOP{Multiply, Divide, Remainder, Add, Subtract, GreaterThan, LessThan, GreaterThanOrEqualTo, LessThanOrEqualTo, EqualTo, NotEqualTo, AND, OR};
enum t {VAR, ARRAY1D, ARRAY2D};

struct vardetails {
    t vartype;
    type datatype;
};

struct fndetails{
    type returntype;
    map<string, vardetails> local_variables;
};

class ASTProg;

class ASTStatement;
class ASTStatementCompound;
class ASTStatementVariableDeclaration;
class ASTStatementArrayDeclaration;
class ASTStatementVariableAssignment;
class ASTStatement1DArrayElementAssignment;
class ASTStatement2DArrayElementAssignment;
class ASTStatementFunctionDeclaration;
class ASTStatementFunctionDeclarationArgument;
class ASTStatementFunctionDeclarationArgumentVariable;
class ASTStatementFunctionDeclarationArgumentArray1D;
class ASTStatementFunctionDeclarationArgumentArray2D;
class ASTStatementIfElse;
class ASTStatementForLoop;
class ASTStatementWhileLoop;
class ASTStatementReturn;

class ASTExpr;
class ASTExprFunctionCall;
class ASTExprStringLiteral;
class ASTExprIntegerLiteral;
class ASTExprCharLiteral;
class ASTExprVariable;
class ASTExpr1DArrayElement;
class ASTExpr2DArrayElement;
class ASTExprUnaryOp;
class ASTExprBinaryOp;
class ASTExprTernaryOp;

class ASTvisitor
{
public:
    virtual llvm::Value* visit(ASTProg &node) = 0;
    virtual llvm::Value* visit(ASTStatementCompound &node) = 0;   
    virtual llvm::Value* visit(ASTStatementVariableDeclaration &node) = 0;
    virtual llvm::Value* visit(ASTStatementArrayDeclaration &node) = 0;
    virtual llvm::Value* visit(ASTStatementVariableAssignment &node) = 0;
    virtual llvm::Value* visit(ASTStatement1DArrayElementAssignment &node) = 0;
    virtual llvm::Value* visit(ASTStatement2DArrayElementAssignment &node) = 0;
    virtual llvm::Value* visit(ASTStatementFunctionDeclaration &node) = 0;
    virtual llvm::Value* visit(ASTStatementFunctionDeclarationArgumentVariable &node) = 0;
    virtual llvm::Value* visit(ASTStatementFunctionDeclarationArgumentArray1D &node) = 0;
    virtual llvm::Value* visit(ASTStatementFunctionDeclarationArgumentArray2D &node) = 0;
    virtual llvm::Value* visit(ASTStatementIfElse &node) = 0;
    virtual llvm::Value* visit(ASTStatementForLoop &node) = 0;
    virtual llvm::Value* visit(ASTStatementWhileLoop &node) = 0;
    virtual llvm::Value* visit(ASTStatementReturn &node) = 0;
    virtual llvm::Value* visit(ASTExprFunctionCall &node) = 0;
    virtual llvm::Value* visit(ASTExprStringLiteral &node) = 0;
    virtual llvm::Value* visit(ASTExprIntegerLiteral &node) = 0;
    virtual llvm::Value* visit(ASTExprCharLiteral &node) = 0;
    virtual llvm::Value* visit(ASTExprVariable &node) = 0;
    virtual llvm::Value* visit(ASTExpr1DArrayElement &node) = 0;
    virtual llvm::Value* visit(ASTExpr2DArrayElement &node) = 0;
    virtual llvm::Value* visit(ASTExprUnaryOp &node) = 0;
    virtual llvm::Value* visit(ASTExprBinaryOp &node) = 0;
    virtual llvm::Value* visit(ASTExprTernaryOp &node) = 0;
};

class ASTnode
{
public:
    virtual ~ASTnode()
    {
    }
};

class ASTStatement : public ASTnode
{
public:
    virtual ~ASTStatement()
    {
    }
};

class ASTProg : public ASTnode
{
public:

    vector<ASTStatement *> statements;

    map<string, vardetails> global_variables;
    map<string, fndetails> global_fns;

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTExpr : public ASTnode
{
public:
};


class ASTExprStringLiteral : public ASTExpr
{
    string value;

public:
    
    ASTExprStringLiteral(string val) : value(val) {};
    
    string getValue() {
        return value;
    }
    
    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTExprCharLiteral : public ASTExpr
{
    char value;

public:
    
    ASTExprCharLiteral(char val) : value(val) {};
    
    char getValue() {
        return value;
    }
    
    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTExprIntegerLiteral : public ASTExpr
{
    int value;

public:
    
    ASTExprIntegerLiteral(int val) : value(val) {};
    
    int getValue() {
        return value;
    }
    
    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTExprVariable : public ASTExpr
{
    string name;

public:

    ASTExprVariable(string val) : name(val) {};

    string getId() {
        return name;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTExpr1DArrayElement : public ASTExpr
{
    string name;
    ASTExpr *index;

public:

    ASTExpr1DArrayElement(string arrname, ASTExpr *index) : name(arrname), index(index) {};

    string getId() {
        return name;
    }

    ASTExpr *getIndex() {
        return index;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTExpr2DArrayElement : public ASTExpr
{
    string name;
    ASTExpr *rindex;
    ASTExpr *cindex;

public:

    ASTExpr2DArrayElement(string arrname, ASTExpr *rindex, ASTExpr *cindex) : name(arrname), rindex(rindex), cindex(cindex) {};

    string getId() {
        return name;
    }

    ASTExpr *getRindex() {
        return rindex;
    }

    ASTExpr *getCindex() {
        return cindex;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTExprUnaryOp : public ASTExpr
{
    UnaryOP o;
    ASTExpr *e;

public:

    ASTExprUnaryOp(UnaryOP o, ASTExpr *expr) : o(o), e(expr) {}

    UnaryOP getOperator()
    {
        return o;
    }

    ASTExpr *getExpr()
    {
        return e;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTExprBinaryOp : public ASTExpr
{
    BinaryOP bin_operator;
    ASTExpr *left;
    ASTExpr *right;

public:

    ASTExprBinaryOp(BinaryOP op, ASTExpr *_left, ASTExpr *_right) : bin_operator(op), left(_left), right(_right) {}

    ASTExpr *getLeft()
    {
        return left;
    }

    ASTExpr *getRight()
    {
        return right;
    }

    BinaryOP getOperator()
    {
        return bin_operator;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTExprTernaryOp : public ASTExpr
{

    ASTExpr *first;
    ASTExpr *second;
    ASTExpr *third;

public:

    ASTExprTernaryOp(ASTExpr *first, ASTExpr *second, ASTExpr *third) : first(first), second(second), third(third) {}

    ASTExpr *getFirst()
    {
        return first;
    }

    ASTExpr *getSecond()
    {
        return second;
    }

    ASTExpr *getThird()
    {
        return third;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTExprFunctionCall : public ASTExpr
{
    string name;

public:

    vector<ASTExpr *> arguments;

    ASTExprFunctionCall(string name) : name(name) {};

    string getId()
    {
        return name;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }

};

class ASTStatementCompound : public ASTStatement
{
public:

    vector<ASTStatement *> statements;

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTStatementVariableDeclaration : public ASTStatement
{
    type datatype;
    string name;
    ASTExpr *expr;

public:

    ASTStatementVariableDeclaration(type t, string name, ASTExpr *expr) : datatype(t), name(name), expr(expr) {}

    type getType()
    {
        return datatype;
    }

    string getId()
    {
        return name;
    }

    ASTExpr *getExpr()
    {
        return expr;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }

};


class ASTStatementArrayDeclaration : public ASTStatement
{
    type datatype;
    string name;
    int nr;
    int nc;

public:

    ASTStatementArrayDeclaration(type t, string name, int nr, int nc=1) : datatype(t), name(name), nr(nr), nc(nc) {}

    type getType()
    {
        return datatype;
    }

    string getId()
    {
        return name;
    }

    int getNumberofrows()
    {
        return nr;
    }

    int getNumberofcolumns()
    {
        return nc;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }

};

class ASTStatementVariableAssignment : public ASTStatement
{
    string name;
    ASTExpr *expr;

public:

    ASTStatementVariableAssignment(string name, ASTExpr *expr) : name(name), expr(expr) {}

    string getId()
    {
        return name;
    }

    ASTExpr *getExpr()
    {
        return expr;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTStatement1DArrayElementAssignment : public ASTStatement
{
    string arname;
    ASTExpr *index;
    ASTExpr *expr;

public:

    ASTStatement1DArrayElementAssignment(string arname, ASTExpr *index, ASTExpr *expr) : arname(arname), index(index), expr(expr) {}

    string getId()
    {
        return arname;
    }

    ASTExpr *getIndex()
    {
        return index;
    }

    ASTExpr *getExpr()
    {
        return expr;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }

};

class ASTStatement2DArrayElementAssignment : public ASTStatement
{
    string name;
    ASTExpr *rindex;
    ASTExpr *cindex;
    ASTExpr *expr;

public:

    ASTStatement2DArrayElementAssignment(string name, ASTExpr *rindex, ASTExpr *cindex, ASTExpr *expr) : name(name), rindex(rindex), cindex(cindex), expr(expr) {}

    string getId()
    {
        return name;
    }

    ASTExpr * getRindex()
    {
        return rindex;
    }

    ASTExpr * getCindex()
    {
        return cindex;
    }

    ASTExpr *getExpr()
    {
        return expr;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }

};

class ASTStatementFunctionDeclarationArgument : ASTStatement
{
public:
    virtual ~ASTStatementFunctionDeclarationArgument()
    {
    }
};

class ASTStatementFunctionDeclarationArgumentVariable : ASTStatementFunctionDeclarationArgument
{
    type datatype;
    string name;

public:

    ASTStatementFunctionDeclarationArgumentVariable(type t, string name) : datatype(t), name(name) {}

    type getType()
    {
        return datatype;
    }

    string getId()
    {
        return name;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTStatementFunctionDeclarationArgumentArray1D : ASTStatementFunctionDeclarationArgument
{
    type datatype;
    string name;

public:

    ASTStatementFunctionDeclarationArgumentArray1D(type t, string name) : datatype(t), name(name) {}

    type getDType()
    {
        return datatype;
    }

    string getId()
    {
        return name;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTStatementFunctionDeclarationArgumentArray2D : ASTStatementFunctionDeclarationArgument
{
    type datatype;
    string name;
    int nc;

public:

    ASTStatementFunctionDeclarationArgumentArray2D(type t, string name, int nc=1) : datatype(t), name(name), nc(nc) {}

    type getType()
    {
        return datatype;
    }

    string getId()
    {
        return name;
    }

    int getNumberofcolumns()
    {
        return nc;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTStatementFunctionDeclaration : public ASTStatement
{
    type returntype;
    string name;
    ASTStatement *statement;

public:

    vector<ASTStatementFunctionDeclarationArgument *> arguments;

    ASTStatementFunctionDeclaration(type rt, string name, ASTStatement *s, vector<ASTStatementFunctionDeclarationArgument *> args) : returntype(rt), name(name), statement(s), arguments(args) {};

    type getType()
    {
        return returntype;
    }

    string getId()
    {
        return name;
    }

    ASTStatement *getStatement()
    {
        return statement;
    }


    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }

};

class ASTStatementIfElse : ASTStatement 
{
    ASTExpr *condexpr;

public:

    ASTStatement *ifStatement;
    ASTStatement *elseStatement;

    ASTStatementIfElse(ASTExpr *cond, ASTStatement *ifStatement, ASTStatement *elseStatement = nullptr) : condexpr(cond), ifStatement(ifStatement), elseStatement(elseStatement) {}

    ASTExpr *getExpr()
    {
        return condexpr;
    }

    ASTStatement *getIfstatement()
    {
        return ifStatement;
    }

    ASTStatement *getElsestatement()
    {
        return elseStatement;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTStatementForLoop : ASTStatement
{
    ASTStatement *init;
    ASTExpr *cond;
    ASTStatement *inc;
    ASTStatement *statement;

public:


    ASTStatementForLoop(ASTStatement *init, ASTExpr *cond, ASTStatement *inc, ASTStatement *stat) : init(init), cond(cond), inc(inc), statement(stat) {}

    ASTStatement *getIteratordeclaration()
    {
        return init;
    }

    ASTExpr *getExpr()
    {
        return cond;
    }

    ASTStatement *getIteratorincrementation()
    {
        return inc;
    }

    ASTStatement *getStatement()
    {
        return statement;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTStatementWhileLoop : ASTStatement
{
    ASTExpr *cond;
    ASTStatement *statement;

public:

    ASTStatementWhileLoop(ASTExpr *cond, ASTStatement *stat) : cond(cond), statement(stat) {}

    ASTExpr *getExpr()
    {
        return cond;
    }

    ASTStatement *getStatement()
    {
        return statement;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};

class ASTStatementReturn : ASTStatement
{
    ASTExpr *returnval;

public:

    ASTStatementReturn(ASTExpr *expr) : returnval(expr) {}

    ASTExpr *getExpr()
    {
        return returnval;
    }

    llvm::Value* accept(ASTvisitor &v)
    {
        return v.visit(*this);
    }
};


class ASTContext
{
public:
    ASTnode *root;

    ~ASTContext()
    {
        clearAST();
    }

    /// free all saved expression trees
    void clearAST()
    {
        delete root;
    }
};
