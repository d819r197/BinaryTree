#include <iostream>

#include "BinaryTree.h"

//Constructor
BinaryTree::BinaryTree() {
  treeRoot = nullptr;
  treeSize = 0;
  treeHeight = 0;
}

//Class Functions
void BinaryTree::RecAddItem(Node* root, char value) {
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
// std::cout << "Adding item: " <<item <<" to the tree.\n";
  // Empty Tree
  if(treeRoot == nullptr) {
    // std::cout << "Inserting at root.\n";
    Node* childNode = new Node(item);
    treeRoot = childNode;
  }
  else {
    RecAddItem(treeRoot, item);
  }
  std::cout << "Output: the element was inserted successfully"
}

bool BinaryTree::RecDelete(Node* root, char value) {
  if(root != nullptr) {
    // std::cout << "Comparing item: " <<root->getValue() <<" with: " <<value <<std::endl;
    if(root->getValue() == value && root->getLeftChild() != nullptr) {
      // std::cout << "Value found: " <<root->getValue() <<" with a valid left child.\n";
      Node* tempNode = root->getLeftChild();
      Node* lastNode = tempNode;
      while(tempNode->getRightChild() != nullptr) {
        lastNode = tempNode;
        tempNode = tempNode->getRightChild();
      }
      root->setValue(lastNode->getValue());

      if(lastNode == tempNode) {
        root->setLeftChild(nullptr);
        delete lastNode;
      }
      else {
        lastNode->setRightChild(nullptr);
        delete tempNode;
      }
      return(true);
    }
    else if(root->getValue() == value && root->getRightChild() != nullptr) {
      // std::cout << "Value found: " <<root->getValue() <<" with a valid right child.\n";
      Node* tempNode = root->getRightChild();
      Node* lastNode = tempNode;
      while(tempNode->getLeftChild() != nullptr) {
        lastNode = tempNode;
        tempNode = tempNode->getLeftChild();
      }
      root->setValue(lastNode->getValue());

      if(lastNode == tempNode) {
        root->setRightChild(nullptr);
      }
      else {
        lastNode->setLeftChild(nullptr);
      }
      delete tempNode;
      return(true);
    }
    else if(root->getLeftChild() != nullptr) {
      // std::cout << "Value: " <<root->getValue() <<" has a valid left child.\n";
      if((root->getLeftChild())->getValue() == value) {
        // std::cout << "Value found: " <<(root->getLeftChild())->getValue() <<".\n";
        Node* tempNode = root->getLeftChild();
        if(tempNode->getLeftChild() == nullptr) {
          root->setLeftChild(nullptr);
        }
        else {
          root->setLeftChild(tempNode->getLeftChild());
        }
        delete tempNode;
        return(true);
      }
    }
    else if(root->getRightChild() != nullptr) {
      // std::cout << "Value: " <<root->getValue() <<" has a valid right child.\n";
      if((root->getRightChild())->getValue() == value) {
        // std::cout << "Value found: " <<(root->getRightChild())->getValue() <<".\n";
        Node* tempNode = root->getRightChild();
        if(tempNode->getRightChild() == nullptr) {
          root->setRightChild(nullptr);
        }
        else {
          root->setRightChild(tempNode->getRightChild());
        }
        delete tempNode;
        return(true);
      }
    }
    if(RecDelete(root->getLeftChild(), value)) {
      return(true);
    }
    if(RecDelete(root->getRightChild(), value)) {
      return(true);
    }
    return(false);
  }
}

bool BinaryTree::Delete(char value) {
  if(treeRoot != nullptr) {
    if(treeRoot->getValue() == value && treeRoot->getLeftChild() == nullptr && treeRoot->getRightChild() == nullptr) {
      Node* tempNode = treeRoot;
      treeRoot = nullptr;
      delete tempNode;
    }
    else {
      return(RecDelete(treeRoot, value));
    }
  }
  else {
    return(false);
  }
}

bool BinaryTree::RecIsLeaf(Node* root, char value) {
  if(root->getValue() == value && root->getLeftChild() == nullptr && root->getRightChild() == nullptr) {
    return(true);
  }
  if(value <= root->getValue() && root->getLeftChild() != nullptr) {
    return(RecIsLeaf(root->getLeftChild(), value));
  }
  else if(value > root->getValue() && root->getRightChild() != nullptr) {
    return(RecIsLeaf(root->getRightChild(), value));
  }
  else {
    return(false);
  }
}

bool BinaryTree::IsLeaf(char value) {
  if(treeRoot != nullptr) {
    return(RecIsLeaf(treeRoot, value));
  }
  else {
    return(false);
  }
}

void BinaryTree::RecPrintLeaves(Node* root) {
  if(root->getLeftChild() == nullptr && root->getRightChild() == nullptr) {
    std::cout <<root->getValue() <<"" ";
  }
  if(root->getLeftChild() != nullptr) {
    RecPrintLeaves(root->getLeftChild());
  }
  if(root->getRightChild() != nullptr) {
    RecPrintLeaves(root->getRightChild());
  }
}

void BinaryTree::PrintLeaves() {
  std::cout << "The leaves are: ";
  RecPrintLeaves(treeRoot);
  std::cout << std::endl;
}

int BinaryTree::getTreeHeight(Node* root, int currentHeight) {
  if(root->getLeftChild() != nullptr && root->getRightChild() != nullptr) {
    currentHeight++;
    int left = getTreeHeight(root->getLeftChild(), currentHeight);
    int right = getTreeHeight(root->getRightChild(), currentHeight);
    // std::cout << "Comparing heights of: " <<left << " and " <<right <<". \n";
    if(left > right) {
      return(left);
    }
    return(right);
  }
  else if(root->getLeftChild() != nullptr) {
    // std::cout << "Found left subtree of: " <<root->getValue() <<" with currentHeight: " <<currentHeight <<". \n";
    currentHeight++;
    return(getTreeHeight(root->getLeftChild(), currentHeight));
  }
  else if(root->getRightChild() != nullptr) {
    // std::cout << "Found right subtree of: " <<root->getValue() <<" with currentHeight: " <<currentHeight <<". \n";
    currentHeight++;
    return(getTreeHeight(root->getRightChild(), currentHeight));
  }
  else if(root->getLeftChild() == nullptr && root->getRightChild() == nullptr) {
    // std::cout << "No sub tree of: " <<root->getValue() <<". Returning currentHeight: " <<currentHeight <<". \n";
    return(currentHeight);
  }
  else {
    std::cout << "Hit an Unexpected route in getTreeHeight.\n";
  }
}

void BinaryTree::PrintTreeHeight() {
  std::cout << "Output: The height of the tree is " <<getTreeHeight(treeRoot, 0) <<".\n";
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
    if(root->getLeftChild() != nullptr) {
      RecPrintLevelorder(root->getLeftChild());
    }
    if(root->getRightChild() != nullptr) {
      RecPrintLevelorder(root->getRightChild());
    }
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
  if(root->getValue() == item) {
    return(true);
  }
  if(item <= root->getValue() && root->getLeftChild() != nullptr) {
    return(RecSearchElement(root->getLeftChild(), item));
  }
  else if(item > root->getValue() && root->getRightChild() != nullptr) {
    return(RecSearchElement(root->getRightChild(), item));
  }
  else {
    return(false);
  }
}

bool BinaryTree::SearchElement(char item) {
  if(treeRoot != nullptr) {
    return(RecSearchElement(treeRoot, item));
  }
  else {
    return(false);
  }
}
