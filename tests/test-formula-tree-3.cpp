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
  std::string t1 = "(a == true && b == true)";
  std::string t2 = "((c == true) -> (d == false))";
  std::string pseudoBoolean = t1 + " + " + t2 + " == 1"; 
  FormulaTree tree(pseudoBoolean);
  FormulaNode root = tree.getRoot();
  print(root);
  assert(content == "==+()&&==atrue==btrue()->()==ctrue()==dfalse1");
  assert(root.getSubTreeType() == pb);
}
