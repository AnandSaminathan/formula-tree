
// Generated from FormulaTree.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "FormulaTreeParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by FormulaTreeParser.
 */
class  FormulaTreeListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterLtl(FormulaTreeParser::LtlContext *ctx) = 0;
  virtual void exitLtl(FormulaTreeParser::LtlContext *ctx) = 0;

  virtual void enterLtlT(FormulaTreeParser::LtlTContext *ctx) = 0;
  virtual void exitLtlT(FormulaTreeParser::LtlTContext *ctx) = 0;

  virtual void enterAtomicProposition(FormulaTreeParser::AtomicPropositionContext *ctx) = 0;
  virtual void exitAtomicProposition(FormulaTreeParser::AtomicPropositionContext *ctx) = 0;

  virtual void enterRelationalExpr(FormulaTreeParser::RelationalExprContext *ctx) = 0;
  virtual void exitRelationalExpr(FormulaTreeParser::RelationalExprContext *ctx) = 0;

  virtual void enterArithmeticExpr(FormulaTreeParser::ArithmeticExprContext *ctx) = 0;
  virtual void exitArithmeticExpr(FormulaTreeParser::ArithmeticExprContext *ctx) = 0;

  virtual void enterArithmeticExprT(FormulaTreeParser::ArithmeticExprTContext *ctx) = 0;
  virtual void exitArithmeticExprT(FormulaTreeParser::ArithmeticExprTContext *ctx) = 0;

  virtual void enterArithValue(FormulaTreeParser::ArithValueContext *ctx) = 0;
  virtual void exitArithValue(FormulaTreeParser::ArithValueContext *ctx) = 0;

  virtual void enterLogicalValue(FormulaTreeParser::LogicalValueContext *ctx) = 0;
  virtual void exitLogicalValue(FormulaTreeParser::LogicalValueContext *ctx) = 0;

  virtual void enterId(FormulaTreeParser::IdContext *ctx) = 0;
  virtual void exitId(FormulaTreeParser::IdContext *ctx) = 0;

  virtual void enterDecimal(FormulaTreeParser::DecimalContext *ctx) = 0;
  virtual void exitDecimal(FormulaTreeParser::DecimalContext *ctx) = 0;

  virtual void enterInteger(FormulaTreeParser::IntegerContext *ctx) = 0;
  virtual void exitInteger(FormulaTreeParser::IntegerContext *ctx) = 0;

  virtual void enterWholeNumber(FormulaTreeParser::WholeNumberContext *ctx) = 0;
  virtual void exitWholeNumber(FormulaTreeParser::WholeNumberContext *ctx) = 0;

  virtual void enterAlpha(FormulaTreeParser::AlphaContext *ctx) = 0;
  virtual void exitAlpha(FormulaTreeParser::AlphaContext *ctx) = 0;

  virtual void enterAlphaNum(FormulaTreeParser::AlphaNumContext *ctx) = 0;
  virtual void exitAlphaNum(FormulaTreeParser::AlphaNumContext *ctx) = 0;

  virtual void enterNewline(FormulaTreeParser::NewlineContext *ctx) = 0;
  virtual void exitNewline(FormulaTreeParser::NewlineContext *ctx) = 0;


};

