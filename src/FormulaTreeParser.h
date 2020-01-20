
// Generated from FormulaTree.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  FormulaTreeParser : public antlr4::Parser {
public:
  enum {
    TRUE = 1, FALSE = 2, PLUS = 3, MINUS = 4, DIV = 5, MUL = 6, MOD = 7, 
    NOT = 8, AND = 9, OR = 10, IMPLIES = 11, EQUIVALENT = 12, EQ = 13, NEQ = 14, 
    GT = 15, LT = 16, GTE = 17, LTE = 18, NEXT = 19, UNTIL = 20, RELEASE = 21, 
    GLOBAL = 22, FUTURE = 23, LOWER_CASE = 24, UPPER_CASE = 25, DIGIT = 26, 
    WS = 27, NL = 28, DOT = 29, COMMA = 30, COLON = 31, SC = 32, OPEN_CURLY = 33, 
    CLOSE_CURLY = 34, OPEN_PARAN = 35, CLOSE_PARAN = 36
  };

  enum {
    RuleLtl = 0, RuleLtlT = 1, RuleAtomicProposition = 2, RuleRelationalExpr = 3, 
    RuleArithmeticExpr = 4, RuleArithmeticExprT = 5, RuleArithValue = 6, 
    RuleLogicalValue = 7, RuleId = 8, RuleDecimal = 9, RuleInteger = 10, 
    RuleWholeNumber = 11, RuleAlpha = 12, RuleAlphaNum = 13, RuleNewline = 14
  };

  FormulaTreeParser(antlr4::TokenStream *input);
  ~FormulaTreeParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class LtlContext;
  class LtlTContext;
  class AtomicPropositionContext;
  class RelationalExprContext;
  class ArithmeticExprContext;
  class ArithmeticExprTContext;
  class ArithValueContext;
  class LogicalValueContext;
  class IdContext;
  class DecimalContext;
  class IntegerContext;
  class WholeNumberContext;
  class AlphaContext;
  class AlphaNumContext;
  class NewlineContext; 

  class  LtlContext : public antlr4::ParserRuleContext {
  public:
    LtlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AtomicPropositionContext *atomicProposition();
    LtlTContext *ltlT();
    antlr4::tree::TerminalNode *GLOBAL();
    LtlContext *ltl();
    antlr4::tree::TerminalNode *FUTURE();
    antlr4::tree::TerminalNode *NEXT();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *OPEN_PARAN();
    antlr4::tree::TerminalNode *CLOSE_PARAN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LtlContext* ltl();

  class  LtlTContext : public antlr4::ParserRuleContext {
  public:
    LtlTContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNTIL();
    LtlContext *ltl();
    antlr4::tree::TerminalNode *RELEASE();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *IMPLIES();
    antlr4::tree::TerminalNode *EQUIVALENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LtlTContext* ltlT();

  class  AtomicPropositionContext : public antlr4::ParserRuleContext {
  public:
    AtomicPropositionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RelationalExprContext *relationalExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AtomicPropositionContext* atomicProposition();

  class  RelationalExprContext : public antlr4::ParserRuleContext {
  public:
    RelationalExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LogicalValueContext *logicalValue();
    IdContext *id();
    std::vector<ArithmeticExprContext *> arithmeticExpr();
    ArithmeticExprContext* arithmeticExpr(size_t i);
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LTE();
    antlr4::tree::TerminalNode *GTE();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RelationalExprContext* relationalExpr();

  class  ArithmeticExprContext : public antlr4::ParserRuleContext {
  public:
    ArithmeticExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArithValueContext *arithValue();
    ArithmeticExprTContext *arithmeticExprT();
    IdContext *id();
    antlr4::tree::TerminalNode *OPEN_PARAN();
    ArithmeticExprContext *arithmeticExpr();
    antlr4::tree::TerminalNode *CLOSE_PARAN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArithmeticExprContext* arithmeticExpr();

  class  ArithmeticExprTContext : public antlr4::ParserRuleContext {
  public:
    ArithmeticExprTContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MOD();
    ArithmeticExprContext *arithmeticExpr();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArithmeticExprTContext* arithmeticExprT();

  class  ArithValueContext : public antlr4::ParserRuleContext {
  public:
    ArithValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntegerContext *integer();
    DecimalContext *decimal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArithValueContext* arithValue();

  class  LogicalValueContext : public antlr4::ParserRuleContext {
  public:
    LogicalValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicalValueContext* logicalValue();

  class  IdContext : public antlr4::ParserRuleContext {
  public:
    IdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AlphaContext *alpha();
    std::vector<AlphaNumContext *> alphaNum();
    AlphaNumContext* alphaNum(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IdContext* id();

  class  DecimalContext : public antlr4::ParserRuleContext {
  public:
    DecimalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntegerContext *integer();
    antlr4::tree::TerminalNode *DOT();
    WholeNumberContext *wholeNumber();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DecimalContext* decimal();

  class  IntegerContext : public antlr4::ParserRuleContext {
  public:
    IntegerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    WholeNumberContext *wholeNumber();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IntegerContext* integer();

  class  WholeNumberContext : public antlr4::ParserRuleContext {
  public:
    WholeNumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> DIGIT();
    antlr4::tree::TerminalNode* DIGIT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  WholeNumberContext* wholeNumber();

  class  AlphaContext : public antlr4::ParserRuleContext {
  public:
    AlphaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOWER_CASE();
    antlr4::tree::TerminalNode *UPPER_CASE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AlphaContext* alpha();

  class  AlphaNumContext : public antlr4::ParserRuleContext {
  public:
    AlphaNumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AlphaContext *alpha();
    antlr4::tree::TerminalNode *DIGIT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AlphaNumContext* alphaNum();

  class  NewlineContext : public antlr4::ParserRuleContext {
  public:
    NewlineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NewlineContext* newline();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

