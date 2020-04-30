#include <iostream>
#include "formula-tree/formula-tree.h"

std::string content = "";

void print(FormulaNode cur) {
  content += cur.getContent();
  for(int i = 0; i < cur.getChildrenCount(); ++i) {
    print(cur.getChild(i));
  }
}

int main() {
  std::string p1 = "(a == true && b == true)";
  FormulaTree tree(p1);
  FormulaNode root = tree.getRoot();
  print(root);
  assert(content == "()&&==atrue==btrue");
  assert(root.getSubTreeType() == pl);
}
