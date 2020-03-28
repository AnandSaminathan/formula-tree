#include "FormulaLexer.h"
#include "FormulaParser.h"
#include "FormulaVisitor.h"

#include "antlr4-runtime.h"
#include "formula-tree/formula-tree.h"

#include <map>

using namespace antlr4;
using namespace antlr4::atn;

std::map<std::string, std::string> complement;

void FormulaTree::constructTree() {
  ANTLRInputStream input(this->formula);
  FormulaLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  tokens.fill();
  FormulaParser parser(&tokens);
  parser.getInterpreter<ParserATNSimulator>()->setPredictionMode(PredictionMode::SLL);

  tree::ParseTree *tree = parser.form();
  FormulaVisitor visitor;
  visitor.visit(tree);
  root = visitor.getNode();
}

std::shared_ptr<FormulaNode> nnfConstruct(FormulaNode cur, bool negate) {
  if(cur.isLeaf()) { 
    return std::shared_ptr<FormulaNode>(new FormulaNode(cur));
  }

  std::string content = cur.getContent();
  if(content == "!") { return nnfConstruct(cur.getChild(0), !negate); }
  if(content == "->") {
    std::shared_ptr<FormulaNode> left, right;
    std::string op;
    if(negate) {
      left = nnfConstruct(cur.getChild(0), !negate);
      right = nnfConstruct(cur.getChild(1), negate);
      op = "&&";
    } else {
      left = nnfConstruct(cur.getChild(0), negate);
      right = nnfConstruct(cur.getChild(1), !negate);
      op = "||";
    }
    std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[2]);
    children[0] = left; children[1] = right;
    return std::shared_ptr<FormulaNode>(new FormulaNode(op, children, 2));
  }

  int childrenCount = cur.getChildrenCount();
  std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[childrenCount]);
  for(int i = 0; i < childrenCount; ++i) { children[i] = nnfConstruct(cur.getChild(i), negate); }

  if(negate && complement.find(content) != complement.end()) { 
    return std::shared_ptr<FormulaNode>(new FormulaNode(complement[content], children, childrenCount)); 
  } else { 
    return std::shared_ptr<FormulaNode>(new FormulaNode(content, children, childrenCount)); 
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


void makeSubstitution(std::shared_ptr<FormulaNode> root, std::map<std::string, std::string>& mapper) {
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