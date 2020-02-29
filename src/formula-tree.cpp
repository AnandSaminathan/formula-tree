#include "FormulaLexer.h"
#include "FormulaParser.h"
#include "FormulaVisitor.h"

#include "antlr4-runtime.h"
#include "formula-tree/formula-tree.h"

#include <map>

using namespace antlr4;

std::map<std::string, std::string> complement;

void FormulaTree::constructTree() {
  ANTLRInputStream input(this->formula);
  FormulaLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  FormulaParser parser(&tokens);

  tree::ParseTree *tree = parser.ltlForm();
  FormulaVisitor visitor;
  visitor.visit(tree);
  root = visitor.getNode();
}

FormulaNode* nnfConstruct(FormulaNode cur, bool negate) {
  if(cur.isLeaf()) { return new FormulaNode(cur.getContent(), {}); }

  std::string content = cur.getContent();
  if(content == "!") { return nnfConstruct(cur.getChild(0), !negate); }

  std::vector<FormulaNode*> children;
  int childrenCount = cur.getChildrenCount();
  for(int i = 0; i < childrenCount; ++i) { children.emplace_back(nnfConstruct(cur.getChild(i), negate)); }

  if(negate && complement.find(content) != complement.end()) { return new FormulaNode(complement[content], children); } 
  else { 
    FormulaNode* child = new FormulaNode(content, children); 
    if(negate && content != "()") { return new FormulaNode("!", {child}); }
    else { return child; } 
  }

  return nullptr;
}

void FormulaTree::constructNNF() {
  complement["&&"] = "||";
  complement["||"] = "&&";
  complement["F"] = "G";
  complement["G"] = "F";
  complement["X"] = "X";
  complement["U"] = "R";
  complement["R"] = "U";
  nnfRoot = nnfConstruct(getRoot(), false);
}
