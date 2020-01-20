
// Generated from FormulaTree.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "FormulaTreeListener.h"


/**
 * This class provides an empty implementation of FormulaTreeListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  FormulaTreeBaseListener : public FormulaTreeListener {
public:

  virtual void enterLtl(FormulaTreeParser::LtlContext * /*ctx*/) override { }
  virtual void exitLtl(FormulaTreeParser::LtlContext * /*ctx*/) override { }

  virtual void enterLtlT(FormulaTreeParser::LtlTContext * /*ctx*/) override { }
  virtual void exitLtlT(FormulaTreeParser::LtlTContext * /*ctx*/) override { }

  virtual void enterAtomicProposition(FormulaTreeParser::AtomicPropositionContext * /*ctx*/) override { }
  virtual void exitAtomicProposition(FormulaTreeParser::AtomicPropositionContext * /*ctx*/) override { }

  virtual void enterRelationalExpr(FormulaTreeParser::RelationalExprContext * /*ctx*/) override { }
  virtual void exitRelationalExpr(FormulaTreeParser::RelationalExprContext * /*ctx*/) override { }

  virtual void enterArithmeticExpr(FormulaTreeParser::ArithmeticExprContext * /*ctx*/) override { }
  virtual void exitArithmeticExpr(FormulaTreeParser::ArithmeticExprContext * /*ctx*/) override { }

  virtual void enterArithmeticExprT(FormulaTreeParser::ArithmeticExprTContext * /*ctx*/) override { }
  virtual void exitArithmeticExprT(FormulaTreeParser::ArithmeticExprTContext * /*ctx*/) override { }

  virtual void enterArithValue(FormulaTreeParser::ArithValueContext * /*ctx*/) override { }
  virtual void exitArithValue(FormulaTreeParser::ArithValueContext * /*ctx*/) override { }

  virtual void enterLogicalValue(FormulaTreeParser::LogicalValueContext * /*ctx*/) override { }
  virtual void exitLogicalValue(FormulaTreeParser::LogicalValueContext * /*ctx*/) override { }

  virtual void enterId(FormulaTreeParser::IdContext * /*ctx*/) override { }
  virtual void exitId(FormulaTreeParser::IdContext * /*ctx*/) override { }

  virtual void enterDecimal(FormulaTreeParser::DecimalContext * /*ctx*/) override { }
  virtual void exitDecimal(FormulaTreeParser::DecimalContext * /*ctx*/) override { }

  virtual void enterInteger(FormulaTreeParser::IntegerContext * /*ctx*/) override { }
  virtual void exitInteger(FormulaTreeParser::IntegerContext * /*ctx*/) override { }

  virtual void enterWholeNumber(FormulaTreeParser::WholeNumberContext * /*ctx*/) override { }
  virtual void exitWholeNumber(FormulaTreeParser::WholeNumberContext * /*ctx*/) override { }

  virtual void enterAlpha(FormulaTreeParser::AlphaContext * /*ctx*/) override { }
  virtual void exitAlpha(FormulaTreeParser::AlphaContext * /*ctx*/) override { }

  virtual void enterAlphaNum(FormulaTreeParser::AlphaNumContext * /*ctx*/) override { }
  virtual void exitAlphaNum(FormulaTreeParser::AlphaNumContext * /*ctx*/) override { }

  virtual void enterNewline(FormulaTreeParser::NewlineContext * /*ctx*/) override { }
  virtual void exitNewline(FormulaTreeParser::NewlineContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

