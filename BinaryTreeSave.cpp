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

void BinaryTree::RecAddItem(Node* root, int level, int value) {

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


  // Empty Tree
  if(root == nullptr) {
    std::cout << "Inserting at root.\n";
    Node* childNode = new Node(value);
    treeRoot = childNode;
    treeSize++;
  }
  //Full Tree
  else if(IsFull()) {
    std::cout <<"Full tree, adding new layer\n";
    Node* childNode = new Node(value);
    while(root->getLeftChild() != nullptr) {
      root = root->getLeftChild();
    }
    //Farmost left node
    root->setLeftChild(childNode);
    treeSize++;
    treeHeight++;
  }
  else if(root->getLeftChild() == nullptr) {
    Node* childNode = new Node(value);
    root->setLeftChild(childNode);
    treeSize++;
  }
  else if(root->getRightChild() == nullptr) {
    Node* childNode = new Node(value);
    root->setRightChild(childNode);
    treeSize++;
  }
  else if (level < treeHeight){
    RecAddItem(root->getLeftChild(), level++, value);
    RecAddItem(root->getRightChild(), level++, value);
  }
  else {
    std::cout << "ERROR: recursive function findNextLeaf not working as expected\n";
  }
}

void BinaryTree::AddItem(int item) {
  RecAddItem(treeRoot, 0, item);
  // treeSize++;

  // Node* newNode = new Node(item);
  // Node* tempNode = root;
  //
  // //Empty Tree
  // if(root == nullptr) {
  //   std::cout << "Inserting at root.\n";
  //   root = newNode;
  //   treeSize++;
  //   return(true);
  // }
  // //Full Tree
  // else if(IsFull()) {
  //   std::cout <<"Full tree, adding new layer\n";
  //   while(tempNode->getLeftChild() != nullptr) {
  //     tempNode = tempNode->getLeftChild();
  //   }
  //   //Farmost left node
  //   tempNode->setLeftChild(newNode);
  //   treeSize++;
  //   treeHeight++;
  //   return(true);
  // }
  // //All other cases
  // else {
  //   tempNode = RecAddItem(tempNode, 0, item);
  //   // tempNode->setLeftChild(newNode);
  //   treeSize++;
  //   return(true);
  // }
  // else if(tempNode ->getLeftChild() == nullptr || tempNode->getRightChild() == nullptr){
  //   std::cout <<"Non-Full tree, adding new node normally.\n";
  //
  // }
  // else {
  //   std::cout << "ERROR: cant find child branch to insert node with value: " <<item <<" into.\n";
  // }
}

bool BinaryTree::RecDelete(Node* root, int value) {
  if(root->getValue() == value) {
    return(true);
  }
  else if(root->getLeftChild() == nullptr && root->getRightChild() == nullptr) {
    return(false);
  }
  else if(root->getLeftChild() == nullptr) {
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

}

void BinaryTree::RecPrintPostorder(Node* root) {

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

}

void BinaryTree::PrintPreorder() {

}

void BinaryTree::PrintPostorder() {

}

void BinaryTree::PrintInorder() {
  std::cout << "Output: Printing the tree in In-Order: ";
  RecPrintInorder(treeRoot);
  std::cout << std::endl;
}

void BinaryTree::PrintLevelorder() {

}
