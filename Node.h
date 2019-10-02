#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

class Node {
  public:
    //Constructor
    Node();
    Node(int value);
    Node(int value, Node* leftChild, Node* rightChild);

    //Helper Functions
    void setValue(int value);
    void setLeftChild(Node* child);
    void setRightChild(Node* child);

    int getValue();
    Node* getLeftChild();
    Node* getRightChild();

  private:
    int value;
    Node* leftChild;
    Node* rightChild;
};

#endif
