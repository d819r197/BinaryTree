#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

#include "Node.h"

class BinaryTree {
  public:
    //Constructor
    BinaryTree();

    //Class Functions
    bool IsFull();
    void RecAddItem(Node* root, int level, int value);
    void AddItem(int item);

    bool RecDelete(Node* root, int value);
    bool Delete(int value);

    bool RecIsLeaf(Node* root, int value);
    bool IsLeaf(int value);

    void RecPrintLeaves(Node* root);
    void PrintLeaves();

    void PrintTreeHeight();

    void RecPrintPreorder(Node* root);
    void RecPrintPostorder(Node* root);
    void RecPrintInorder(Node* root);
    void RecPrintLevelorder(Node* root);

    void PrintPreorder();
    void PrintPostorder();
    void PrintInorder();
    void PrintLevelorder();


  private:
    Node* treeRoot;
    int treeSize;
    int treeHeight;
};

#endif
