
// Generated from FormulaTree.g4 by ANTLR 4.7.2


#include "FormulaTreeListener.h"

#include "FormulaTreeParser.h"


using namespace antlrcpp;
using namespace antlr4;

FormulaTreeParser::FormulaTreeParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

FormulaTreeParser::~FormulaTreeParser() {
  delete _interpreter;
}

std::string FormulaTreeParser::getGrammarFileName() const {
  return "FormulaTree.g4";
}

const std::vector<std::string>& FormulaTreeParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& FormulaTreeParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- LtlContext ------------------------------------------------------------------

FormulaTreeParser::LtlContext::LtlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FormulaTreeParser::AtomicPropositionContext* FormulaTreeParser::LtlContext::atomicProposition() {
  return getRuleContext<FormulaTreeParser::AtomicPropositionContext>(0);
}

FormulaTreeParser::LtlTContext* FormulaTreeParser::LtlContext::ltlT() {
  return getRuleContext<FormulaTreeParser::LtlTContext>(0);
}

tree::TerminalNode* FormulaTreeParser::LtlContext::GLOBAL() {
  return getToken(FormulaTreeParser::GLOBAL, 0);
}

FormulaTreeParser::LtlContext* FormulaTreeParser::LtlContext::ltl() {
  return getRuleContext<FormulaTreeParser::LtlContext>(0);
}

tree::TerminalNode* FormulaTreeParser::LtlContext::FUTURE() {
  return getToken(FormulaTreeParser::FUTURE, 0);
}

tree::TerminalNode* FormulaTreeParser::LtlContext::NEXT() {
  return getToken(FormulaTreeParser::NEXT, 0);
}

tree::TerminalNode* FormulaTreeParser::LtlContext::NOT() {
  return getToken(FormulaTreeParser::NOT, 0);
}

tree::TerminalNode* FormulaTreeParser::LtlContext::OPEN_PARAN() {
  return getToken(FormulaTreeParser::OPEN_PARAN, 0);
}

tree::TerminalNode* FormulaTreeParser::LtlContext::CLOSE_PARAN() {
  return getToken(FormulaTreeParser::CLOSE_PARAN, 0);
}


size_t FormulaTreeParser::LtlContext::getRuleIndex() const {
  return FormulaTreeParser::RuleLtl;
}

void FormulaTreeParser::LtlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLtl(this);
}

void FormulaTreeParser::LtlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLtl(this);
}

FormulaTreeParser::LtlContext* FormulaTreeParser::ltl() {
  LtlContext *_localctx = _tracker.createInstance<LtlContext>(_ctx, getState());
  enterRule(_localctx, 0, FormulaTreeParser::RuleLtl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      setState(30);
      atomicProposition();
      setState(31);
      ltlT();
      break;
    }

    case 2: {
      setState(33);
      match(FormulaTreeParser::GLOBAL);
      setState(34);
      ltl();
      setState(35);
      ltlT();
      break;
    }

    case 3: {
      setState(37);
      match(FormulaTreeParser::FUTURE);
      setState(38);
      ltl();
      setState(39);
      ltlT();
      break;
    }

    case 4: {
      setState(41);
      match(FormulaTreeParser::NEXT);
      setState(42);
      ltl();
      setState(43);
      ltlT();
      break;
    }

    case 5: {
      setState(45);
      match(FormulaTreeParser::NOT);
      setState(46);
      ltl();
      setState(47);
      ltlT();
      break;
    }

    case 6: {
      setState(49);
      match(FormulaTreeParser::OPEN_PARAN);
      setState(50);
      ltl();
      setState(51);
      match(FormulaTreeParser::CLOSE_PARAN);
      setState(52);
      ltlT();
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

//----------------- LtlTContext ------------------------------------------------------------------

FormulaTreeParser::LtlTContext::LtlTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FormulaTreeParser::LtlTContext::UNTIL() {
  return getToken(FormulaTreeParser::UNTIL, 0);
}

FormulaTreeParser::LtlContext* FormulaTreeParser::LtlTContext::ltl() {
  return getRuleContext<FormulaTreeParser::LtlContext>(0);
}

tree::TerminalNode* FormulaTreeParser::LtlTContext::RELEASE() {
  return getToken(FormulaTreeParser::RELEASE, 0);
}

tree::TerminalNode* FormulaTreeParser::LtlTContext::AND() {
  return getToken(FormulaTreeParser::AND, 0);
}

tree::TerminalNode* FormulaTreeParser::LtlTContext::OR() {
  return getToken(FormulaTreeParser::OR, 0);
}

tree::TerminalNode* FormulaTreeParser::LtlTContext::IMPLIES() {
  return getToken(FormulaTreeParser::IMPLIES, 0);
}

tree::TerminalNode* FormulaTreeParser::LtlTContext::EQUIVALENT() {
  return getToken(FormulaTreeParser::EQUIVALENT, 0);
}


size_t FormulaTreeParser::LtlTContext::getRuleIndex() const {
  return FormulaTreeParser::RuleLtlT;
}

void FormulaTreeParser::LtlTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLtlT(this);
}

void FormulaTreeParser::LtlTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLtlT(this);
}

