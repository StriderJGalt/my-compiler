
// Generated from Minic.g4 by ANTLR 4.8


#include "MinicVisitor.h"

#include "MinicParser.h"


using namespace antlrcpp;
using namespace antlr4;

MinicParser::MinicParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

MinicParser::~MinicParser() {
  delete _interpreter;
}

std::string MinicParser::getGrammarFileName() const {
  return "Minic.g4";
}

const std::vector<std::string>& MinicParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& MinicParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

MinicParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MinicParser::ProgContext::EOF() {
  return getToken(MinicParser::EOF, 0);
}

std::vector<MinicParser::DeclarationContext *> MinicParser::ProgContext::declaration() {
  return getRuleContexts<MinicParser::DeclarationContext>();
}

MinicParser::DeclarationContext* MinicParser::ProgContext::declaration(size_t i) {
  return getRuleContext<MinicParser::DeclarationContext>(i);
}

std::vector<MinicParser::AssignmentContext *> MinicParser::ProgContext::assignment() {
  return getRuleContexts<MinicParser::AssignmentContext>();
}

MinicParser::AssignmentContext* MinicParser::ProgContext::assignment(size_t i) {
  return getRuleContext<MinicParser::AssignmentContext>(i);
}

std::vector<MinicParser::Func_declContext *> MinicParser::ProgContext::func_decl() {
  return getRuleContexts<MinicParser::Func_declContext>();
}

MinicParser::Func_declContext* MinicParser::ProgContext::func_decl(size_t i) {
  return getRuleContext<MinicParser::Func_declContext>(i);
}


size_t MinicParser::ProgContext::getRuleIndex() const {
  return MinicParser::RuleProg;
}


antlrcpp::Any MinicParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

MinicParser::ProgContext* MinicParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, MinicParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(21);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(18);
        declaration();
        break;
      }

      case 2: {
        setState(19);
        assignment();
        break;
      }

      case 3: {
        setState(20);
        func_decl();
        break;
      }

      }
      setState(23); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == MinicParser::ID

    || _la == MinicParser::TYPE);
    setState(25);
    match(MinicParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declContext ------------------------------------------------------------------

MinicParser::Func_declContext::Func_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MinicParser::Func_declContext::TYPE() {
  return getToken(MinicParser::TYPE, 0);
}

tree::TerminalNode* MinicParser::Func_declContext::ID() {
  return getToken(MinicParser::ID, 0);
}

MinicParser::StatementContext* MinicParser::Func_declContext::statement() {
  return getRuleContext<MinicParser::StatementContext>(0);
}

std::vector<MinicParser::Decl_argContext *> MinicParser::Func_declContext::decl_arg() {
  return getRuleContexts<MinicParser::Decl_argContext>();
}

MinicParser::Decl_argContext* MinicParser::Func_declContext::decl_arg(size_t i) {
  return getRuleContext<MinicParser::Decl_argContext>(i);
}


size_t MinicParser::Func_declContext::getRuleIndex() const {
  return MinicParser::RuleFunc_decl;
}


antlrcpp::Any MinicParser::Func_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitFunc_decl(this);
  else
    return visitor->visitChildren(this);
}

MinicParser::Func_declContext* MinicParser::func_decl() {
  Func_declContext *_localctx = _tracker.createInstance<Func_declContext>(_ctx, getState());
  enterRule(_localctx, 2, MinicParser::RuleFunc_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(27);
    match(MinicParser::TYPE);
    setState(28);
    match(MinicParser::ID);
    setState(29);
    match(MinicParser::T__0);
    setState(35);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(30);
        decl_arg();
        setState(31);
        match(MinicParser::T__1); 
      }
      setState(37);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(39);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MinicParser::TYPE) {
      setState(38);
      decl_arg();
    }
    setState(41);
    match(MinicParser::T__2);
    setState(42);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_callContext ------------------------------------------------------------------

MinicParser::Func_callContext::Func_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MinicParser::Func_callContext::ID() {
  return getToken(MinicParser::ID, 0);
}

std::vector<MinicParser::ArgContext *> MinicParser::Func_callContext::arg() {
  return getRuleContexts<MinicParser::ArgContext>();
}

MinicParser::ArgContext* MinicParser::Func_callContext::arg(size_t i) {
  return getRuleContext<MinicParser::ArgContext>(i);
}


size_t MinicParser::Func_callContext::getRuleIndex() const {
  return MinicParser::RuleFunc_call;
}


antlrcpp::Any MinicParser::Func_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitFunc_call(this);
  else
    return visitor->visitChildren(this);
}

