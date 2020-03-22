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

  tree::ParseTree *tree = parser.form();
  FormulaVisitor visitor;
  visitor.visit(tree);
  root = visitor.getNode();
}

FormulaNode* nnfConstruct(FormulaNode cur, bool negate) {
  if(cur.isLeaf()) { 
    return new FormulaNode(cur);
  }

  std::string content = cur.getContent();
  if(content == "!") { return nnfConstruct(cur.getChild(0), !negate); }
  if(content == "->") {
    if(negate) {
      FormulaNode* left = nnfConstruct(cur.getChild(0), !negate);
      FormulaNode* right = nnfConstruct(cur.getChild(1), negate);
      return new FormulaNode("&&", {left, right});
    } else {
      FormulaNode* left = nnfConstruct(cur.getChild(0), negate);
      FormulaNode* right = nnfConstruct(cur.getChild(1), !negate);
      return new FormulaNode("||", {left, right});
    }
  }

  std::vector<FormulaNode*> children;
  int childrenCount = cur.getChildrenCount();
  for(int i = 0; i < childrenCount; ++i) { children.emplace_back(nnfConstruct(cur.getChild(i), negate)); }

  if(negate && complement.find(content) != complement.end()) { return new FormulaNode(complement[content], children); } 
  else { 
    return new FormulaNode(content, children); 
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
  complement[">="] = "<";
  complement["<="] = ">";
  complement[">"] = "<=";
  complement["<"] = ">=";
  complement["=="] = "!=";
  complement["!="] = "==";
  nnfRoot = nnfConstruct(getRoot(), false);
}

std::string FormulaTree::toString(FormulaNode root) {
  if(root.isLeaf()) return (root.getContent());

  std::string content = root.getContent();
  int childrenCount = root.getChildrenCount();

  switch(childrenCount) {
    case 1: {
      if(content == "()") { return "(" + toString(root.getChild(0)) + ")"; } 
      else { return content + toString(root.getChild(0)); }
    } break;

    case 2: {
      return toString(root.getChild(0)) + content + toString(root.getChild(1));
    } break;

    default : assert(childrenCount <= 2);
  }
}


void makeSubstitution(FormulaNode* root, std::map<std::string, std::string>& mapper) {
  if(root->isVar()) {
    std::string content = root->getContent();
    if(mapper.find(content) != mapper.end()) {
      FormulaTree subTree(mapper[content]);
      (*root) = subTree.getRoot();
    }
    return ;
  }

  int count = root->getChildrenCount();
  for(int i = 0; i < count; ++i) {
    makeSubstitution(root->getPointerToChild(i), mapper);
  }
}

void FormulaTree::substitute(std::map<std::string, std::string>& mapper) {
  makeSubstitution(this->root, mapper);
  this->formula = toString(getRoot());
}