FormulaTreeParser::LtlTContext* FormulaTreeParser::ltlT() {
  LtlTContext *_localctx = _tracker.createInstance<LtlTContext>(_ctx, getState());
  enterRule(_localctx, 2, FormulaTreeParser::RuleLtlT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(56);
      match(FormulaTreeParser::UNTIL);
      setState(57);
      ltl();
      break;
    }

    case 2: {
      setState(58);
      match(FormulaTreeParser::RELEASE);
      setState(59);
      ltl();
      break;
    }

    case 3: {
      setState(60);
      match(FormulaTreeParser::AND);
      setState(61);
      ltl();
      break;
    }

    case 4: {
      setState(62);
      match(FormulaTreeParser::OR);
      setState(63);
      ltl();
      break;
    }

    case 5: {
      setState(64);
      match(FormulaTreeParser::IMPLIES);
      setState(65);
      ltl();
      break;
    }

    case 6: {
      setState(66);
      match(FormulaTreeParser::EQUIVALENT);
      setState(67);
      ltl();
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

//----------------- AtomicPropositionContext ------------------------------------------------------------------

FormulaTreeParser::AtomicPropositionContext::AtomicPropositionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FormulaTreeParser::RelationalExprContext* FormulaTreeParser::AtomicPropositionContext::relationalExpr() {
  return getRuleContext<FormulaTreeParser::RelationalExprContext>(0);
}


size_t FormulaTreeParser::AtomicPropositionContext::getRuleIndex() const {
  return FormulaTreeParser::RuleAtomicProposition;
}

void FormulaTreeParser::AtomicPropositionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtomicProposition(this);
}

void FormulaTreeParser::AtomicPropositionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtomicProposition(this);
}

FormulaTreeParser::AtomicPropositionContext* FormulaTreeParser::atomicProposition() {
  AtomicPropositionContext *_localctx = _tracker.createInstance<AtomicPropositionContext>(_ctx, getState());
  enterRule(_localctx, 4, FormulaTreeParser::RuleAtomicProposition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    relationalExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationalExprContext ------------------------------------------------------------------

FormulaTreeParser::RelationalExprContext::RelationalExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FormulaTreeParser::LogicalValueContext* FormulaTreeParser::RelationalExprContext::logicalValue() {
  return getRuleContext<FormulaTreeParser::LogicalValueContext>(0);
}

FormulaTreeParser::IdContext* FormulaTreeParser::RelationalExprContext::id() {
  return getRuleContext<FormulaTreeParser::IdContext>(0);
}

std::vector<FormulaTreeParser::ArithmeticExprContext *> FormulaTreeParser::RelationalExprContext::arithmeticExpr() {
  return getRuleContexts<FormulaTreeParser::ArithmeticExprContext>();
}

FormulaTreeParser::ArithmeticExprContext* FormulaTreeParser::RelationalExprContext::arithmeticExpr(size_t i) {
  return getRuleContext<FormulaTreeParser::ArithmeticExprContext>(i);
}

tree::TerminalNode* FormulaTreeParser::RelationalExprContext::LT() {
  return getToken(FormulaTreeParser::LT, 0);
}

tree::TerminalNode* FormulaTreeParser::RelationalExprContext::GT() {
  return getToken(FormulaTreeParser::GT, 0);
}

tree::TerminalNode* FormulaTreeParser::RelationalExprContext::LTE() {
  return getToken(FormulaTreeParser::LTE, 0);
}

tree::TerminalNode* FormulaTreeParser::RelationalExprContext::GTE() {
  return getToken(FormulaTreeParser::GTE, 0);
}

tree::TerminalNode* FormulaTreeParser::RelationalExprContext::EQ() {
  return getToken(FormulaTreeParser::EQ, 0);
}

tree::TerminalNode* FormulaTreeParser::RelationalExprContext::NEQ() {
  return getToken(FormulaTreeParser::NEQ, 0);
}


size_t FormulaTreeParser::RelationalExprContext::getRuleIndex() const {
  return FormulaTreeParser::RuleRelationalExpr;
}

void FormulaTreeParser::RelationalExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpr(this);
}

void FormulaTreeParser::RelationalExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpr(this);
}