MinicParser::Func_callContext* MinicParser::func_call() {
  Func_callContext *_localctx = _tracker.createInstance<Func_callContext>(_ctx, getState());
  enterRule(_localctx, 4, MinicParser::RuleFunc_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(44);
    match(MinicParser::ID);
    setState(45);
    match(MinicParser::T__0);
    setState(51);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(46);
        arg();
        setState(47);
        match(MinicParser::T__1); 
      }
      setState(53);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(55);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << MinicParser::T__0)
      | (1ULL << MinicParser::T__17)
      | (1ULL << MinicParser::ID)
      | (1ULL << MinicParser::CHAR)
      | (1ULL << MinicParser::INT)
      | (1ULL << MinicParser::STRING))) != 0)) {
      setState(54);
      arg();
    }
    setState(57);
    match(MinicParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Decl_argContext ------------------------------------------------------------------

MinicParser::Decl_argContext::Decl_argContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MinicParser::Decl_argContext::getRuleIndex() const {
  return MinicParser::RuleDecl_arg;
}

void MinicParser::Decl_argContext::copyFrom(Decl_argContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Decl_argArray1DContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::Decl_argArray1DContext::TYPE() {
  return getToken(MinicParser::TYPE, 0);
}

tree::TerminalNode* MinicParser::Decl_argArray1DContext::ID() {
  return getToken(MinicParser::ID, 0);
}

MinicParser::Decl_argArray1DContext::Decl_argArray1DContext(Decl_argContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::Decl_argArray1DContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitDecl_argArray1D(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Decl_argArray2DContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::Decl_argArray2DContext::TYPE() {
  return getToken(MinicParser::TYPE, 0);
}

tree::TerminalNode* MinicParser::Decl_argArray2DContext::ID() {
  return getToken(MinicParser::ID, 0);
}

tree::TerminalNode* MinicParser::Decl_argArray2DContext::INT() {
  return getToken(MinicParser::INT, 0);
}

MinicParser::Decl_argArray2DContext::Decl_argArray2DContext(Decl_argContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::Decl_argArray2DContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitDecl_argArray2D(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Decl_argSimpleContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::Decl_argSimpleContext::TYPE() {
  return getToken(MinicParser::TYPE, 0);
}

tree::TerminalNode* MinicParser::Decl_argSimpleContext::ID() {
  return getToken(MinicParser::ID, 0);
}

MinicParser::Decl_argSimpleContext::Decl_argSimpleContext(Decl_argContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::Decl_argSimpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitDecl_argSimple(this);
  else
    return visitor->visitChildren(this);
}
MinicParser::Decl_argContext* MinicParser::decl_arg() {
  Decl_argContext *_localctx = _tracker.createInstance<Decl_argContext>(_ctx, getState());
  enterRule(_localctx, 6, MinicParser::RuleDecl_arg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(69);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Decl_argContext *>(_tracker.createInstance<MinicParser::Decl_argSimpleContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(59);
      match(MinicParser::TYPE);
      setState(60);
      match(MinicParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Decl_argContext *>(_tracker.createInstance<MinicParser::Decl_argArray1DContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(61);
      match(MinicParser::TYPE);
      setState(62);
      match(MinicParser::ID);
      setState(63);
      match(MinicParser::T__3);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<Decl_argContext *>(_tracker.createInstance<MinicParser::Decl_argArray2DContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(64);
      match(MinicParser::TYPE);
      setState(65);
      match(MinicParser::ID);
      setState(66);
      match(MinicParser::T__4);
      setState(67);
      match(MinicParser::INT);
      setState(68);
      match(MinicParser::T__5);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgContext ------------------------------------------------------------------

MinicParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MinicParser::ArgContext::getRuleIndex() const {
  return MinicParser::RuleArg;
}

void MinicParser::ArgContext::copyFrom(ArgContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArgStringContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::ArgStringContext::STRING() {
  return getToken(MinicParser::STRING, 0);
}

MinicParser::ArgStringContext::ArgStringContext(ArgContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ArgStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitArgString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArgExprContext ------------------------------------------------------------------

MinicParser::ExprContext* MinicParser::ArgExprContext::expr() {
  return getRuleContext<MinicParser::ExprContext>(0);
}

MinicParser::ArgExprContext::ArgExprContext(ArgContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ArgExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitArgExpr(this);
  else
    return visitor->visitChildren(this);
}
MinicParser::ArgContext* MinicParser::arg() {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState());
  enterRule(_localctx, 8, MinicParser::RuleArg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MinicParser::STRING: {
        _localctx = dynamic_cast<ArgContext *>(_tracker.createInstance<MinicParser::ArgStringContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(71);
        match(MinicParser::STRING);
        break;
      }

      case MinicParser::T__0:
      case MinicParser::T__17:
      case MinicParser::ID:
      case MinicParser::CHAR:
      case MinicParser::INT: {
        _localctx = dynamic_cast<ArgContext *>(_tracker.createInstance<MinicParser::ArgExprContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(72);
        expr(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

MinicParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MinicParser::StatementContext::getRuleIndex() const {
  return MinicParser::RuleStatement;
}

void MinicParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StatementAssignmentContext ------------------------------------------------------------------

MinicParser::AssignmentContext* MinicParser::StatementAssignmentContext::assignment() {
  return getRuleContext<MinicParser::AssignmentContext>(0);
}

MinicParser::StatementAssignmentContext::StatementAssignmentContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::StatementAssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitStatementAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementForContext ------------------------------------------------------------------

MinicParser::DeclarationContext* MinicParser::StatementForContext::declaration() {
  return getRuleContext<MinicParser::DeclarationContext>(0);
}

MinicParser::ExprContext* MinicParser::StatementForContext::expr() {
  return getRuleContext<MinicParser::ExprContext>(0);
}

MinicParser::AssignmentContext* MinicParser::StatementForContext::assignment() {
  return getRuleContext<MinicParser::AssignmentContext>(0);
}

MinicParser::StatementContext* MinicParser::StatementForContext::statement() {
  return getRuleContext<MinicParser::StatementContext>(0);
}

MinicParser::StatementForContext::StatementForContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::StatementForContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitStatementFor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementDeclarationContext ------------------------------------------------------------------

MinicParser::DeclarationContext* MinicParser::StatementDeclarationContext::declaration() {
  return getRuleContext<MinicParser::DeclarationContext>(0);
}

MinicParser::StatementDeclarationContext::StatementDeclarationContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::StatementDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitStatementDeclaration(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompoundStatementContext ------------------------------------------------------------------

std::vector<MinicParser::StatementContext *> MinicParser::CompoundStatementContext::statement() {
  return getRuleContexts<MinicParser::StatementContext>();
}

MinicParser::StatementContext* MinicParser::CompoundStatementContext::statement(size_t i) {
  return getRuleContext<MinicParser::StatementContext>(i);
}

MinicParser::CompoundStatementContext::CompoundStatementContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementIfElseContext ------------------------------------------------------------------

MinicParser::ExprContext* MinicParser::StatementIfElseContext::expr() {
  return getRuleContext<MinicParser::ExprContext>(0);
}

std::vector<MinicParser::StatementContext *> MinicParser::StatementIfElseContext::statement() {
  return getRuleContexts<MinicParser::StatementContext>();
}

MinicParser::StatementContext* MinicParser::StatementIfElseContext::statement(size_t i) {
  return getRuleContext<MinicParser::StatementContext>(i);
}

MinicParser::StatementIfElseContext::StatementIfElseContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::StatementIfElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitStatementIfElse(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementWhileContext ------------------------------------------------------------------

MinicParser::ExprContext* MinicParser::StatementWhileContext::expr() {
  return getRuleContext<MinicParser::ExprContext>(0);
}

MinicParser::StatementContext* MinicParser::StatementWhileContext::statement() {
  return getRuleContext<MinicParser::StatementContext>(0);
}

MinicParser::StatementWhileContext::StatementWhileContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::StatementWhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitStatementWhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementRetContext ------------------------------------------------------------------

MinicParser::ExprContext* MinicParser::StatementRetContext::expr() {
  return getRuleContext<MinicParser::ExprContext>(0);
}

MinicParser::StatementRetContext::StatementRetContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::StatementRetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitStatementRet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementIfContext ------------------------------------------------------------------

MinicParser::ExprContext* MinicParser::StatementIfContext::expr() {
  return getRuleContext<MinicParser::ExprContext>(0);
}

MinicParser::StatementContext* MinicParser::StatementIfContext::statement() {
  return getRuleContext<MinicParser::StatementContext>(0);
}

MinicParser::StatementIfContext::StatementIfContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::StatementIfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitStatementIf(this);
  else
    return visitor->visitChildren(this);
}
MinicParser::StatementContext* MinicParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 10, MinicParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(118);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MinicParser::CompoundStatementContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(75);
      match(MinicParser::T__6);
      setState(77); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(76);
        statement();
        setState(79); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << MinicParser::T__6)
        | (1ULL << MinicParser::T__8)
        | (1ULL << MinicParser::T__10)
        | (1ULL << MinicParser::T__12)
        | (1ULL << MinicParser::T__13)
        | (1ULL << MinicParser::ID)
        | (1ULL << MinicParser::TYPE))) != 0));
      setState(81);
      match(MinicParser::T__7);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MinicParser::StatementAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(83);
      assignment();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MinicParser::StatementDeclarationContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(84);
      declaration();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MinicParser::StatementIfContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(85);
      match(MinicParser::T__8);
      setState(86);
      match(MinicParser::T__0);
      setState(87);
      expr(0);
      setState(88);
      match(MinicParser::T__2);
      setState(89);
      statement();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MinicParser::StatementIfElseContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(91);
      match(MinicParser::T__8);
      setState(92);
      match(MinicParser::T__0);
      setState(93);
      expr(0);
      setState(94);
      match(MinicParser::T__2);
      setState(95);
      statement();
      setState(96);
      match(MinicParser::T__9);
      setState(97);
      statement();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MinicParser::StatementForContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(99);
      match(MinicParser::T__10);
      setState(100);
      match(MinicParser::T__0);
      setState(101);
      declaration();
      setState(102);
      expr(0);
      setState(103);
      match(MinicParser::T__11);
      setState(104);
      assignment();
      setState(105);
      match(MinicParser::T__2);
      setState(106);
      statement();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MinicParser::StatementWhileContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(108);
      match(MinicParser::T__12);
      setState(109);
      match(MinicParser::T__0);
      setState(110);
      expr(0);
      setState(111);
      match(MinicParser::T__2);
      setState(112);
      statement();
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<MinicParser::StatementRetContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(114);
      match(MinicParser::T__13);
      setState(115);
      expr(0);
      setState(116);
      match(MinicParser::T__11);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

MinicParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MinicParser::AssignmentContext::getRuleIndex() const {
  return MinicParser::RuleAssignment;
}

void MinicParser::AssignmentContext::copyFrom(AssignmentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AssignmentSimpleContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::AssignmentSimpleContext::ID() {
  return getToken(MinicParser::ID, 0);
}

MinicParser::ExprContext* MinicParser::AssignmentSimpleContext::expr() {
  return getRuleContext<MinicParser::ExprContext>(0);
}

MinicParser::AssignmentSimpleContext::AssignmentSimpleContext(AssignmentContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::AssignmentSimpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitAssignmentSimple(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentArrayElement1dContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::AssignmentArrayElement1dContext::ID() {
  return getToken(MinicParser::ID, 0);
}

std::vector<MinicParser::ExprContext *> MinicParser::AssignmentArrayElement1dContext::expr() {
  return getRuleContexts<MinicParser::ExprContext>();
}

MinicParser::ExprContext* MinicParser::AssignmentArrayElement1dContext::expr(size_t i) {
  return getRuleContext<MinicParser::ExprContext>(i);
}

MinicParser::AssignmentArrayElement1dContext::AssignmentArrayElement1dContext(AssignmentContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::AssignmentArrayElement1dContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitAssignmentArrayElement1d(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentArrayElement2dContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::AssignmentArrayElement2dContext::ID() {
  return getToken(MinicParser::ID, 0);
}

std::vector<MinicParser::ExprContext *> MinicParser::AssignmentArrayElement2dContext::expr() {
  return getRuleContexts<MinicParser::ExprContext>();
}

MinicParser::ExprContext* MinicParser::AssignmentArrayElement2dContext::expr(size_t i) {
  return getRuleContext<MinicParser::ExprContext>(i);
}

MinicParser::AssignmentArrayElement2dContext::AssignmentArrayElement2dContext(AssignmentContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::AssignmentArrayElement2dContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitAssignmentArrayElement2d(this);
  else
    return visitor->visitChildren(this);
}
MinicParser::AssignmentContext* MinicParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 12, MinicParser::RuleAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(143);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<AssignmentContext *>(_tracker.createInstance<MinicParser::AssignmentSimpleContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(120);
      match(MinicParser::ID);
      setState(121);
      match(MinicParser::T__14);
      setState(122);
      expr(0);
      setState(123);
      match(MinicParser::T__11);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<AssignmentContext *>(_tracker.createInstance<MinicParser::AssignmentArrayElement1dContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(125);
      match(MinicParser::ID);
      setState(126);
      match(MinicParser::T__15);
      setState(127);
      expr(0);
      setState(128);
      match(MinicParser::T__5);
      setState(129);
      match(MinicParser::T__14);
      setState(130);
      expr(0);
      setState(131);
      match(MinicParser::T__11);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<AssignmentContext *>(_tracker.createInstance<MinicParser::AssignmentArrayElement2dContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(133);
      match(MinicParser::ID);
      setState(134);
      match(MinicParser::T__15);
      setState(135);
      expr(0);
      setState(136);
      match(MinicParser::T__16);
      setState(137);
      expr(0);
      setState(138);
      match(MinicParser::T__5);
      setState(139);
      match(MinicParser::T__14);
      setState(140);
      expr(0);
      setState(141);
      match(MinicParser::T__11);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

MinicParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MinicParser::DeclarationContext::getRuleIndex() const {
  return MinicParser::RuleDeclaration;
}

void MinicParser::DeclarationContext::copyFrom(DeclarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DeclarationSimpleContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::DeclarationSimpleContext::TYPE() {
  return getToken(MinicParser::TYPE, 0);
}

tree::TerminalNode* MinicParser::DeclarationSimpleContext::ID() {
  return getToken(MinicParser::ID, 0);
}

MinicParser::ExprContext* MinicParser::DeclarationSimpleContext::expr() {
  return getRuleContext<MinicParser::ExprContext>(0);
}

MinicParser::DeclarationSimpleContext::DeclarationSimpleContext(DeclarationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::DeclarationSimpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitDeclarationSimple(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclarationArray2DContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::DeclarationArray2DContext::TYPE() {
  return getToken(MinicParser::TYPE, 0);
}

tree::TerminalNode* MinicParser::DeclarationArray2DContext::ID() {
  return getToken(MinicParser::ID, 0);
}

std::vector<tree::TerminalNode *> MinicParser::DeclarationArray2DContext::INT() {
  return getTokens(MinicParser::INT);
}

tree::TerminalNode* MinicParser::DeclarationArray2DContext::INT(size_t i) {
  return getToken(MinicParser::INT, i);
}

MinicParser::DeclarationArray2DContext::DeclarationArray2DContext(DeclarationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::DeclarationArray2DContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitDeclarationArray2D(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeclarationArray1DContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::DeclarationArray1DContext::TYPE() {
  return getToken(MinicParser::TYPE, 0);
}

tree::TerminalNode* MinicParser::DeclarationArray1DContext::ID() {
  return getToken(MinicParser::ID, 0);
}

tree::TerminalNode* MinicParser::DeclarationArray1DContext::INT() {
  return getToken(MinicParser::INT, 0);
}

MinicParser::DeclarationArray1DContext::DeclarationArray1DContext(DeclarationContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::DeclarationArray1DContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitDeclarationArray1D(this);
  else
    return visitor->visitChildren(this);
}
MinicParser::DeclarationContext* MinicParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 14, MinicParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(165);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DeclarationContext *>(_tracker.createInstance<MinicParser::DeclarationSimpleContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(145);
      match(MinicParser::TYPE);
      setState(146);
      match(MinicParser::ID);
      setState(147);
      match(MinicParser::T__14);
      setState(148);
      expr(0);
      setState(149);
      match(MinicParser::T__11);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DeclarationContext *>(_tracker.createInstance<MinicParser::DeclarationArray1DContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(151);
      match(MinicParser::TYPE);
      setState(152);
      match(MinicParser::ID);
      setState(153);
      match(MinicParser::T__15);
      setState(154);
      match(MinicParser::INT);
      setState(155);
      match(MinicParser::T__5);
      setState(156);
      match(MinicParser::T__11);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<DeclarationContext *>(_tracker.createInstance<MinicParser::DeclarationArray2DContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(157);
      match(MinicParser::TYPE);
      setState(158);
      match(MinicParser::ID);
      setState(159);
      match(MinicParser::T__15);
      setState(160);
      match(MinicParser::INT);
      setState(161);
      match(MinicParser::T__16);
      setState(162);
      match(MinicParser::INT);
      setState(163);
      match(MinicParser::T__5);
      setState(164);
      match(MinicParser::T__11);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

MinicParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MinicParser::ExprContext::getRuleIndex() const {
  return MinicParser::RuleExpr;
}

void MinicParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprIntContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::ExprIntContext::INT() {
  return getToken(MinicParser::INT, 0);
}

MinicParser::ExprIntContext::ExprIntContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ExprIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExprInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprMulDivModContext ------------------------------------------------------------------

std::vector<MinicParser::ExprContext *> MinicParser::ExprMulDivModContext::expr() {
  return getRuleContexts<MinicParser::ExprContext>();
}

MinicParser::ExprContext* MinicParser::ExprMulDivModContext::expr(size_t i) {
  return getRuleContext<MinicParser::ExprContext>(i);
}

MinicParser::ExprMulDivModContext::ExprMulDivModContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ExprMulDivModContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExprMulDivMod(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprNotContext ------------------------------------------------------------------

MinicParser::ExprContext* MinicParser::ExprNotContext::expr() {
  return getRuleContext<MinicParser::ExprContext>(0);
}

MinicParser::ExprNotContext::ExprNotContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ExprNotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExprNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAddSubContext ------------------------------------------------------------------

std::vector<MinicParser::ExprContext *> MinicParser::ExprAddSubContext::expr() {
  return getRuleContexts<MinicParser::ExprContext>();
}

MinicParser::ExprContext* MinicParser::ExprAddSubContext::expr(size_t i) {
  return getRuleContext<MinicParser::ExprContext>(i);
}

MinicParser::ExprAddSubContext::ExprAddSubContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ExprAddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExprAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprVarContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::ExprVarContext::ID() {
  return getToken(MinicParser::ID, 0);
}

MinicParser::ExprVarContext::ExprVarContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ExprVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExprVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprCharContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::ExprCharContext::CHAR() {
  return getToken(MinicParser::CHAR, 0);
}

MinicParser::ExprCharContext::ExprCharContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ExprCharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExprChar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprFuncCallContext ------------------------------------------------------------------

MinicParser::Func_callContext* MinicParser::ExprFuncCallContext::func_call() {
  return getRuleContext<MinicParser::Func_callContext>(0);
}

MinicParser::ExprFuncCallContext::ExprFuncCallContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ExprFuncCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExprFuncCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprOrContext ------------------------------------------------------------------

std::vector<MinicParser::ExprContext *> MinicParser::ExprOrContext::expr() {
  return getRuleContexts<MinicParser::ExprContext>();
}

MinicParser::ExprContext* MinicParser::ExprOrContext::expr(size_t i) {
  return getRuleContext<MinicParser::ExprContext>(i);
}

MinicParser::ExprOrContext::ExprOrContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ExprOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExprOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprGreaterLesserContext ------------------------------------------------------------------

std::vector<MinicParser::ExprContext *> MinicParser::ExprGreaterLesserContext::expr() {
  return getRuleContexts<MinicParser::ExprContext>();
}

MinicParser::ExprContext* MinicParser::ExprGreaterLesserContext::expr(size_t i) {
  return getRuleContext<MinicParser::ExprContext>(i);
}

MinicParser::ExprGreaterLesserContext::ExprGreaterLesserContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ExprGreaterLesserContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExprGreaterLesser(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr2DArrayElementContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::Expr2DArrayElementContext::ID() {
  return getToken(MinicParser::ID, 0);
}

std::vector<MinicParser::ExprContext *> MinicParser::Expr2DArrayElementContext::expr() {
  return getRuleContexts<MinicParser::ExprContext>();
}

MinicParser::ExprContext* MinicParser::Expr2DArrayElementContext::expr(size_t i) {
  return getRuleContext<MinicParser::ExprContext>(i);
}

MinicParser::Expr2DArrayElementContext::Expr2DArrayElementContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::Expr2DArrayElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExpr2DArrayElement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAndContext ------------------------------------------------------------------

std::vector<MinicParser::ExprContext *> MinicParser::ExprAndContext::expr() {
  return getRuleContexts<MinicParser::ExprContext>();
}

MinicParser::ExprContext* MinicParser::ExprAndContext::expr(size_t i) {
  return getRuleContext<MinicParser::ExprContext>(i);
}

MinicParser::ExprAndContext::ExprAndContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ExprAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExprAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprTernaryContext ------------------------------------------------------------------

std::vector<MinicParser::ExprContext *> MinicParser::ExprTernaryContext::expr() {
  return getRuleContexts<MinicParser::ExprContext>();
}

MinicParser::ExprContext* MinicParser::ExprTernaryContext::expr(size_t i) {
  return getRuleContext<MinicParser::ExprContext>(i);
}

MinicParser::ExprTernaryContext::ExprTernaryContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ExprTernaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExprTernary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParenthesisContext ------------------------------------------------------------------

MinicParser::ExprContext* MinicParser::ExprParenthesisContext::expr() {
  return getRuleContext<MinicParser::ExprContext>(0);
}

MinicParser::ExprParenthesisContext::ExprParenthesisContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ExprParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExprParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprEqualNotEqualContext ------------------------------------------------------------------

std::vector<MinicParser::ExprContext *> MinicParser::ExprEqualNotEqualContext::expr() {
  return getRuleContexts<MinicParser::ExprContext>();
}

MinicParser::ExprContext* MinicParser::ExprEqualNotEqualContext::expr(size_t i) {
  return getRuleContext<MinicParser::ExprContext>(i);
}

MinicParser::ExprEqualNotEqualContext::ExprEqualNotEqualContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::ExprEqualNotEqualContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExprEqualNotEqual(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr1DArrayElementContext ------------------------------------------------------------------

tree::TerminalNode* MinicParser::Expr1DArrayElementContext::ID() {
  return getToken(MinicParser::ID, 0);
}

MinicParser::ExprContext* MinicParser::Expr1DArrayElementContext::expr() {
  return getRuleContext<MinicParser::ExprContext>(0);
}

MinicParser::Expr1DArrayElementContext::Expr1DArrayElementContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any MinicParser::Expr1DArrayElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MinicVisitor*>(visitor))
    return parserVisitor->visitExpr1DArrayElement(this);
  else
    return visitor->visitChildren(this);
}

MinicParser::ExprContext* MinicParser::expr() {
   return expr(0);
}

MinicParser::ExprContext* MinicParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MinicParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  MinicParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 16;
  enterRecursionRule(_localctx, 16, MinicParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(190);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprNotContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(168);
      match(MinicParser::T__17);
      setState(169);
      expr(15);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ExprIntContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(170);
      match(MinicParser::INT);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExprFuncCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(171);
      func_call();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Expr2DArrayElementContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(172);
      match(MinicParser::ID);
      setState(173);
      match(MinicParser::T__15);
      setState(174);
      expr(0);
      setState(175);
      match(MinicParser::T__16);
      setState(176);
      expr(0);
      setState(177);
      match(MinicParser::T__5);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Expr1DArrayElementContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(179);
      match(MinicParser::ID);
      setState(180);
      match(MinicParser::T__15);
      setState(181);
      expr(0);
      setState(182);
      match(MinicParser::T__5);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ExprCharContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(184);
      match(MinicParser::CHAR);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ExprVarContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(185);
      match(MinicParser::ID);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ExprParenthesisContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(186);
      match(MinicParser::T__0);
      setState(187);
      expr(0);
      setState(188);
      match(MinicParser::T__2);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(218);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(216);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprMulDivModContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(192);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(193);
          dynamic_cast<ExprMulDivModContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MinicParser::T__18)
            | (1ULL << MinicParser::T__19)
            | (1ULL << MinicParser::T__20))) != 0))) {
            dynamic_cast<ExprMulDivModContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(194);
          expr(15);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprAddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(195);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(196);
          dynamic_cast<ExprAddSubContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MinicParser::T__21

          || _la == MinicParser::T__22)) {
            dynamic_cast<ExprAddSubContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(197);
          expr(14);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprGreaterLesserContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(198);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(199);
          dynamic_cast<ExprGreaterLesserContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << MinicParser::T__23)
            | (1ULL << MinicParser::T__24)
            | (1ULL << MinicParser::T__25)
            | (1ULL << MinicParser::T__26))) != 0))) {
            dynamic_cast<ExprGreaterLesserContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(200);
          expr(13);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ExprEqualNotEqualContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(201);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(202);
          dynamic_cast<ExprEqualNotEqualContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MinicParser::T__27

          || _la == MinicParser::T__28)) {
            dynamic_cast<ExprEqualNotEqualContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(203);
          expr(12);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<ExprAndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(204);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(205);
          match(MinicParser::T__29);
          setState(206);
          expr(11);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ExprOrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(207);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(208);
          match(MinicParser::T__30);
          setState(209);
          expr(10);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<ExprTernaryContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(210);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(211);
          match(MinicParser::T__31);
          setState(212);
          expr(0);
          setState(213);
          match(MinicParser::T__32);
          setState(214);
          expr(9);
          break;
        }

        } 
      }
      setState(220);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool MinicParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 8: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MinicParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 14);
    case 1: return precpred(_ctx, 13);
    case 2: return precpred(_ctx, 12);
    case 3: return precpred(_ctx, 11);
    case 4: return precpred(_ctx, 10);
    case 5: return precpred(_ctx, 9);
    case 6: return precpred(_ctx, 8);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> MinicParser::_decisionToDFA;
atn::PredictionContextCache MinicParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN MinicParser::_atn;
std::vector<uint16_t> MinicParser::_serializedATN;

std::vector<std::string> MinicParser::_ruleNames = {
  "prog", "func_decl", "func_call", "decl_arg", "arg", "statement", "assignment", 
  "declaration", "expr"
};

std::vector<std::string> MinicParser::_literalNames = {
  "", "'('", "','", "')'", "'[]'", "'[]['", "']'", "'{'", "'}'", "'IF'", 
  "'ELSE'", "'FOR'", "';'", "'WHILE'", "'RET'", "'='", "'['", "']['", "'!'", 
  "'*'", "'/'", "'%'", "'+'", "'-'", "'>'", "'>='", "'<'", "'<='", "'=='", 
  "'!='", "'&'", "'|'", "'?'", "':'"
};

std::vector<std::string> MinicParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ID", 
  "CHAR", "INT", "STRING", "COMMENT", "NS", "TYPE"
};

dfa::Vocabulary MinicParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> MinicParser::_tokenNames;

MinicParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2a, 0xe0, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x6, 0x2, 0x18, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x19, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x7, 0x3, 0x24, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x27, 0xb, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x2a, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x34, 0xa, 0x4, 0xc, 
    0x4, 0xe, 0x4, 0x37, 0xb, 0x4, 0x3, 0x4, 0x5, 0x4, 0x3a, 0xa, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x48, 0xa, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x4c, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x6, 
    0x7, 0x50, 0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 0x51, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 
    0x7, 0x79, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x92, 0xa, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xa8, 
    0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xc1, 0xa, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x7, 0xa, 0xdb, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xde, 0xb, 
    0xa, 0x3, 0xa, 0x2, 0x3, 0x12, 0xb, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x2, 0x6, 0x3, 0x2, 0x15, 0x17, 0x3, 0x2, 0x18, 0x19, 0x3, 
    0x2, 0x1a, 0x1d, 0x3, 0x2, 0x1e, 0x1f, 0x2, 0xfa, 0x2, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x6, 0x2e, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x47, 0x3, 0x2, 0x2, 0x2, 0xa, 0x4b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x78, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x91, 0x3, 0x2, 0x2, 0x2, 0x10, 0xa7, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0xc0, 0x3, 0x2, 0x2, 0x2, 0x14, 0x18, 0x5, 0x10, 
    0x9, 0x2, 0x15, 0x18, 0x5, 0xe, 0x8, 0x2, 0x16, 0x18, 0x5, 0x4, 0x3, 
    0x2, 0x17, 0x14, 0x3, 0x2, 0x2, 0x2, 0x17, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x17, 0x16, 0x3, 0x2, 0x2, 0x2, 0x18, 0x19, 0x3, 0x2, 0x2, 0x2, 0x19, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x7, 0x2, 0x2, 0x3, 0x1c, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0x2a, 0x2, 0x2, 0x1e, 0x1f, 0x7, 0x24, 
    0x2, 0x2, 0x1f, 0x25, 0x7, 0x3, 0x2, 0x2, 0x20, 0x21, 0x5, 0x8, 0x5, 
    0x2, 0x21, 0x22, 0x7, 0x4, 0x2, 0x2, 0x22, 0x24, 0x3, 0x2, 0x2, 0x2, 
    0x23, 0x20, 0x3, 0x2, 0x2, 0x2, 0x24, 0x27, 0x3, 0x2, 0x2, 0x2, 0x25, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x3, 0x2, 0x2, 0x2, 0x26, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2a, 0x5, 
    0x8, 0x5, 0x2, 0x29, 0x28, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0x5, 0x2, 
    0x2, 0x2c, 0x2d, 0x5, 0xc, 0x7, 0x2, 0x2d, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x2e, 0x2f, 0x7, 0x24, 0x2, 0x2, 0x2f, 0x35, 0x7, 0x3, 0x2, 0x2, 0x30, 
    0x31, 0x5, 0xa, 0x6, 0x2, 0x31, 0x32, 0x7, 0x4, 0x2, 0x2, 0x32, 0x34, 
    0x3, 0x2, 0x2, 0x2, 0x33, 0x30, 0x3, 0x2, 0x2, 0x2, 0x34, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0x39, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0x3a, 0x5, 0xa, 0x6, 0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 
    0x39, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3b, 
    0x3c, 0x7, 0x5, 0x2, 0x2, 0x3c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 
    0x7, 0x2a, 0x2, 0x2, 0x3e, 0x48, 0x7, 0x24, 0x2, 0x2, 0x3f, 0x40, 0x7, 
    0x2a, 0x2, 0x2, 0x40, 0x41, 0x7, 0x24, 0x2, 0x2, 0x41, 0x48, 0x7, 0x6, 
    0x2, 0x2, 0x42, 0x43, 0x7, 0x2a, 0x2, 0x2, 0x43, 0x44, 0x7, 0x24, 0x2, 
    0x2, 0x44, 0x45, 0x7, 0x7, 0x2, 0x2, 0x45, 0x46, 0x7, 0x26, 0x2, 0x2, 
    0x46, 0x48, 0x7, 0x8, 0x2, 0x2, 0x47, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x47, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x47, 0x42, 0x3, 0x2, 0x2, 0x2, 0x48, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x49, 0x4c, 0x7, 0x27, 0x2, 0x2, 0x4a, 0x4c, 0x5, 
    0x12, 0xa, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4a, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4f, 0x7, 0x9, 0x2, 
    0x2, 0x4e, 0x50, 0x5, 0xc, 0x7, 0x2, 0x4f, 0x4e, 0x3, 0x2, 0x2, 0x2, 
    0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 
    0x52, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 
    0x7, 0xa, 0x2, 0x2, 0x54, 0x79, 0x3, 0x2, 0x2, 0x2, 0x55, 0x79, 0x5, 
    0xe, 0x8, 0x2, 0x56, 0x79, 0x5, 0x10, 0x9, 0x2, 0x57, 0x58, 0x7, 0xb, 
    0x2, 0x2, 0x58, 0x59, 0x7, 0x3, 0x2, 0x2, 0x59, 0x5a, 0x5, 0x12, 0xa, 
    0x2, 0x5a, 0x5b, 0x7, 0x5, 0x2, 0x2, 0x5b, 0x5c, 0x5, 0xc, 0x7, 0x2, 
    0x5c, 0x79, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0xb, 0x2, 0x2, 0x5e, 
    0x5f, 0x7, 0x3, 0x2, 0x2, 0x5f, 0x60, 0x5, 0x12, 0xa, 0x2, 0x60, 0x61, 
    0x7, 0x5, 0x2, 0x2, 0x61, 0x62, 0x5, 0xc, 0x7, 0x2, 0x62, 0x63, 0x7, 
    0xc, 0x2, 0x2, 0x63, 0x64, 0x5, 0xc, 0x7, 0x2, 0x64, 0x79, 0x3, 0x2, 
    0x2, 0x2, 0x65, 0x66, 0x7, 0xd, 0x2, 0x2, 0x66, 0x67, 0x7, 0x3, 0x2, 
    0x2, 0x67, 0x68, 0x5, 0x10, 0x9, 0x2, 0x68, 0x69, 0x5, 0x12, 0xa, 0x2, 
    0x69, 0x6a, 0x7, 0xe, 0x2, 0x2, 0x6a, 0x6b, 0x5, 0xe, 0x8, 0x2, 0x6b, 
    0x6c, 0x7, 0x5, 0x2, 0x2, 0x6c, 0x6d, 0x5, 0xc, 0x7, 0x2, 0x6d, 0x79, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0xf, 0x2, 0x2, 0x6f, 0x70, 0x7, 
    0x3, 0x2, 0x2, 0x70, 0x71, 0x5, 0x12, 0xa, 0x2, 0x71, 0x72, 0x7, 0x5, 
    0x2, 0x2, 0x72, 0x73, 0x5, 0xc, 0x7, 0x2, 0x73, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x74, 0x75, 0x7, 0x10, 0x2, 0x2, 0x75, 0x76, 0x5, 0x12, 0xa, 0x2, 
    0x76, 0x77, 0x7, 0xe, 0x2, 0x2, 0x77, 0x79, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x78, 0x55, 0x3, 0x2, 0x2, 0x2, 0x78, 0x56, 
    0x3, 0x2, 0x2, 0x2, 0x78, 0x57, 0x3, 0x2, 0x2, 0x2, 0x78, 0x5d, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x65, 0x3, 0x2, 0x2, 0x2, 0x78, 0x6e, 0x3, 0x2, 
    0x2, 0x2, 0x78, 0x74, 0x3, 0x2, 0x2, 0x2, 0x79, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0x7b, 0x7, 0x24, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x11, 0x2, 0x2, 
    0x7c, 0x7d, 0x5, 0x12, 0xa, 0x2, 0x7d, 0x7e, 0x7, 0xe, 0x2, 0x2, 0x7e, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x24, 0x2, 0x2, 0x80, 0x81, 
    0x7, 0x12, 0x2, 0x2, 0x81, 0x82, 0x5, 0x12, 0xa, 0x2, 0x82, 0x83, 0x7, 
    0x8, 0x2, 0x2, 0x83, 0x84, 0x7, 0x11, 0x2, 0x2, 0x84, 0x85, 0x5, 0x12, 
    0xa, 0x2, 0x85, 0x86, 0x7, 0xe, 0x2, 0x2, 0x86, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0x87, 0x88, 0x7, 0x24, 0x2, 0x2, 0x88, 0x89, 0x7, 0x12, 0x2, 0x2, 
    0x89, 0x8a, 0x5, 0x12, 0xa, 0x2, 0x8a, 0x8b, 0x7, 0x13, 0x2, 0x2, 0x8b, 
    0x8c, 0x5, 0x12, 0xa, 0x2, 0x8c, 0x8d, 0x7, 0x8, 0x2, 0x2, 0x8d, 0x8e, 
    0x7, 0x11, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x12, 0xa, 0x2, 0x8f, 0x90, 0x7, 
    0xe, 0x2, 0x2, 0x90, 0x92, 0x3, 0x2, 0x2, 0x2, 0x91, 0x7a, 0x3, 0x2, 
    0x2, 0x2, 0x91, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x87, 0x3, 0x2, 0x2, 
    0x2, 0x92, 0xf, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 0x2a, 0x2, 0x2, 
    0x94, 0x95, 0x7, 0x24, 0x2, 0x2, 0x95, 0x96, 0x7, 0x11, 0x2, 0x2, 0x96, 
    0x97, 0x5, 0x12, 0xa, 0x2, 0x97, 0x98, 0x7, 0xe, 0x2, 0x2, 0x98, 0xa8, 
    0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x7, 0x2a, 0x2, 0x2, 0x9a, 0x9b, 0x7, 
    0x24, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x12, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x26, 
    0x2, 0x2, 0x9d, 0x9e, 0x7, 0x8, 0x2, 0x2, 0x9e, 0xa8, 0x7, 0xe, 0x2, 
    0x2, 0x9f, 0xa0, 0x7, 0x2a, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x24, 0x2, 0x2, 
    0xa1, 0xa2, 0x7, 0x12, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x26, 0x2, 0x2, 0xa3, 
    0xa4, 0x7, 0x13, 0x2, 0x2, 0xa4, 0xa5, 0x7, 0x26, 0x2, 0x2, 0xa5, 0xa6, 
    0x7, 0x8, 0x2, 0x2, 0xa6, 0xa8, 0x7, 0xe, 0x2, 0x2, 0xa7, 0x93, 0x3, 
    0x2, 0x2, 0x2, 0xa7, 0x99, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x9f, 0x3, 0x2, 
    0x2, 0x2, 0xa8, 0x11, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x8, 0xa, 0x1, 
    0x2, 0xaa, 0xab, 0x7, 0x14, 0x2, 0x2, 0xab, 0xc1, 0x5, 0x12, 0xa, 0x11, 
    0xac, 0xc1, 0x7, 0x26, 0x2, 0x2, 0xad, 0xc1, 0x5, 0x6, 0x4, 0x2, 0xae, 
    0xaf, 0x7, 0x24, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x12, 0x2, 0x2, 0xb0, 0xb1, 
    0x5, 0x12, 0xa, 0x2, 0xb1, 0xb2, 0x7, 0x13, 0x2, 0x2, 0xb2, 0xb3, 0x5, 
    0x12, 0xa, 0x2, 0xb3, 0xb4, 0x7, 0x8, 0x2, 0x2, 0xb4, 0xc1, 0x3, 0x2, 
    0x2, 0x2, 0xb5, 0xb6, 0x7, 0x24, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x12, 0x2, 
    0x2, 0xb7, 0xb8, 0x5, 0x12, 0xa, 0x2, 0xb8, 0xb9, 0x7, 0x8, 0x2, 0x2, 
    0xb9, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xba, 0xc1, 0x7, 0x25, 0x2, 0x2, 0xbb, 
    0xc1, 0x7, 0x24, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x3, 0x2, 0x2, 0xbd, 0xbe, 
    0x5, 0x12, 0xa, 0x2, 0xbe, 0xbf, 0x7, 0x5, 0x2, 0x2, 0xbf, 0xc1, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xac, 0x3, 0x2, 
    0x2, 0x2, 0xc0, 0xad, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xae, 0x3, 0x2, 0x2, 
    0x2, 0xc0, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xba, 0x3, 0x2, 0x2, 0x2, 
    0xc0, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xc1, 
    0xdc, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0xc, 0x10, 0x2, 0x2, 0xc3, 0xc4, 
    0x9, 0x2, 0x2, 0x2, 0xc4, 0xdb, 0x5, 0x12, 0xa, 0x11, 0xc5, 0xc6, 0xc, 
    0xf, 0x2, 0x2, 0xc6, 0xc7, 0x9, 0x3, 0x2, 0x2, 0xc7, 0xdb, 0x5, 0x12, 
    0xa, 0x10, 0xc8, 0xc9, 0xc, 0xe, 0x2, 0x2, 0xc9, 0xca, 0x9, 0x4, 0x2, 
    0x2, 0xca, 0xdb, 0x5, 0x12, 0xa, 0xf, 0xcb, 0xcc, 0xc, 0xd, 0x2, 0x2, 
    0xcc, 0xcd, 0x9, 0x5, 0x2, 0x2, 0xcd, 0xdb, 0x5, 0x12, 0xa, 0xe, 0xce, 
    0xcf, 0xc, 0xc, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x20, 0x2, 0x2, 0xd0, 0xdb, 
    0x5, 0x12, 0xa, 0xd, 0xd1, 0xd2, 0xc, 0xb, 0x2, 0x2, 0xd2, 0xd3, 0x7, 
    0x21, 0x2, 0x2, 0xd3, 0xdb, 0x5, 0x12, 0xa, 0xc, 0xd4, 0xd5, 0xc, 0xa, 
    0x2, 0x2, 0xd5, 0xd6, 0x7, 0x22, 0x2, 0x2, 0xd6, 0xd7, 0x5, 0x12, 0xa, 
    0x2, 0xd7, 0xd8, 0x7, 0x23, 0x2, 0x2, 0xd8, 0xd9, 0x5, 0x12, 0xa, 0xb, 
    0xd9, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xda, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xda, 
    0xc5, 0x3, 0x2, 0x2, 0x2, 0xda, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xda, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0xda, 0xce, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd1, 0x3, 
    0x2, 0x2, 0x2, 0xda, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xde, 0x3, 0x2, 
    0x2, 0x2, 0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0xdd, 0x13, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 
    0x11, 0x17, 0x19, 0x25, 0x29, 0x35, 0x39, 0x47, 0x4b, 0x51, 0x78, 0x91, 
    0xa7, 0xc0, 0xda, 0xdc, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

MinicParser::Initializer MinicParser::_init;
