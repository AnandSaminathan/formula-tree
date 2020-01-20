
// Generated from FormulaTree.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  FormulaTreeLexer : public antlr4::Lexer {
public:
  enum {
    TRUE = 1, FALSE = 2, PLUS = 3, MINUS = 4, DIV = 5, MUL = 6, MOD = 7, 
    NOT = 8, AND = 9, OR = 10, IMPLIES = 11, EQUIVALENT = 12, EQ = 13, NEQ = 14, 
    GT = 15, LT = 16, GTE = 17, LTE = 18, NEXT = 19, UNTIL = 20, RELEASE = 21, 
    GLOBAL = 22, FUTURE = 23, LOWER_CASE = 24, UPPER_CASE = 25, DIGIT = 26, 
    WS = 27, NL = 28, DOT = 29, COMMA = 30, COLON = 31, SC = 32, OPEN_CURLY = 33, 
    CLOSE_CURLY = 34, OPEN_PARAN = 35, CLOSE_PARAN = 36
  };

  FormulaTreeLexer(antlr4::CharStream *input);
  ~FormulaTreeLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