FormulaTreeParser::RelationalExprContext* FormulaTreeParser::relationalExpr() {
  RelationalExprContext *_localctx = _tracker.createInstance<RelationalExprContext>(_ctx, getState());
  enterRule(_localctx, 6, FormulaTreeParser::RuleRelationalExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(72);
      logicalValue();
      break;
    }

    case 2: {
      setState(73);
      id();
      break;
    }

    case 3: {
      setState(74);
      arithmeticExpr();
      setState(75);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << FormulaTreeParser::GT)
        | (1ULL << FormulaTreeParser::LT)
        | (1ULL << FormulaTreeParser::GTE)
        | (1ULL << FormulaTreeParser::LTE))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(76);
      arithmeticExpr();
      break;
    }

    case 4: {
      setState(78);
      arithmeticExpr();
      setState(79);
      _la = _input->LA(1);
      if (!(_la == FormulaTreeParser::EQ

      || _la == FormulaTreeParser::NEQ)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(80);
      arithmeticExpr();
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

//----------------- ArithmeticExprContext ------------------------------------------------------------------

FormulaTreeParser::ArithmeticExprContext::ArithmeticExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FormulaTreeParser::ArithValueContext* FormulaTreeParser::ArithmeticExprContext::arithValue() {
  return getRuleContext<FormulaTreeParser::ArithValueContext>(0);
}

FormulaTreeParser::ArithmeticExprTContext* FormulaTreeParser::ArithmeticExprContext::arithmeticExprT() {
  return getRuleContext<FormulaTreeParser::ArithmeticExprTContext>(0);
}

FormulaTreeParser::IdContext* FormulaTreeParser::ArithmeticExprContext::id() {
  return getRuleContext<FormulaTreeParser::IdContext>(0);
}

tree::TerminalNode* FormulaTreeParser::ArithmeticExprContext::OPEN_PARAN() {
  return getToken(FormulaTreeParser::OPEN_PARAN, 0);
}

FormulaTreeParser::ArithmeticExprContext* FormulaTreeParser::ArithmeticExprContext::arithmeticExpr() {
  return getRuleContext<FormulaTreeParser::ArithmeticExprContext>(0);
}

tree::TerminalNode* FormulaTreeParser::ArithmeticExprContext::CLOSE_PARAN() {
  return getToken(FormulaTreeParser::CLOSE_PARAN, 0);
}


size_t FormulaTreeParser::ArithmeticExprContext::getRuleIndex() const {
  return FormulaTreeParser::RuleArithmeticExpr;
}

void FormulaTreeParser::ArithmeticExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmeticExpr(this);
}

void FormulaTreeParser::ArithmeticExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmeticExpr(this);
}

