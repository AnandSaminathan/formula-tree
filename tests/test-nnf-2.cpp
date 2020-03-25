#include <iostream>
#include "formula-tree/formula-tree.h"

std::string curString;


void print(FormulaNode cur) {
  std::cout << cur.getContent();
  curString += cur.getContent();
  for(int i = 0; i < cur.getChildrenCount(); ++i) {
    print(cur.getChild(i));
  }
}

int main() {
  FormulaTree tree("!G((p3 == 0) -> (p2 == 1 && p5 == 1))");
  FormulaTree tree2("!G(next_p1 == p1 - 2)");
  FormulaNode root = tree.getRoot();
  FormulaNode root2 = tree2.getRoot();
  print(root); std::cout << '\n';
  print(root2); std::cout << '\n';
  
  tree.makeNNF();
  tree2.makeNNF();
  FormulaNode nnfRoot = tree.getNNFRoot();
  FormulaNode nnfRoot2 = tree2.getNNFRoot();
  curString = "";
  print(nnfRoot); std::cout << '\n';
  assert(curString == "F()&&()==p30()||!=p21!=p51");
  curString = "";
  print(nnfRoot2); std::cout << '\n'; 
  assert(curString == "F()!=next_p1-p12");
}
