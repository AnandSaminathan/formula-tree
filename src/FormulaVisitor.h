#pragma once

#include "FormulaLexer.h"
#include "FormulaParser.h"
#include "FormulaParserBaseVisitor.h"
#include "formula-tree/formula-tree.h"

#include "antlr4-runtime.h"

class FormulaVisitor : public FormulaParserBaseVisitor {
  public:

    antlrcpp::Any visitPropUnary(FormulaParser::PropUnaryContext *ctx) override {
      handleUnary(ctx);
      node->setSubTreeType(pl);
      return nullptr;
    }

    antlrcpp::Any visitPropBinary(FormulaParser::PropBinaryContext *ctx) override {
      handleBinary(ctx);
      node->setSubTreeType(pl);
      return nullptr;
    }

    antlrcpp::Any visitPropParenthesis(FormulaParser::PropParenthesisContext *ctx) override {
      handleParenthesis(ctx);
      node->setSubTreeType(pl);
      return nullptr;
    }

    antlrcpp::Any visitPseudoBoolCoeff(FormulaParser::PseudoBoolCoeffContext *ctx) override {
      handleBinary(ctx);
      node->setSubTreeType(pb);
      return nullptr;
    }

    antlrcpp::Any visitPseudoBoolIneqBinary(FormulaParser::PseudoBoolIneqBinaryContext *ctx) override {
      handleBinary(ctx);
      node->setSubTreeType(pb);
      return nullptr;
    }

    antlrcpp::Any visitPseudoBoolLogicalBinary(FormulaParser::PseudoBoolLogicalBinaryContext *ctx) override {
      handleBinary(ctx);
      node->setSubTreeType(pb);
      return nullptr;
    }

    antlrcpp::Any visitPseudoBoolLogicalUnary(FormulaParser::PseudoBoolLogicalUnaryContext *ctx) override {
      handleUnary(ctx);
      node->setSubTreeType(pb);
      return nullptr;
    }

    antlrcpp::Any visitPseudoBoolArithBinary(FormulaParser::PseudoBoolArithBinaryContext *ctx) override {
      handleBinary(ctx);
      node->setSubTreeType(pb);
      return nullptr;
    }

    antlrcpp::Any visitPseudoBoolParenthesis(FormulaParser::PseudoBoolParenthesisContext *ctx) override {
      handleParenthesis(ctx);
      node->setSubTreeType(pb);
      return nullptr;
    }

    antlrcpp::Any visitLtlUnary(FormulaParser::LtlUnaryContext *ctx) override { 
      handleUnary(ctx); 
      node->setSubTreeType(ltl);
      return nullptr; 
    }

    antlrcpp::Any visitLtlBinary(FormulaParser::LtlBinaryContext *ctx) override { 
      handleBinary(ctx); 
      node->setSubTreeType(ltl);
      return nullptr; 
    }

    antlrcpp::Any visitLtlParenthesis(FormulaParser::LtlParenthesisContext *ctx) override {
      handleParenthesis(ctx);
      node->setSubTreeType(ltl);
      return nullptr;
    }

    antlrcpp::Any visitRelationalId(FormulaParser::RelationalIdContext *ctx) override {
      handleBase(ctx);
      node->setSubTreeType(rel);
      return nullptr;
    }

    antlrcpp::Any visitRelationalValue(FormulaParser::RelationalValueContext *ctx) override {
      handleBase(ctx);
      node->setSubTreeType(rel);
      node->toggleVal();
      node->setType("bool");
      return nullptr;
    }

    antlrcpp::Any visitRelationalParenthesis(FormulaParser::RelationalParenthesisContext *ctx) override { 
      handleParenthesis(ctx); 
      node->setSubTreeType(rel);
      return nullptr; 
    }

    antlrcpp::Any visitRelationalBinary(FormulaParser::RelationalBinaryContext *ctx) override {
      handleBinary(ctx);
      node->setSubTreeType(rel);
      return nullptr;
    }

    antlrcpp::Any visitArithmeticParenthesis(FormulaParser::ArithmeticParenthesisContext *ctx) override {
      handleParenthesis(ctx);
      node->setSubTreeType(arith);
      return nullptr;
    }

    antlrcpp::Any visitArithmeticId(FormulaParser::ArithmeticIdContext *ctx) override {
      handleBase(ctx);
      node->setSubTreeType(arith);
      return nullptr;
    }

    antlrcpp::Any visitArithmeticValue(FormulaParser::ArithmeticValueContext *ctx) override {
      handleBase(ctx);
      visit(ctx->content);
      node->toggleVal();
      node->setSubTreeType(arith);
      return nullptr;
    }

    antlrcpp::Any visitArithmeticBinary(FormulaParser::ArithmeticBinaryContext *ctx) override {
      handleBinary(ctx);
      node->setSubTreeType(arith);
      return nullptr;
    }

    antlrcpp::Any visitInteger(FormulaParser::IntegerContext *ctx) override {
      node->setType("int");
      return nullptr;
    }

    antlrcpp::Any visitDecimal(FormulaParser::DecimalContext *ctx) override {
      node->setType("real");
      return nullptr;
    }

    antlrcpp::Any visitWholeNumber(FormulaParser::WholeNumberContext *ctx) override {\
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> empty;
      node.reset(new FormulaNode((ctx->getText()), empty, 0));
      node->setType("int");
      node->setSubTreeType(arith);
      return nullptr;
    }

    std::shared_ptr<FormulaNode> getNode() {
      return node;
    }

  private:

    std::shared_ptr<FormulaNode> node;
    std::string parenthesisOp{"()"};

    template<typename context>
    void handleBinary(context ctx) {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[2]);      
      visit(ctx->left); children[0] = node;
      visit(ctx->right); children[1] = node;
      node.reset(new FormulaNode((ctx->op)->getText(), children, 2));
    }

    template<typename context>
    void handleUnary(context ctx) {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[1]);      
      visit(ctx->formula); children[0] = node;
      node.reset(new FormulaNode((ctx->op)->getText(), children, 1));
    }

    template<typename context>
    void handleParenthesis(context ctx) {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[1]);      
      visit(ctx->formula); children[0] = node;
      node.reset(new FormulaNode(parenthesisOp, children, 1));      
    }

    template<typename context>
    void handleBase(context ctx) {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[0]);      
      node.reset(new FormulaNode((ctx->content)->getText(), children, 0));        
    }
};

