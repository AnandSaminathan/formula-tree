#include <iostream>
#include "formula-tree/formula-tree.h"

void print(FormulaNode cur) {
  std::cout << cur.getContent();
  for(int i = 0; i < cur.getChildrenCount(); ++i) {
    print(cur.getChild(i));
  }
}

int main() {
  FormulaTree tree("!G((p3 == 0) -> (p2 == 1 && p5 == 1))");
  FormulaNode root = tree.getRoot();
  print(root); std::cout << '\n';
  
  tree.makeNNF();
  FormulaNode nnfRoot = tree.getNNFRoot();
  print(nnfRoot); std::cout << '\n';
}
