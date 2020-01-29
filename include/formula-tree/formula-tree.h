#pragma once

#include <string>
#include <vector>
#include <assert.h>

class FormulaNode {
  public:
    FormulaNode(std::string content, int childrenCount) {
      this->content = content;
      this->childrenCount = childrenCount;

      children.resize(childrenCount);
    }

    bool isLeaf() { return (childrenCount == 0); }

    std::string getContent() { return content; }
    std::string getContentType() { return contentType; }

    int getChildrenCount() { return childrenCount; }
    FormulaNode getChild(int child) { assertChild(child); return (*children[child]); }
    
    void setType(std::string type) { contentType = type; }
    void setChild(int child, FormulaNode *node) { assertChild(child); children[child] = node; }

  private:
    int childrenCount;
    std::string content;
    std::string contentType;
    std::vector<FormulaNode*> children;

    void assertChild(int child) { assert(child >= 0 && child < childrenCount); }
};


class FormulaTree {
  public:
    FormulaTree(std::string formula) {
      this->formula = formula;
    }

    std::string getFormula() { return formula; }
    FormulaNode getRoot() { return (*root); }

  private:
    FormulaNode *root;
    std::string formula;
};


