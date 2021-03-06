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
  FormulaTree tree("G((x >= 10) -> y)");
  FormulaNode root = tree.getRoot();
  print(root);
  assert(content == "G()->()>=x10y");
  assert(root.getSubTreeType() == ltl);
}
