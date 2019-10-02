#include <iostream>

#include "BinaryTree.h"

//Constructor
BinaryTree::BinaryTree() {
  treeRoot = nullptr;
  treeSize = 0;
  treeHeight = 0;
}

//Class Functions
bool BinaryTree::IsFull() {
  int numOfFullTreeNodes = 2;
  for(int lcv = 1; lcv < treeHeight + 1; lcv++) {
    numOfFullTreeNodes = numOfFullTreeNodes * 2;
  }
  numOfFullTreeNodes = numOfFullTreeNodes - 1;

  std::cout << "Nodes in tree: " <<treeSize <<", and Max Nodes for Tree of Height: " <<treeHeight <<" is: " <<numOfFullTreeNodes <<std::endl;
  if(treeSize == numOfFullTreeNodes) {
    return(true);
  }
  return(false);
}

bool BinaryTree::RecAddItem(Node* root, int level, int value) {

  // if(root->getLeftChild() == nullptr) {
  //   return(root);
  // }
  // else if(root->getRightChild() == nullptr) {
  //   return(root);
  // }
  // else if (root->getLeftChild() != nullptr && level < treeHeight){
  //   return(findNextLeaf(root->getRightChild(), level++));
  // }
  // else if (root->getRightChild() != nullptr){
  //   return(findNextLeaf(root->getLeftChild(), level++));
  // }
  // else {
  //   std::cout << "ERROR: recursive function findNextLeaf not working as expected\n";
  // }
  // std::cout << "L: " <<level << " H: " << treeHeight << std::endl;
  if(level > treeHeight) {
    return(false);
  }
  else if(root->getLeftChild() == nullptr) {
    Node* childNode = new Node(value);
    root->setLeftChild(childNode);
    treeSize++;
    return(true);
  }
  else if(root->getRightChild() == nullptr) {
    Node* childNode = new Node(value);
    root->setRightChild(childNode);
    treeSize++;
    return(true);
  }
  else if (RecAddItem(root->getLeftChild(), level++, value) && level < treeHeight){
    return(true);
  }
  else if (RecAddItem(root->getRightChild(), level++, value) && level < treeHeight){
    return(true);
  }
  else {
    std::cout << "ERROR: recursive function findNextLeaf not working as expected\n";
  }
}

void BinaryTree::AddItem(int item) {
  //Full Tree
  if(IsFull()) {
    std::cout <<"Full tree, adding new layer\n";
    treeHeight++;
  }
  // Empty Tree
  if(treeRoot == nullptr) {
    std::cout << "Inserting at root.\n";
    Node* childNode = new Node(item);
    treeRoot = childNode;
  }
  else {
    // IsFull();
    RecAddItem(treeRoot, 0, item);
  }
}

bool BinaryTree::RecDelete(Node* root, int value) {
  if(root->getValue() == value) {
    return(true);
  }
  else if(root->getLeftChild() == nullptr && root->getRightChild() == nullptr) {
    return(false);
  }
  else if(root->getLeftChild() != nullptr) {
    return(RecDelete(root->getRightChild(), value));
  }
  else if(root->getRightChild() == nullptr) {
    return(RecDelete(root->getLeftChild(), value));
  }
  else {
      std::cout << "ERROR: Rec delete entered an unexpected branch of recursion\n";
  }

  // //Only Active for Root Case
  // if(root->getValue() == value) {
  //
  // }
  // //All Other Cases
  // if((root->getLeftChild())->getValue() == value) {
  //   return(RecDelete(root->getRightChild(), value));
  // }
  // else if(root->getRightChild())->getValue() == value) {
  //   return(RecDelete(root->getLeftChild(), value));
  // }
  //
  // if(root->getValue() == value) {
  //   return(true);
  // }
  // if(root->getLeftChild() == nullptr && root->getRightChild() == nullptr) {
  //   return(false);
  // }
  // else if(root->getLeftChild() == nullptr) {
  //   return(RecDelete(root->getRightChild(), value));
  // }
  // else if(root->getRightChild() == nullptr) {
  //   return(RecDelete(root->getLeftChild(), value));
  // }
  // else {
  //     std::cout << "ERROR: Rec delete entered an unexpected branch of recursion\n";
  // }
}

bool BinaryTree::Delete(int value) {
  RecDelete(treeRoot, value);
}



bool BinaryTree::RecIsLeaf(Node* root, int value) {
  if(root->getValue() == value) {
    if(root->getLeftChild() == nullptr && root->getRightChild() == nullptr) {
      return(true);
    }
    return(false);
  }
  if(root->getLeftChild() != nullptr) {
    return(RecIsLeaf(root->getLeftChild(), value));
  }
  if(root->getRightChild() != nullptr) {
    return(RecIsLeaf(root->getRightChild(), value));
  }
return(false);
}

bool BinaryTree::IsLeaf(int value) {
  RecIsLeaf(treeRoot, value);
}

void BinaryTree::RecPrintLeaves(Node* root) {
  if(root->getLeftChild() == nullptr && root->getRightChild() == nullptr) {
    std::cout << "[ " <<root->getValue() <<" ] ";
  }
  if(root->getLeftChild() != nullptr) {
    RecPrintLeaves(root->getLeftChild());
  }
  if(root->getRightChild() != nullptr) {
    RecPrintLeaves(root->getRightChild());
  }
}

void BinaryTree::PrintLeaves() {
  RecPrintLeaves(treeRoot);
  std::cout << std::endl;
}

void BinaryTree::PrintTreeHeight() {
  std::cout << "Output: The height of the tree is " <<treeHeight <<".\n";
}

void BinaryTree::RecPrintPreorder(Node* root) {
  std::cout <<root->getValue() << ", ";
  if(root->getLeftChild() != nullptr) {
    RecPrintInorder(root->getLeftChild());
  }
  if(root->getRightChild() != nullptr) {
    RecPrintInorder(root->getRightChild());
  }
}

void BinaryTree::RecPrintPostorder(Node* root) {
  if(root->getLeftChild() != nullptr) {
    RecPrintInorder(root->getLeftChild());
  }
  if(root->getRightChild() != nullptr) {
    RecPrintInorder(root->getRightChild());
  }
  std::cout <<root->getValue() << ", ";
}

void BinaryTree::RecPrintInorder(Node* root) {
  if(root->getLeftChild() != nullptr) {
    RecPrintInorder(root->getLeftChild());
  }
  std::cout <<root->getValue() << ", ";
  if(root->getRightChild() != nullptr) {
    RecPrintInorder(root->getRightChild());
  }
}

void BinaryTree::RecPrintLevelorder(Node* root) {
  if(root != nullptr) {
    std::cout << root->getValue() <<", ";
    RecPrintLevelorder(root->getLeftChild());
    RecPrintLevelorder(root->getRightChild());
  }
}

void BinaryTree::PrintPreorder() {
  std::cout << "Output: Printing the tree in Pre-Order: ";
  RecPrintInorder(treeRoot);
  std::cout << std::endl;
}

void BinaryTree::PrintPostorder() {
  std::cout << "Output: Printing the tree in Post-Order: ";
  RecPrintInorder(treeRoot);
  std::cout << std::endl;
}

void BinaryTree::PrintInorder() {
  std::cout << "Output: Printing the tree in In-Order: ";
  RecPrintInorder(treeRoot);
  std::cout << std::endl;
}

void BinaryTree::PrintLevelorder() {
  std::cout << "Output: Printing the tree in Level-Order: ";
  RecPrintLevelorder(treeRoot);
  std::cout << std::endl;
}
