#include <iostream>

#include "Node.h"

//Constructor
Node::Node() {
  value = 0;
  leftChild = nullptr;
  rightChild = nullptr;
}

Node::Node(int val) {
  value = val;
  leftChild = nullptr;
  rightChild = nullptr;
}

Node::Node(int value, Node* lChild, Node* rChild) {
  value = value;
  leftChild = lChild;
  rightChild = rChild;
}

//Helper Functions
void Node::setValue(int v) {
  value = v;
}

void Node::setLeftChild(Node* child) {
  leftChild = child;
}

void Node::setRightChild(Node* child) {
  rightChild = child;
}


int Node::getValue() {
  return(value);
}

Node* Node::getLeftChild() {
  return(leftChild);
}

Node* Node::getRightChild() {
  return(rightChild);
}
