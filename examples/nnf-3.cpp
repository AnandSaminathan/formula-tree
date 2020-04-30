#include <iostream>
#include "formula-tree/formula-tree.h"

std::string curString;

void print(FormulaNode cur) {
  curString += cur.getContent();
  for(int i = 0; i < cur.getChildrenCount(); ++i) {
    print(cur.getChild(i));
  }
}

int main() {
  FormulaTree tree("!(a U b)");
  FormulaNode root = tree.getRoot();
  print(root);
  
  tree.makeNNF();
  FormulaNode nnfRoot = tree.getNNFRoot();
  curString = "";
  print(nnfRoot);  
  assert(curString == "()Rab");
}
