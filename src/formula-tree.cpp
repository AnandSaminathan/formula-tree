#include "FormulaLexer.h"
#include "FormulaParser.h"
#include "FormulaVisitor.h"

#include "antlr4-runtime.h"
#include "formula-tree/formula-tree.h"

#include <map>
#include <future>
#include <memory>
#include <vector>
#include <thread>

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
    return std::make_shared<FormulaNode>(cur);
  }

  std::string content = cur.getContent();
  if(content == "!") { return nnfConstruct(cur.getChild(0), !negate); }
  if(content == "->") {
    std::future<std::shared_ptr<FormulaNode>> left_future, right_future;
    std::string op;
    left_future = std::async(nnfConstruct, cur.getChild(0), false);
    right_future = std::async(nnfConstruct, cur.getChild(1), true);
    if(negate) {
      op = "&&";
    } else {
      op = "||";
    }
    std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[2]);
    children[0] = left_future.get(); children[1] = right_future.get();
    return std::make_shared<FormulaNode>(op, children, 2);
  }

  int childrenCount = cur.getChildrenCount();
  std::shared_ptr<std::shared_ptr<FormulaNode>[]> children(new std::shared_ptr<FormulaNode>[childrenCount]);
  std::vector<std::future<std::shared_ptr<FormulaNode>>> children_futures(childrenCount);
  for(int i = 0; i < childrenCount; ++i) { 
    children_futures[i] = std::async(nnfConstruct, cur.getChild(i), negate); 
  }
  for(int i = 0;i < childrenCount; i++) {
    children[i] = children_futures[i].get();
  }

  if(negate && complement.find(content) != complement.end()) { 
    return std::make_shared<FormulaNode>(complement[content], children, childrenCount);
  } else { 
    return std::make_shared<FormulaNode>(content, children, childrenCount);
  }
}


FormulaNode FormulaNode::getChild(int child) { assertChild(child); return (*children[child]); }
std::shared_ptr<FormulaNode> FormulaNode::getPointerToChild(int child) { assertChild(child); return (children[child]); }

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
  std::vector<std::thread> make_substitution_future(count);
  for(int i = 0; i < count; ++i) {
    make_substitution_future.emplace_back(std::thread([&]{makeSubstitution(root->getPointerToChild(i), mapper);}));
  }
  for(std::thread &i: make_substitution_future)
    if(i.joinable()) i.join();
}

void FormulaTree::substitute(std::map<std::string, std::string>& mapper) {
  makeSubstitution(this->root, mapper);
  this->formula = toString(getRoot());
}
