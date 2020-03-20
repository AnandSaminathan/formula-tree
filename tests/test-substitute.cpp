#include <iostream>
#include "formula-tree/formula-tree.h"

void print(FormulaNode cur) {
  std::cout << cur.getContent();
  for(int i = 0; i < cur.getChildrenCount(); ++i) {
    print(cur.getChild(i));
  }
}

int main() {
  FormulaTree tree("G(t1)");
  FormulaNode root = tree.getRoot(); 
  print(root);
  std::cout << '\n';
  std::map<std::string, std::string> mapper;
  mapper["t1"] = "(a > 2) && (next_a == 2 && next_ b == 1)";
  tree.substitute(mapper);
  print(tree.getRoot());
  std::cout << '\n';
}
