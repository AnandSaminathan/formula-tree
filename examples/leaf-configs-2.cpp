#include <iostream>
#include "formula-tree/formula-tree.h"

void traverse(FormulaNode cur) {
  if(cur.isVal()) {
    assert(cur.getContentType() == "bool");
  }
  int count = cur.getChildrenCount();
  for(int i = 0; i < count; ++i) {
    traverse(cur.getChild(i));
  }
}

int main() {
  FormulaTree tree("x == true && y == false && z == false");
  FormulaNode root = tree.getRoot();
  traverse(root);
}