FormulaTreeParser::ArithmeticExprContext* FormulaTreeParser::arithmeticExpr() {
  ArithmeticExprContext *_localctx = _tracker.createInstance<ArithmeticExprContext>(_ctx, getState());
  enterRule(_localctx, 8, FormulaTreeParser::RuleArithmeticExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FormulaTreeParser::PLUS:
      case FormulaTreeParser::MINUS:
      case FormulaTreeParser::DIGIT: {
        setState(84);
        arithValue();
        setState(85);
        arithmeticExprT();
        break;
      }

      case FormulaTreeParser::LOWER_CASE:
      case FormulaTreeParser::UPPER_CASE: {
        setState(87);
        id();
        setState(88);
        arithmeticExprT();
        break;
      }

      case FormulaTreeParser::OPEN_PARAN: {
        setState(90);
        match(FormulaTreeParser::OPEN_PARAN);
        setState(91);
        arithmeticExpr();
        setState(92);
        match(FormulaTreeParser::CLOSE_PARAN);
        setState(93);
        arithmeticExprT();
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

//----------------- ArithmeticExprTContext ------------------------------------------------------------------

FormulaTreeParser::ArithmeticExprTContext::ArithmeticExprTContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FormulaTreeParser::ArithmeticExprTContext::MOD() {
  return getToken(FormulaTreeParser::MOD, 0);
}

FormulaTreeParser::ArithmeticExprContext* FormulaTreeParser::ArithmeticExprTContext::arithmeticExpr() {
  return getRuleContext<FormulaTreeParser::ArithmeticExprContext>(0);
}

tree::TerminalNode* FormulaTreeParser::ArithmeticExprTContext::DIV() {
  return getToken(FormulaTreeParser::DIV, 0);
}

tree::TerminalNode* FormulaTreeParser::ArithmeticExprTContext::MUL() {
  return getToken(FormulaTreeParser::MUL, 0);
}

tree::TerminalNode* FormulaTreeParser::ArithmeticExprTContext::PLUS() {
  return getToken(FormulaTreeParser::PLUS, 0);
}

tree::TerminalNode* FormulaTreeParser::ArithmeticExprTContext::MINUS() {
  return getToken(FormulaTreeParser::MINUS, 0);
}


size_t FormulaTreeParser::ArithmeticExprTContext::getRuleIndex() const {
  return FormulaTreeParser::RuleArithmeticExprT;
}

void FormulaTreeParser::ArithmeticExprTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmeticExprT(this);
}

void FormulaTreeParser::ArithmeticExprTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmeticExprT(this);
}

FormulaTreeParser::ArithmeticExprTContext* FormulaTreeParser::arithmeticExprT() {
  ArithmeticExprTContext *_localctx = _tracker.createInstance<ArithmeticExprTContext>(_ctx, getState());
  enterRule(_localctx, 10, FormulaTreeParser::RuleArithmeticExprT);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FormulaTreeParser::MOD: {
        setState(97);
        match(FormulaTreeParser::MOD);
        setState(98);
        arithmeticExpr();
        break;
      }

      case FormulaTreeParser::DIV: {
        setState(99);
        match(FormulaTreeParser::DIV);
        setState(100);
        arithmeticExpr();
        break;
      }

      case FormulaTreeParser::MUL: {
        setState(101);
        match(FormulaTreeParser::MUL);
        setState(102);
        arithmeticExpr();
        break;
      }

      case FormulaTreeParser::PLUS: {
        setState(103);
        match(FormulaTreeParser::PLUS);
        setState(104);
        arithmeticExpr();
        break;
      }

      case FormulaTreeParser::MINUS: {
        setState(105);
        match(FormulaTreeParser::MINUS);
        setState(106);
        arithmeticExpr();
        break;
      }

      case FormulaTreeParser::AND:
      case FormulaTreeParser::OR:
      case FormulaTreeParser::IMPLIES:
      case FormulaTreeParser::EQUIVALENT:
      case FormulaTreeParser::EQ:
      case FormulaTreeParser::NEQ:
      case FormulaTreeParser::GT:
      case FormulaTreeParser::LT:
      case FormulaTreeParser::GTE:
      case FormulaTreeParser::LTE:
      case FormulaTreeParser::UNTIL:
      case FormulaTreeParser::RELEASE:
      case FormulaTreeParser::CLOSE_PARAN: {
        break;
      }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArithValueContext ------------------------------------------------------------------

FormulaTreeParser::ArithValueContext::ArithValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FormulaTreeParser::IntegerContext* FormulaTreeParser::ArithValueContext::integer() {
  return getRuleContext<FormulaTreeParser::IntegerContext>(0);
}

FormulaTreeParser::DecimalContext* FormulaTreeParser::ArithValueContext::decimal() {
  return getRuleContext<FormulaTreeParser::DecimalContext>(0);
}


size_t FormulaTreeParser::ArithValueContext::getRuleIndex() const {
  return FormulaTreeParser::RuleArithValue;
}

void FormulaTreeParser::ArithValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithValue(this);
}

void FormulaTreeParser::ArithValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithValue(this);
}

FormulaTreeParser::ArithValueContext* FormulaTreeParser::arithValue() {
  ArithValueContext *_localctx = _tracker.createInstance<ArithValueContext>(_ctx, getState());
  enterRule(_localctx, 12, FormulaTreeParser::RuleArithValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(109);
      integer();
      break;
    }

    case 2: {
      setState(110);
      decimal();
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

//----------------- LogicalValueContext ------------------------------------------------------------------

FormulaTreeParser::LogicalValueContext::LogicalValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FormulaTreeParser::LogicalValueContext::TRUE() {
  return getToken(FormulaTreeParser::TRUE, 0);
}

tree::TerminalNode* FormulaTreeParser::LogicalValueContext::FALSE() {
  return getToken(FormulaTreeParser::FALSE, 0);
}


size_t FormulaTreeParser::LogicalValueContext::getRuleIndex() const {
  return FormulaTreeParser::RuleLogicalValue;
}

void FormulaTreeParser::LogicalValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalValue(this);
}

void FormulaTreeParser::LogicalValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalValue(this);
}

