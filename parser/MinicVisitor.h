
// Generated from Minic.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "MinicParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MinicParser.
 */
class  MinicVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MinicParser.
   */
    virtual antlrcpp::Any visitProg(MinicParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitFunc_decl(MinicParser::Func_declContext *context) = 0;

    virtual antlrcpp::Any visitFunc_call(MinicParser::Func_callContext *context) = 0;

    virtual antlrcpp::Any visitDecl_argSimple(MinicParser::Decl_argSimpleContext *context) = 0;

    virtual antlrcpp::Any visitDecl_argArray1D(MinicParser::Decl_argArray1DContext *context) = 0;

    virtual antlrcpp::Any visitDecl_argArray2D(MinicParser::Decl_argArray2DContext *context) = 0;

    virtual antlrcpp::Any visitArgString(MinicParser::ArgStringContext *context) = 0;

    virtual antlrcpp::Any visitArgExpr(MinicParser::ArgExprContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(MinicParser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitStatementAssignment(MinicParser::StatementAssignmentContext *context) = 0;

    virtual antlrcpp::Any visitStatementDeclaration(MinicParser::StatementDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitStatementIf(MinicParser::StatementIfContext *context) = 0;

    virtual antlrcpp::Any visitStatementIfElse(MinicParser::StatementIfElseContext *context) = 0;

    virtual antlrcpp::Any visitStatementFor(MinicParser::StatementForContext *context) = 0;

    virtual antlrcpp::Any visitStatementWhile(MinicParser::StatementWhileContext *context) = 0;

    virtual antlrcpp::Any visitStatementRet(MinicParser::StatementRetContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentSimple(MinicParser::AssignmentSimpleContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentArrayElement1d(MinicParser::AssignmentArrayElement1dContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentArrayElement2d(MinicParser::AssignmentArrayElement2dContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationSimple(MinicParser::DeclarationSimpleContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationArray1D(MinicParser::DeclarationArray1DContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationArray2D(MinicParser::DeclarationArray2DContext *context) = 0;

    virtual antlrcpp::Any visitExprInt(MinicParser::ExprIntContext *context) = 0;

    virtual antlrcpp::Any visitExprMulDivMod(MinicParser::ExprMulDivModContext *context) = 0;

    virtual antlrcpp::Any visitExprNot(MinicParser::ExprNotContext *context) = 0;

    virtual antlrcpp::Any visitExprAddSub(MinicParser::ExprAddSubContext *context) = 0;

    virtual antlrcpp::Any visitExprVar(MinicParser::ExprVarContext *context) = 0;

    virtual antlrcpp::Any visitExprChar(MinicParser::ExprCharContext *context) = 0;

    virtual antlrcpp::Any visitExprFuncCall(MinicParser::ExprFuncCallContext *context) = 0;

    virtual antlrcpp::Any visitExprOr(MinicParser::ExprOrContext *context) = 0;

    virtual antlrcpp::Any visitExprGreaterLesser(MinicParser::ExprGreaterLesserContext *context) = 0;

    virtual antlrcpp::Any visitExpr2DArrayElement(MinicParser::Expr2DArrayElementContext *context) = 0;

    virtual antlrcpp::Any visitExprAnd(MinicParser::ExprAndContext *context) = 0;

    virtual antlrcpp::Any visitExprTernary(MinicParser::ExprTernaryContext *context) = 0;

    virtual antlrcpp::Any visitExprParenthesis(MinicParser::ExprParenthesisContext *context) = 0;

    virtual antlrcpp::Any visitExprEqualNotEqual(MinicParser::ExprEqualNotEqualContext *context) = 0;

    virtual antlrcpp::Any visitExpr1DArrayElement(MinicParser::Expr1DArrayElementContext *context) = 0;


};

