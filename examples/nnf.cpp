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
  FormulaTree tree("!G((a == true && b == false && c == false) || (a == false && b == true && c == false) || (a == false && b == false && c == true))");
  FormulaNode root = tree.getRoot();
  print(root);
  
  tree.makeNNF();
  FormulaNode nnfRoot = tree.getNNFRoot();
  curString = "";
  print(nnfRoot);
  assert(curString == "F()&&&&()||||!=atrue!=bfalse!=cfalse()||||!=afalse!=btrue!=cfalse()||||!=afalse!=bfalse!=ctrue");
}
