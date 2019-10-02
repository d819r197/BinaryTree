#include <iostream>

#include "Node.h"

//Constructor
Node::Node() {
  value = '\0';
  leftChild = nullptr;
  rightChild = nullptr;
}

Node::Node(char val) {
  value = val;
  leftChild = nullptr;
  rightChild = nullptr;
}

//Helper Functions
void Node::setValue(char v) {
  value = v;
}

void Node::setLeftChild(Node* child) {
  leftChild = child;
}

void Node::setRightChild(Node* child) {
  rightChild = child;
}


char Node::getValue() {
  return(value);
}

Node* Node::getLeftChild() {
  return(leftChild);
}

Node* Node::getRightChild() {
  return(rightChild);
}
