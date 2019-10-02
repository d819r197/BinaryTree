#include <iostream>
#include <string>
#include <fstream>

#include "Executive.h"

Executive::Executive(std::string path) {
  filePath = path;
  tree = new BinaryTree;
}

int Executive::menuInput() {
  int choice;

  std::cout << "1.  \n";
  std::cout << "2. AddItem \n";
  std::cout << "3. Delete \n";
  std::cout << "4. Leaf \n";
  std::cout << "5. PrintLeaf \n";
  std::cout << "6. PrintTreeHeight \n";
  std::cout << "7. Preorder \n";
  std::cout << "8. Postorder \n";
  std::cout << "9. Inorder \n";
  std::cout << "10. Levelorder \n";
  std::cout << "11. Exit \n";

  std::cout << ">> ";
  std::cin >> choice;
  std::cout << std::endl;

  return(choice);
}

void Executive::run() {
  bool quit = false;
  while(!quit) {
    switch (menuInput()) {
      //Add Iteml
      case 1: {
          int input;
          std::cout << "Please enter the value which you want to enter into the tree: ";
          std::cin >> input;
          tree->AddItem(input);
          break;
      }
      //Delete
      case 2: {

        break;
      }
      //Leaf
      case 3: {
        char input;
        std::cout << "Please enter the value which you want to test as a leaf node: ";
        std::cin >> input;
        std::cout << std::endl;
        std::cout << "The Node with " << input <<" is ";
        if(tree->IsLeaf(input)) {
          std::cout << "a leaf node.\n";
        }
        else {
          std::cout << "not a leaf node.\n";
        }
        break;
      }
      //Print Leaf
      case 4: {
        tree->PrintLeaves();
        break;
      }
      //Print Tree Height
      case 5: {
          tree->PrintTreeHeight();
          break;
      }
      //Preorder
      case 6: {
          tree->PrintPreorder();
          break;
      }
      //Postorder
      case 7: {
          tree->PrintPostorder();
          break;
      }
      //Inorder
      case 8: {
          tree->PrintInorder();
          break;
      }
      //Levelorder
      case 9: {
          tree->PrintLevelorder();
          break;
      }
      //SearchElement
      case 10: {
          //tree->SearchElement();
          break;
      }
      //Quit
      case 11: {
        delete tree;
        quit = true;
        break;
      }
      //Invalid Input
      default: {
          std::cout << "Please input a number between 1 and 11.\n\n";
      }
    }
  }
}

bool Executive::parseInputFile() {
  std::ifstream inputFile(filePath);

  char c;
  if (inputFile.is_open()) {
    while(inputFile.get(c)) {
      if (c != ' ' && c != '\n') {
        tree->AddItem(c);
      }
      else {
        std::cout <<"ERROR: Can't parse input file, confusion about char: " <<c <<std::endl;
      }
    }
    inputFile.close();
    return(true);
  }
  else {
    std::cout << "File Path: " <<filePath <<" is an invalid path.\n";
    return(false);
  }
}
