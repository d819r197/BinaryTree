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

  std::cout << "1. AddItem \n";
  std::cout << "2. Delete \n";
  std::cout << "3. Leaf \n";
  std::cout << "4. PrintLeaf \n";
  std::cout << "5. PrintTreeHeight \n";
  std::cout << "6. Preorder \n";
  std::cout << "7. Postorder \n";
  std::cout << "8. Inorder \n";
  std::cout << "9. Levelorder \n";
  std::cout << "10. SearchItem \n";
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
          char input;
          std::cout << "Please enter the value which you want to enter into the tree: ";
          std::cin >> input;
          tree->AddItem(input);
          break;
      }
      //Delete
      case 2: {
        char input;
        std::cout << "Enter the character to be deleted: ";
        std::cin >> input;
        std::cout << std::endl;
        std::cout << "Output: ";
        if(tree->Delete(input)) {
          std::cout << "Deletion was successful.\n";
        }
        else {
          std::cout << "Deletion failed. The character is not present in the tree.\n";
        }
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
        std::cout << "Output: "
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
        char input;
        std::cout << "Please enter the value which you want to searcy in the tree: ";
        std::cin >> input;
        std::cout << std::endl;
        std::cout << "The value: " <<input <<" was ";
          if(tree->SearchElement(input)){
            std::cout <<"found in the tree.\n";
          }
          else {
            std::cout <<"not found in the tree.\n";
          }
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
          break;
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
    }
    inputFile.close();
    return(true);
  }
  else {
    std::cout << "File Path: " <<filePath <<" is an invalid path.\n";
    return(false);
  }
}
