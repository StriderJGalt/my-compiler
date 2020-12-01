
// Generated from Minic.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "MinicVisitor.h"


/**
 * This class provides an empty implementation of MinicVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MinicBaseVisitor : public MinicVisitor {
public:

  virtual antlrcpp::Any visitProg(MinicParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunc_decl(MinicParser::Func_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunc_call(MinicParser::Func_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl_argSimple(MinicParser::Decl_argSimpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl_argArray1D(MinicParser::Decl_argArray1DContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecl_argArray2D(MinicParser::Decl_argArray2DContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgString(MinicParser::ArgStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgExpr(MinicParser::ArgExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompoundStatement(MinicParser::CompoundStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementAssignment(MinicParser::StatementAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementDeclaration(MinicParser::StatementDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementIf(MinicParser::StatementIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementIfElse(MinicParser::StatementIfElseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementFor(MinicParser::StatementForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementWhile(MinicParser::StatementWhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementRet(MinicParser::StatementRetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentSimple(MinicParser::AssignmentSimpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentArrayElement1d(MinicParser::AssignmentArrayElement1dContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentArrayElement2d(MinicParser::AssignmentArrayElement2dContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationSimple(MinicParser::DeclarationSimpleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationArray1D(MinicParser::DeclarationArray1DContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationArray2D(MinicParser::DeclarationArray2DContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprInt(MinicParser::ExprIntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprMulDivMod(MinicParser::ExprMulDivModContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprNot(MinicParser::ExprNotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprAddSub(MinicParser::ExprAddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprVar(MinicParser::ExprVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprChar(MinicParser::ExprCharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprFuncCall(MinicParser::ExprFuncCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprOr(MinicParser::ExprOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprGreaterLesser(MinicParser::ExprGreaterLesserContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr2DArrayElement(MinicParser::Expr2DArrayElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprAnd(MinicParser::ExprAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprTernary(MinicParser::ExprTernaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprParenthesis(MinicParser::ExprParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprEqualNotEqual(MinicParser::ExprEqualNotEqualContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr1DArrayElement(MinicParser::Expr1DArrayElementContext *ctx) override {
    return visitChildren(ctx);
  }


};

