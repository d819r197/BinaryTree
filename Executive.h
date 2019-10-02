#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>

#include "BinaryTree.h"

class Executive {
  public:
    Executive(std::string path);

    int menuInput();
    void run();
    // void parseNewInput(std::string input);
    bool parseInputFile();

  private:
    std::string filePath;
    BinaryTree* tree;

};

#endif
