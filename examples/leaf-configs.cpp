#include <iostream>
#include "formula-tree/formula-tree.h"

void traverse(FormulaNode cur) {
  if(cur.isVal()) {
    if(cur.getContent() == "10") { assert(cur.getContentType() == "int"); } 
    else if(cur.getContent() == "12.23") { assert(cur.getContentType() == "real"); }
    else { assert(false); }
  }
  int count = cur.getChildrenCount();
  for(int i = 0; i < count; ++i) {
    traverse(cur.getChild(i));
  }
}

int main() {
  FormulaTree tree("G((x >= 10) -> (y < 12.23))");
  FormulaNode root = tree.getRoot();
  traverse(root);
}
