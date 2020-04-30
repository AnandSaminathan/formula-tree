#include "antlr4-runtime.h"
#include "FormulaLexer.h"
#include "FormulaParser.h"

using namespace antlr4;

int main() {
  std::string t1 = "(a == true && b == true)";
  std::string t2 = "((c == true) -> (d == false))";
  std::string pseudoBoolean = t1 + " + " + t2 + " == 1"; 
  ANTLRInputStream input(pseudoBoolean);
  FormulaLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  FormulaParser parser(&tokens);

  tree::ParseTree *tree = parser.form();
  std::cout << tree->toStringTree(&parser) << std::endl << std::endl;
}