FormulaTreeParser::LogicalValueContext* FormulaTreeParser::logicalValue() {
  LogicalValueContext *_localctx = _tracker.createInstance<LogicalValueContext>(_ctx, getState());
  enterRule(_localctx, 14, FormulaTreeParser::RuleLogicalValue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    _la = _input->LA(1);
    if (!(_la == FormulaTreeParser::TRUE

    || _la == FormulaTreeParser::FALSE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdContext ------------------------------------------------------------------

FormulaTreeParser::IdContext::IdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FormulaTreeParser::AlphaContext* FormulaTreeParser::IdContext::alpha() {
  return getRuleContext<FormulaTreeParser::AlphaContext>(0);
}

std::vector<FormulaTreeParser::AlphaNumContext *> FormulaTreeParser::IdContext::alphaNum() {
  return getRuleContexts<FormulaTreeParser::AlphaNumContext>();
}

FormulaTreeParser::AlphaNumContext* FormulaTreeParser::IdContext::alphaNum(size_t i) {
  return getRuleContext<FormulaTreeParser::AlphaNumContext>(i);
}


size_t FormulaTreeParser::IdContext::getRuleIndex() const {
  return FormulaTreeParser::RuleId;
}

void FormulaTreeParser::IdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId(this);
}

void FormulaTreeParser::IdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId(this);
}

FormulaTreeParser::IdContext* FormulaTreeParser::id() {
  IdContext *_localctx = _tracker.createInstance<IdContext>(_ctx, getState());
  enterRule(_localctx, 16, FormulaTreeParser::RuleId);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    alpha();
    setState(119);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << FormulaTreeParser::LOWER_CASE)
      | (1ULL << FormulaTreeParser::UPPER_CASE)
      | (1ULL << FormulaTreeParser::DIGIT))) != 0)) {
      setState(116);
      alphaNum();
      setState(121);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecimalContext ------------------------------------------------------------------

FormulaTreeParser::DecimalContext::DecimalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FormulaTreeParser::IntegerContext* FormulaTreeParser::DecimalContext::integer() {
  return getRuleContext<FormulaTreeParser::IntegerContext>(0);
}

tree::TerminalNode* FormulaTreeParser::DecimalContext::DOT() {
  return getToken(FormulaTreeParser::DOT, 0);
}

FormulaTreeParser::WholeNumberContext* FormulaTreeParser::DecimalContext::wholeNumber() {
  return getRuleContext<FormulaTreeParser::WholeNumberContext>(0);
}


size_t FormulaTreeParser::DecimalContext::getRuleIndex() const {
  return FormulaTreeParser::RuleDecimal;
}

void FormulaTreeParser::DecimalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecimal(this);
}

void FormulaTreeParser::DecimalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecimal(this);
}

FormulaTreeParser::DecimalContext* FormulaTreeParser::decimal() {
  DecimalContext *_localctx = _tracker.createInstance<DecimalContext>(_ctx, getState());
  enterRule(_localctx, 18, FormulaTreeParser::RuleDecimal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    integer();
    setState(123);
    match(FormulaTreeParser::DOT);
    setState(124);
    wholeNumber();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerContext ------------------------------------------------------------------

FormulaTreeParser::IntegerContext::IntegerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FormulaTreeParser::WholeNumberContext* FormulaTreeParser::IntegerContext::wholeNumber() {
  return getRuleContext<FormulaTreeParser::WholeNumberContext>(0);
}

tree::TerminalNode* FormulaTreeParser::IntegerContext::PLUS() {
  return getToken(FormulaTreeParser::PLUS, 0);
}

tree::TerminalNode* FormulaTreeParser::IntegerContext::MINUS() {
  return getToken(FormulaTreeParser::MINUS, 0);
}


size_t FormulaTreeParser::IntegerContext::getRuleIndex() const {
  return FormulaTreeParser::RuleInteger;
}

void FormulaTreeParser::IntegerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger(this);
}

void FormulaTreeParser::IntegerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger(this);
}

FormulaTreeParser::IntegerContext* FormulaTreeParser::integer() {
  IntegerContext *_localctx = _tracker.createInstance<IntegerContext>(_ctx, getState());
  enterRule(_localctx, 20, FormulaTreeParser::RuleInteger);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == FormulaTreeParser::PLUS

    || _la == FormulaTreeParser::MINUS) {
      setState(126);
      _la = _input->LA(1);
      if (!(_la == FormulaTreeParser::PLUS

      || _la == FormulaTreeParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(129);
    wholeNumber();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WholeNumberContext ------------------------------------------------------------------

FormulaTreeParser::WholeNumberContext::WholeNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> FormulaTreeParser::WholeNumberContext::DIGIT() {
  return getTokens(FormulaTreeParser::DIGIT);
}

tree::TerminalNode* FormulaTreeParser::WholeNumberContext::DIGIT(size_t i) {
  return getToken(FormulaTreeParser::DIGIT, i);
}


size_t FormulaTreeParser::WholeNumberContext::getRuleIndex() const {
  return FormulaTreeParser::RuleWholeNumber;
}

void FormulaTreeParser::WholeNumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWholeNumber(this);
}

void FormulaTreeParser::WholeNumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWholeNumber(this);
}

FormulaTreeParser::WholeNumberContext* FormulaTreeParser::wholeNumber() {
  WholeNumberContext *_localctx = _tracker.createInstance<WholeNumberContext>(_ctx, getState());
  enterRule(_localctx, 22, FormulaTreeParser::RuleWholeNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      setState(131);
      match(FormulaTreeParser::DIGIT);
      break;
    }

    case 2: {
      setState(133); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(132);
        match(FormulaTreeParser::DIGIT);
        setState(135); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == FormulaTreeParser::DIGIT);
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

//----------------- AlphaContext ------------------------------------------------------------------

FormulaTreeParser::AlphaContext::AlphaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FormulaTreeParser::AlphaContext::LOWER_CASE() {
  return getToken(FormulaTreeParser::LOWER_CASE, 0);
}

tree::TerminalNode* FormulaTreeParser::AlphaContext::UPPER_CASE() {
  return getToken(FormulaTreeParser::UPPER_CASE, 0);
}


size_t FormulaTreeParser::AlphaContext::getRuleIndex() const {
  return FormulaTreeParser::RuleAlpha;
}

void FormulaTreeParser::AlphaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlpha(this);
}

void FormulaTreeParser::AlphaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlpha(this);
}

