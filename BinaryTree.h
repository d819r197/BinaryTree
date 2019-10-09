#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

#include "Node.h"

class BinaryTree {
  public:
    //Constructor
    BinaryTree();

    //Class Functions
    void RecAddItem(Node* root, char value);
    void AddItem(char item);

    bool RecDelete(Node* root, char value);
    bool Delete(char value);

    bool RecIsLeaf(Node* root, char value);
    bool IsLeaf(char value);

    void RecPrintLeaves(Node* root);
    void PrintLeaves();

    int getTreeHeight(Node* root, int treeHeight);
    void PrintTreeHeight();

    void RecPrintPreorder(Node* root);
    void RecPrintPostorder(Node* root);
    void RecPrintInorder(Node* root);
    void RecPrintLevelorder(Node* root);

    void PrintPreorder();
    void PrintPostorder();
    void PrintInorder();
    void PrintLevelorder();

    bool RecSearchElement(Node* root, char item);
    bool SearchElement(char item);

  private:
    Node* treeRoot;
    int treeSize;
    int treeHeight;
};

#endif
