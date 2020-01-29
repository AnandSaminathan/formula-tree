#include "formula_tree.cpp"
#include "generated/antlr4-runtime.h"
#include "generated/FormulaLexer.h"
#include "generated/FormulaParser.h"

using namespace antlr4;

void FormulaTree::contructTree() {
  ANTLRInputStream input(formula);
  FormulaLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();
  for (auto token : tokens.getTokens()) {
    std::cout << token->toString() << std::endl;
  }

  TParser parser(&tokens);
  tree::ParseTree* tree = parser.ltl();

  std::cout << tree->toStringTree(&parser) << std::endl << std::endl;
}