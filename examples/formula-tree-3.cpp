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
  std::string t1 = "(a && b)";
  std::string t2 = "(b && c)";
  std::string t3 = "(c && a)";
  std::string t4 = "(b && a)";
  std::string t5 = "(a && c)";
  std::string pseudoBoolean = t1 + " + " + t2 + " - 3 * " + t3 + " + 4 * " + t4 + " - " + t5 + " <= 2";
  FormulaTree tree(pseudoBoolean);
  FormulaNode root = tree.getRoot();
  print(root);
  assert(content == "<=-+-+()&&ab()&&bc*3()&&ca*4()&&ba()&&ac2");
  assert(root.getSubTreeType() == pb);
}
