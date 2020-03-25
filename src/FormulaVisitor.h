#pragma once

#include "FormulaLexer.h"
#include "FormulaParser.h"
#include "FormulaParserBaseVisitor.h"
#include "formula-tree/formula-tree.h"

#include "antlr4-runtime.h"

class FormulaVisitor : public FormulaParserBaseVisitor {
  public:

    antlrcpp::Any visitPropUnary(FormulaParser::PropUnaryContext *ctx) {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[1]);
      visit(ctx->formula); children[0] = node;
      makeNode((ctx->op)->getText(), children, 1);

      return nullptr;
    }

    antlrcpp::Any visitPropBinary(FormulaParser::PropBinaryContext *ctx) override {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[2]);
      visit(ctx->left); children[0] = node;
      visit(ctx->right); children[1] = node;
      makeNode((ctx->op)->getText(), children, 2);

      return nullptr;      
    }

    antlrcpp::Any visitPropParentheses(FormulaParser::PropParenthesesContext *ctx) override {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[1]);
      visit(ctx->formula); children[0] = node;
      makeNode("()", children, 1);
      
      return nullptr;
    }

    antlrcpp::Any visitLtlUnary(FormulaParser::LtlUnaryContext *ctx) override {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[1]);
      visit(ctx->formula); children[0] = node;
      makeNode((ctx->op)->getText(), children, 1);

      return nullptr;
    }

    antlrcpp::Any visitLtlBinary(FormulaParser::LtlBinaryContext *ctx) override {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[2]);
      visit(ctx->left); children[0] = node;
      visit(ctx->right); children[1] = node;
      makeNode((ctx->op)->getText(), children, 2);

      return nullptr;
    }

    antlrcpp::Any visitLtlParentheses(FormulaParser::LtlParenthesesContext *ctx) override {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[1]);
      visit(ctx->formula); children[0] = node;
      makeNode(parenthesis, children, 1);

      return nullptr;
    }

    antlrcpp::Any visitRelationalId(FormulaParser::RelationalIdContext *ctx) override {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children;
      makeNode((ctx->name)->getText(), children, 0);

      return nullptr;
    }

    antlrcpp::Any visitRelationalValue(FormulaParser::RelationalValueContext *ctx) override {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children;
      makeNode((ctx->value)->getText(), children, 0);
      node->toggleIsVar();
      node->setType("bool");

      return nullptr;
    }

    antlrcpp::Any visitRelationalParentheses(FormulaParser::RelationalParenthesesContext *ctx) override {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[1]);
      visit(ctx->formula); children[0] = node;
      makeNode(parenthesis, children, 1);    

      return nullptr;
    }

    antlrcpp::Any visitRelationalBinary(FormulaParser::RelationalBinaryContext *ctx) override {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[2]);
      visit(ctx->left); children[0] = node;
      visit(ctx->right); children[1] = node;
      makeNode((ctx->op)->getText(), children, 2);

      return nullptr;
    }

    antlrcpp::Any visitArithmeticParentheses(FormulaParser::ArithmeticParenthesesContext *ctx) override {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[1]);
      visit(ctx->formula); children[0] = node;
      makeNode(parenthesis, children, 1);

      return nullptr;
    }

    antlrcpp::Any visitArithmeticId(FormulaParser::ArithmeticIdContext *ctx) override {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children;
      makeNode((ctx->name)->getText(), children, 0);

      return nullptr;
    }

    antlrcpp::Any visitArithmeticValue(FormulaParser::ArithmeticValueContext *ctx) override {
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children;
      makeNode((ctx->value)->getText(), children, 0);
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
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[2]);
      visit(ctx->left); children[0] = node;
      visit(ctx->right); children[1] = node;
      makeNode((ctx->op)->getText(), children, 2);

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

    inline void makeNode(std::string content, std::shared_ptr<std::shared_ptr<FormulaNode>[]> children, int count) {
      node.reset(new FormulaNode(content, children, count));
    }
};
