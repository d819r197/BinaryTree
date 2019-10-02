#include <iostream>

#include "BinaryTree.h"

//Constructor
BinaryTree::BinaryTree() {
  treeRoot = nullptr;
  treeSize = 0;
  treeHeight = 0;
}

//Class Functions
bool BinaryTree::RecAddItem(Node* root, char value) {
  if(value <= root->getValue() && root->getLeftChild() != nullptr) {
    RecAddItem(root->getLeftChild(), value);
  }
  else if(value > root->getValue() && root->getRightChild() != nullptr) {
    RecAddItem(root->getRightChild(), value);
  }
  else if(value <= root->getValue() && root->getLeftChild() == nullptr ) {
    Node* newNode = new Node(value);
    root->setLeftChild(newNode);
  }
  else if(value > root->getValue() && root->getRightChild() == nullptr ) {
    Node* newNode = new Node(value);
    root->setRightChild(newNode);
  }
  else {
    std::cout << "ERROR: Unexpected behavior occured in RecAddItem().\n";
  }

}

void BinaryTree::AddItem(char item) {
std::cout << "Adding item: " <<item <<" to the tree.\n";
  // Empty Tree
  if(treeRoot == nullptr) {
    std::cout << "Inserting at root.\n";
    Node* childNode = new Node(item);
    treeRoot = childNode;
  }
  else {
    RecAddItem(treeRoot, item);
  }
}

bool BinaryTree::RecDelete(Node* root, char value) {
    if(root->getValue() == value && root->getLeftChild() != nullptr) {
      std::cout << "FOUND VALUE: " <<value <<std::endl;
      Node* tempNode = root->getLeftChild();
      Node* lastNode = nullptr;
      while(tempNode->getRightChild() != nullptr) {
        lastNode = tempNode;
        tempNode = tempNode->getRightChild();
      }
      root->setValue(lastNode->getValue());
      lastNode->setRightChild(nullptr);
      delete tempNode;
      return(true);
    }
    else if(root->getValue() == value && root->getRightChild() != nullptr) {
      std::cout << "FOUND VALUE: " <<value <<std::endl;
      Node* tempNode = root->getRightChild();
      Node* lastNode = nullptr;
      while(tempNode->getLeftChild() != nullptr) {
        lastNode = tempNode;
        tempNode = tempNode->getLeftChild();
      }
      root->setValue(lastNode->getValue());
      lastNode->setLeftChild(nullptr);
      delete tempNode;
      return(true);
    }
    else if((root->getLeftChild())->getValue() == value && (root->getLeftChild())->getLeftChild() == nullptr && (root->getRightChild())->getRightChild() == nullptr) {
      Node* tempNode = root->getLeftChild();
      root->setLeftChild(nullptr);
      delete tempNode;
      return(true);
    }
    else if((root->getRightChild())->getValue() == value && (root->getLeftChild())->getLeftChild() == nullptr && (root->getRightChild())->getRightChild() == nullptr) {
      Node* tempNode = root->getRightChild();
      root->setRightChild(nullptr);
      delete tempNode;
      return(true);
    }
    else if(RecDelete(root->getLeftChild(), value)){
      return(true);
    }
    else if(RecDelete(root->getRightChild(), value)) {
      return(true);
    }
    else {
      // std::cout << "ERROR: Could not find item to be deleted in Binary Search Tree.\n";
      return(false);
    }
}

bool BinaryTree::Delete(char value) {
  if(treeRoot != nullptr) {
    return(RecDelete(treeRoot, value));
  }
  else {
    return(false);
  }
}



bool BinaryTree::RecIsLeaf(Node* root, char value) {
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

bool BinaryTree::IsLeaf(char value) {
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
  if(treeRoot != nullptr) {
    std::cout <<root->getValue() << ", ";
    if(root->getLeftChild() != nullptr) {
      RecPrintInorder(root->getLeftChild());
    }
    if(root->getRightChild() != nullptr) {
      RecPrintInorder(root->getRightChild());
    }
  }
}

void BinaryTree::RecPrintPostorder(Node* root) {
  if(treeRoot != nullptr) {
    if(root->getLeftChild() != nullptr) {
      RecPrintInorder(root->getLeftChild());
    }
    if(root->getRightChild() != nullptr) {
      RecPrintInorder(root->getRightChild());
    }
    std::cout <<root->getValue() << ", ";
  }
}

void BinaryTree::RecPrintInorder(Node* root) {
  if(treeRoot != nullptr) {
    if(root->getLeftChild() != nullptr) {
      RecPrintInorder(root->getLeftChild());
    }
    std::cout <<root->getValue() << ", ";
    if(root->getRightChild() != nullptr) {
      RecPrintInorder(root->getRightChild());
    }
  }
}

void BinaryTree::RecPrintLevelorder(Node* root) {
  if(treeRoot != nullptr) {
    std::cout << root->getValue() <<", ";
    RecPrintLevelorder(root->getLeftChild());
    RecPrintLevelorder(root->getRightChild());
  }
}

void BinaryTree::PrintPreorder() {
  std::cout << "Output: Printing the tree in Pre-Order: ";
  RecPrintPreorder(treeRoot);
  std::cout << std::endl;
}

void BinaryTree::PrintPostorder() {
  std::cout << "Output: Printing the tree in Post-Order: ";
  RecPrintPostorder(treeRoot);
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

bool BinaryTree::RecSearchElement(Node* root, char item) {

}

bool BinaryTree::SearchElement(char item) {
  RecSearchElement(treeRoot, item);
}
