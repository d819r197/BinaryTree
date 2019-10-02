#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

class Node {
  public:
    //Constructor
    Node();
    Node(char value);

    //Helper Functions
    void setValue(char value);
    void setLeftChild(Node* child);
    void setRightChild(Node* child);

    char getValue();
    Node* getLeftChild();
    Node* getRightChild();

  private:
    char value;
    Node* leftChild;
    Node* rightChild;
};

#endif
