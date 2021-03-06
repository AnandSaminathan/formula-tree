#pragma once
#pragma GCC optimize("unroll-loops")

#include <string>
#include <map>
#include <memory>
#include <algorithm>

#include "formula-tree/formula-type.hpp"

namespace ftree {
  class FormulaNode {
    public:
  
      FormulaNode(std::string content, std::shared_ptr<std::shared_ptr<FormulaNode>[]>& children, int childrenCount)
      : content(content),
        children(children),
        childrenCount(childrenCount) { }
  
      FormulaNode(const FormulaNode& other) {
        (*this) = other;
      }
  
      inline bool isLeaf() { return (childrenCount == 0); }
      inline bool isVar() { return isLeaf() && !val; }
      inline bool isVal() { return isLeaf() && val; }
  
      inline std::string getContent() { return content; }
      inline std::string getContentType() { return contentType; }
      inline formulaType getSubTreeType() { return subTreeType;  }
  
      inline int getChildrenCount() { return childrenCount; }
      FormulaNode getChild(int); 
      std::shared_ptr<FormulaNode> getPointerToChild(int); 
      
      inline void setType(std::string type) { contentType = type; }
      inline void setSubTreeType(formulaType type) { subTreeType = type;  }
      inline void setContent(std::string content) { this->content = content; }
      inline void toggleVal() { val = true; }
  
    private:
      
      formulaType subTreeType;
      bool val{false};
      int childrenCount;
      std::string content;
      std::string contentType;
      std::shared_ptr<std::shared_ptr<FormulaNode>[]> children;
  
      inline void assertChild(int child) { 
        if(!(child >= 0 && child < childrenCount)) {
          throw std::out_of_range("child " + std::to_string(child) + " is not between 0 and " + std::to_string(childrenCount - 1));
        }
      }
  };
  
  
  class FormulaTree {
    public:
  
      FormulaTree(std::string formula)
      : formula(formula) {
        this->constructTree();
      }
  
      inline void makeNNF() { constructNNF(); }
  
      inline std::string getFormula() { return toString((*root)); }
      inline FormulaNode getRoot() { return (*root); }
      inline std::shared_ptr<FormulaNode> getPointerToRoot() { return (root); }
      inline FormulaNode getNNFRoot() { return (*nnfRoot); }
      void substitute(std::map<std::string, std::string>&);
  
    private:
    
      std::shared_ptr<FormulaNode> root;
      std::shared_ptr<FormulaNode> nnfRoot;
      std::string formula;
      void constructTree();
      void constructNNF();
      std::string toString(FormulaNode);
  };
}