FormulaTreeParser::AlphaContext* FormulaTreeParser::alpha() {
  AlphaContext *_localctx = _tracker.createInstance<AlphaContext>(_ctx, getState());
  enterRule(_localctx, 24, FormulaTreeParser::RuleAlpha);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    _la = _input->LA(1);
    if (!(_la == FormulaTreeParser::LOWER_CASE

    || _la == FormulaTreeParser::UPPER_CASE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AlphaNumContext ------------------------------------------------------------------

FormulaTreeParser::AlphaNumContext::AlphaNumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FormulaTreeParser::AlphaContext* FormulaTreeParser::AlphaNumContext::alpha() {
  return getRuleContext<FormulaTreeParser::AlphaContext>(0);
}

tree::TerminalNode* FormulaTreeParser::AlphaNumContext::DIGIT() {
  return getToken(FormulaTreeParser::DIGIT, 0);
}


size_t FormulaTreeParser::AlphaNumContext::getRuleIndex() const {
  return FormulaTreeParser::RuleAlphaNum;
}

void FormulaTreeParser::AlphaNumContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlphaNum(this);
}

void FormulaTreeParser::AlphaNumContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlphaNum(this);
}

FormulaTreeParser::AlphaNumContext* FormulaTreeParser::alphaNum() {
  AlphaNumContext *_localctx = _tracker.createInstance<AlphaNumContext>(_ctx, getState());
  enterRule(_localctx, 26, FormulaTreeParser::RuleAlphaNum);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FormulaTreeParser::LOWER_CASE:
      case FormulaTreeParser::UPPER_CASE: {
        setState(141);
        alpha();
        break;
      }

      case FormulaTreeParser::DIGIT: {
        setState(142);
        match(FormulaTreeParser::DIGIT);
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

//----------------- NewlineContext ------------------------------------------------------------------

FormulaTreeParser::NewlineContext::NewlineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* FormulaTreeParser::NewlineContext::NL() {
  return getToken(FormulaTreeParser::NL, 0);
}


size_t FormulaTreeParser::NewlineContext::getRuleIndex() const {
  return FormulaTreeParser::RuleNewline;
}

void FormulaTreeParser::NewlineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewline(this);
}

void FormulaTreeParser::NewlineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FormulaTreeListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewline(this);
}

FormulaTreeParser::NewlineContext* FormulaTreeParser::newline() {
  NewlineContext *_localctx = _tracker.createInstance<NewlineContext>(_ctx, getState());
  enterRule(_localctx, 28, FormulaTreeParser::RuleNewline);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    match(FormulaTreeParser::NL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> FormulaTreeParser::_decisionToDFA;
atn::PredictionContextCache FormulaTreeParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN FormulaTreeParser::_atn;
std::vector<uint16_t> FormulaTreeParser::_serializedATN;

std::vector<std::string> FormulaTreeParser::_ruleNames = {
  "ltl", "ltlT", "atomicProposition", "relationalExpr", "arithmeticExpr", 
  "arithmeticExprT", "arithValue", "logicalValue", "id", "decimal", "integer", 
  "wholeNumber", "alpha", "alphaNum", "newline"
};

std::vector<std::string> FormulaTreeParser::_literalNames = {
  "", "'true'", "'false'", "'+'", "'-'", "'/'", "'*'", "'%'", "'!'", "'&&'", 
  "'||'", "'=>'", "'<=>'", "'=='", "'!='", "'>'", "'<'", "'>='", "'<='", 
  "'X'", "'U'", "'R'", "'G'", "'F'", "", "", "", "", "", "'.'", "','", "':'", 
  "';'", "'{'", "'}'", "'('", "')'"
};

std::vector<std::string> FormulaTreeParser::_symbolicNames = {
  "", "TRUE", "FALSE", "PLUS", "MINUS", "DIV", "MUL", "MOD", "NOT", "AND", 
  "OR", "IMPLIES", "EQUIVALENT", "EQ", "NEQ", "GT", "LT", "GTE", "LTE", 
  "NEXT", "UNTIL", "RELEASE", "GLOBAL", "FUTURE", "LOWER_CASE", "UPPER_CASE", 
  "DIGIT", "WS", "NL", "DOT", "COMMA", "COLON", "SC", "OPEN_CURLY", "CLOSE_CURLY", 
  "OPEN_PARAN", "CLOSE_PARAN"
};

dfa::Vocabulary FormulaTreeParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> FormulaTreeParser::_tokenNames;

FormulaTreeParser::Initializer::Initializer() {
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
    0x3, 0x26, 0x96, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 
    0x2, 0x39, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x47, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0x55, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x5, 0x6, 0x62, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x6e, 
    0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x72, 0xa, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x78, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 
    0x7b, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x5, 
    0xc, 0x82, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x6, 0xd, 
    0x88, 0xa, 0xd, 0xd, 0xd, 0xe, 0xd, 0x89, 0x5, 0xd, 0x8c, 0xa, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x92, 0xa, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x2, 0x2, 0x11, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x2, 0x7, 
    0x3, 0x2, 0x11, 0x14, 0x3, 0x2, 0xf, 0x10, 0x3, 0x2, 0x3, 0x4, 0x3, 
    0x2, 0x5, 0x6, 0x3, 0x2, 0x1a, 0x1b, 0x2, 0xa1, 0x2, 0x38, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x46, 0x3, 0x2, 0x2, 0x2, 0x6, 0x48, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x54, 0x3, 0x2, 0x2, 0x2, 0xa, 0x61, 0x3, 0x2, 0x2, 0x2, 0xc, 0x6d, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x71, 0x3, 0x2, 0x2, 0x2, 0x10, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x75, 0x3, 0x2, 0x2, 0x2, 0x14, 0x7c, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x81, 0x3, 0x2, 0x2, 0x2, 0x18, 0x8b, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x91, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x93, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x5, 0x6, 0x4, 0x2, 0x21, 
    0x22, 0x5, 0x4, 0x3, 0x2, 0x22, 0x39, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 
    0x7, 0x18, 0x2, 0x2, 0x24, 0x25, 0x5, 0x2, 0x2, 0x2, 0x25, 0x26, 0x5, 
    0x4, 0x3, 0x2, 0x26, 0x39, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x7, 0x19, 
    0x2, 0x2, 0x28, 0x29, 0x5, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x5, 0x4, 0x3, 
    0x2, 0x2a, 0x39, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0x15, 0x2, 0x2, 
    0x2c, 0x2d, 0x5, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x5, 0x4, 0x3, 0x2, 0x2e, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x7, 0xa, 0x2, 0x2, 0x30, 0x31, 
    0x5, 0x2, 0x2, 0x2, 0x31, 0x32, 0x5, 0x4, 0x3, 0x2, 0x32, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x25, 0x2, 0x2, 0x34, 0x35, 0x5, 0x2, 
    0x2, 0x2, 0x35, 0x36, 0x7, 0x26, 0x2, 0x2, 0x36, 0x37, 0x5, 0x4, 0x3, 
    0x2, 0x37, 0x39, 0x3, 0x2, 0x2, 0x2, 0x38, 0x20, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x23, 0x3, 0x2, 0x2, 0x2, 0x38, 0x27, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x38, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x38, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x3, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x7, 
    0x16, 0x2, 0x2, 0x3b, 0x47, 0x5, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x17, 
    0x2, 0x2, 0x3d, 0x47, 0x5, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0xb, 0x2, 
    0x2, 0x3f, 0x47, 0x5, 0x2, 0x2, 0x2, 0x40, 0x41, 0x7, 0xc, 0x2, 0x2, 
    0x41, 0x47, 0x5, 0x2, 0x2, 0x2, 0x42, 0x43, 0x7, 0xd, 0x2, 0x2, 0x43, 
    0x47, 0x5, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0xe, 0x2, 0x2, 0x45, 0x47, 
    0x5, 0x2, 0x2, 0x2, 0x46, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x46, 0x3c, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x46, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x46, 0x42, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x47, 0x3, 0x2, 0x2, 0x2, 0x47, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x48, 0x49, 0x5, 0x8, 0x5, 0x2, 0x49, 0x7, 0x3, 0x2, 0x2, 0x2, 0x4a, 
    0x55, 0x5, 0x10, 0x9, 0x2, 0x4b, 0x55, 0x5, 0x12, 0xa, 0x2, 0x4c, 0x4d, 
    0x5, 0xa, 0x6, 0x2, 0x4d, 0x4e, 0x9, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x5, 
    0xa, 0x6, 0x2, 0x4f, 0x55, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x5, 0xa, 
    0x6, 0x2, 0x51, 0x52, 0x9, 0x3, 0x2, 0x2, 0x52, 0x53, 0x5, 0xa, 0x6, 
    0x2, 0x53, 0x55, 0x3, 0x2, 0x2, 0x2, 0x54, 0x4a, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x54, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x54, 
    0x50, 0x3, 0x2, 0x2, 0x2, 0x55, 0x9, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 
    0x5, 0xe, 0x8, 0x2, 0x57, 0x58, 0x5, 0xc, 0x7, 0x2, 0x58, 0x62, 0x3, 
    0x2, 0x2, 0x2, 0x59, 0x5a, 0x5, 0x12, 0xa, 0x2, 0x5a, 0x5b, 0x5, 0xc, 
    0x7, 0x2, 0x5b, 0x62, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x25, 0x2, 
    0x2, 0x5d, 0x5e, 0x5, 0xa, 0x6, 0x2, 0x5e, 0x5f, 0x7, 0x26, 0x2, 0x2, 
    0x5f, 0x60, 0x5, 0xc, 0x7, 0x2, 0x60, 0x62, 0x3, 0x2, 0x2, 0x2, 0x61, 
    0x56, 0x3, 0x2, 0x2, 0x2, 0x61, 0x59, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0x62, 0xb, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 
    0x9, 0x2, 0x2, 0x64, 0x6e, 0x5, 0xa, 0x6, 0x2, 0x65, 0x66, 0x7, 0x7, 
    0x2, 0x2, 0x66, 0x6e, 0x5, 0xa, 0x6, 0x2, 0x67, 0x68, 0x7, 0x8, 0x2, 
    0x2, 0x68, 0x6e, 0x5, 0xa, 0x6, 0x2, 0x69, 0x6a, 0x7, 0x5, 0x2, 0x2, 
    0x6a, 0x6e, 0x5, 0xa, 0x6, 0x2, 0x6b, 0x6c, 0x7, 0x6, 0x2, 0x2, 0x6c, 
    0x6e, 0x5, 0xa, 0x6, 0x2, 0x6d, 0x63, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x6d, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x69, 0x3, 
    0x2, 0x2, 0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 
    0x2, 0x2, 0x6e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x72, 0x5, 0x16, 0xc, 
    0x2, 0x70, 0x72, 0x5, 0x14, 0xb, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x70, 0x3, 0x2, 0x2, 0x2, 0x72, 0xf, 0x3, 0x2, 0x2, 0x2, 0x73, 
    0x74, 0x9, 0x4, 0x2, 0x2, 0x74, 0x11, 0x3, 0x2, 0x2, 0x2, 0x75, 0x79, 
    0x5, 0x1a, 0xe, 0x2, 0x76, 0x78, 0x5, 0x1c, 0xf, 0x2, 0x77, 0x76, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x79, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x16, 0xc, 0x2, 
    0x7d, 0x7e, 0x7, 0x1f, 0x2, 0x2, 0x7e, 0x7f, 0x5, 0x18, 0xd, 0x2, 0x7f, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x80, 0x82, 0x9, 0x5, 0x2, 0x2, 0x81, 0x80, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 
    0x2, 0x2, 0x2, 0x83, 0x84, 0x5, 0x18, 0xd, 0x2, 0x84, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x85, 0x8c, 0x7, 0x1c, 0x2, 0x2, 0x86, 0x88, 0x7, 0x1c, 0x2, 
    0x2, 0x87, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 
    0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x8c, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x85, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x87, 
    0x3, 0x2, 0x2, 0x2, 0x8c, 0x19, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x9, 
    0x6, 0x2, 0x2, 0x8e, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x92, 0x5, 0x1a, 
    0xe, 0x2, 0x90, 0x92, 0x7, 0x1c, 0x2, 0x2, 0x91, 0x8f, 0x3, 0x2, 0x2, 
    0x2, 0x91, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x93, 0x94, 0x7, 0x1e, 0x2, 0x2, 0x94, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xd, 
    0x38, 0x46, 0x54, 0x61, 0x6d, 0x71, 0x79, 0x81, 0x89, 0x8b, 0x91, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

FormulaTreeParser::Initializer FormulaTreeParser::_init;
