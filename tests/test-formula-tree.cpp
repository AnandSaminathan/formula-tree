#include "formula-tree/formula-tree.h"
#include "catch.hpp"

std::string content = "";

void print(FormulaNode cur) {
  content += cur.getContent();
  for(int i = 0; i < cur.getChildrenCount(); ++i) {
    print(cur.getChild(i));
  }
}

TEST_CASE("formula tree structure", "[formula-tree]") {
  SECTION("ltl formula") {
    FormulaTree tree("G((x >= 10) -> y)");
    FormulaNode root = tree.getRoot();
    content = "";
    print(root);
    REQUIRE(content == "G()->()>=x10y");
    REQUIRE(root.getSubTreeType() == ltl);
  } 

  SECTION("pl formula") {
    std::string p1 = "(a == true && b == true)";
    FormulaTree tree(p1);
    FormulaNode root = tree.getRoot();
    content = "";
    print(root);
    REQUIRE(content == "()&&==atrue==btrue");
    REQUIRE(root.getSubTreeType() == pl);
  }

  SECTION("pb formula") {
    std::string t1 = "(a && b)";
    std::string t2 = "(b && c)";
    std::string t3 = "(c && a)";
    std::string t4 = "(b && a)";
    std::string t5 = "(a && c)";
    std::string pseudoBoolean = t1 + " + " + t2 + " - 3 * " + t3 + " + 4 * " + t4 + " - " + t5 + " <= 2";
    FormulaTree tree(pseudoBoolean);
    FormulaNode root = tree.getRoot();
    content = "";
    print(root);
    REQUIRE(content == "<=-+-+()&&ab()&&bc*3()&&ca*4()&&ba()&&ac2");
    REQUIRE(root.getSubTreeType() == pb);
  }
}

TEST_CASE("negation normal form", "[nnf]") {
  SECTION("example 1") {

    FormulaTree tree("!G((a == true && b == false && c == false) || (a == false && b == true && c == false) || (a == false && b == false && c == true))");
    FormulaNode root = tree.getRoot();
    print(root);
    
    tree.makeNNF();
    FormulaNode nnfRoot = tree.getNNFRoot();
    content = "";
    print(nnfRoot);
    REQUIRE(content == "F()&&&&()||||!=atrue!=bfalse!=cfalse()||||!=afalse!=btrue!=cfalse()||||!=afalse!=bfalse!=ctrue");
  }

  SECTION("example 2") {

    FormulaTree tree("!G((p3 == 0) -> (p2 == 1 && p5 == 1))");
    FormulaTree tree2("!G(next_p1 == p1 - 2)");
    FormulaNode root = tree.getRoot();
    FormulaNode root2 = tree2.getRoot();
    print(root);
    print(root2);
    
    tree.makeNNF();
    tree2.makeNNF();
    FormulaNode nnfRoot = tree.getNNFRoot();
    FormulaNode nnfRoot2 = tree2.getNNFRoot();
    content = "";
    print(nnfRoot);
    REQUIRE(content == "F()&&()==p30()||!=p21!=p51");
    content = "";
    print(nnfRoot2);
    REQUIRE(content == "F()!=next_p1-p12");
  }

  SECTION("example 3") {

    FormulaTree tree("!(a U b)");
    FormulaNode root = tree.getRoot();
    print(root);
    
    tree.makeNNF();
    FormulaNode nnfRoot = tree.getNNFRoot();
    content = "";
    print(nnfRoot);  
    REQUIRE(content == "()Rab");
  }
}
