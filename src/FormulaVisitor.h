#pragma once

#include "FormulaLexer.h"
#include "FormulaParser.h"
#include "FormulaParserBaseVisitor.h"
#include "formula-tree/formula-tree.h"

#include "antlr4-runtime.h"

class FormulaVisitor : public FormulaParserBaseVisitor {
  public:

    antlrcpp::Any visitPropUnary(FormulaParser::PropUnaryContext *ctx) {
      std::vector<std::shared_ptr<FormulaNode>> children(1);
      visit(ctx->formula); children[0] = node;
      makeNode((ctx->op)->getText(), children);

      return nullptr;
    }

    antlrcpp::Any visitPropBinary(FormulaParser::PropBinaryContext *ctx) override {
      std::vector<std::shared_ptr<FormulaNode>> children(2);
      visit(ctx->left); children[0] = node;
      visit(ctx->right); children[1] = node;
      makeNode((ctx->op)->getText(), children);

      return nullptr;      
    }

    antlrcpp::Any visitPropParentheses(FormulaParser::PropParenthesesContext *ctx) override {
      std::vector<std::shared_ptr<FormulaNode>> children(1);
      visit(ctx->formula); children[0] = node;
      makeNode("()", children);
      
      return nullptr;
    }

    antlrcpp::Any visitLtlUnary(FormulaParser::LtlUnaryContext *ctx) override {
      std::vector<std::shared_ptr<FormulaNode>> children(1);
      visit(ctx->formula); children[0] = node;
      makeNode((ctx->op)->getText(), children);

      return nullptr;
    }

    antlrcpp::Any visitLtlBinary(FormulaParser::LtlBinaryContext *ctx) override {
      std::vector<std::shared_ptr<FormulaNode>> children(2);
      visit(ctx->left); children[0] = node;
      visit(ctx->right); children[1] = node;
      makeNode((ctx->op)->getText(), children);

      return nullptr;
    }

    antlrcpp::Any visitLtlParentheses(FormulaParser::LtlParenthesesContext *ctx) override {
      std::vector<std::shared_ptr<FormulaNode>> children(1);
      visit(ctx->formula); children[0] = node;
      makeNode(parenthesis, children);

      return nullptr;
    }

    antlrcpp::Any visitRelationalId(FormulaParser::RelationalIdContext *ctx) override {
      std::vector<std::shared_ptr<FormulaNode>> children;
      makeNode((ctx->name)->getText(), children);

      return nullptr;
    }

    antlrcpp::Any visitRelationalValue(FormulaParser::RelationalValueContext *ctx) override {
      std::vector<std::shared_ptr<FormulaNode>> children;
      makeNode((ctx->value)->getText(), children);
      node->toggleIsVar();
      node->setType("bool");

      return nullptr;
    }

    antlrcpp::Any visitRelationalParentheses(FormulaParser::RelationalParenthesesContext *ctx) override {
      std::vector<std::shared_ptr<FormulaNode>> children(1);
      visit(ctx->formula); children[0] = node;
      makeNode(parenthesis, children);    

      return nullptr;
    }

    antlrcpp::Any visitRelationalBinary(FormulaParser::RelationalBinaryContext *ctx) override {
      std::vector<std::shared_ptr<FormulaNode>> children(2);
      visit(ctx->left); children[0] = node;
      visit(ctx->right); children[1] = node;
      makeNode((ctx->op)->getText(), children);

      return nullptr;
    }

    antlrcpp::Any visitArithmeticParentheses(FormulaParser::ArithmeticParenthesesContext *ctx) override {
      std::vector<std::shared_ptr<FormulaNode>> children(1);
      visit(ctx->formula); children[0] = node;
      makeNode(parenthesis, children);

      return nullptr;
    }

    antlrcpp::Any visitArithmeticId(FormulaParser::ArithmeticIdContext *ctx) override {
      std::vector<std::shared_ptr<FormulaNode>> children;
      makeNode((ctx->name)->getText(), children);

      return nullptr;
    }

    antlrcpp::Any visitArithmeticValue(FormulaParser::ArithmeticValueContext *ctx) override {
      std::vector<std::shared_ptr<FormulaNode>> children;
      makeNode((ctx->value)->getText(), children);
      visit(ctx->value);
      node->toggleIsVar();

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

    antlrcpp::Any visitArithmeticBinary(FormulaParser::ArithmeticBinaryContext *ctx) override {
      std::vector<std::shared_ptr<FormulaNode>> children(2);
      visit(ctx->left); children[0] = node;
      visit(ctx->right); children[1] = node;
      makeNode((ctx->op)->getText(), children);

      return nullptr;
    }

    antlrcpp::Any visitAtomicProposition(FormulaParser::AtomicPropositionContext *ctx) override {
      visit(ctx->relationalForm());

      return nullptr;
    }

    std::shared_ptr<FormulaNode> getNode() {
      return node;
    }

  private:

    std::shared_ptr<FormulaNode> node;
    std::string parenthesis{"()"};

    void makeNode(std::string content, std::vector<std::shared_ptr<FormulaNode>> children) {
      node.reset(new FormulaNode(content, children));
    }
};
