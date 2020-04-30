#include "antlr4-runtime.h"
#include "FormulaLexer.h"
#include "FormulaParser.h"

using namespace antlr4;

int main() {
  std::string p1 = "(a == true && b == true)";
  ANTLRInputStream input(p1);
  FormulaLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  FormulaParser parser(&tokens);

  tree::ParseTree *tree = parser.form();
  std::cout << tree->toStringTree(&parser) << std::endl << std::endl;
}
