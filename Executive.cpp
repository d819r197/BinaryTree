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

  std::cout << "1. IsFull \n";
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
      //IsFull
      case 1: {
          std::cout << "IsFull Result: ";
          if(tree->IsFull()) {
            std::cout << "True\n";
          }
          else {
            std::cout << "False\n";
          }
          break;
      }
      //Add Iteml
      case 2: {
          int input;
          std::cout << "Please enter the value which you want to enter into the tree: ";
          std::cin >> input;
          tree->AddItem(input);
          break;
      }
      //Delete
      case 3: {

        break;
      }
      //Leaf
      case 4: {
        int input;
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
      case 5: {
        tree->PrintLeaves();
        break;
      }
      //Print Tree Height
      case 6: {

          break;
      }
      //Preorder
      case 7: {

          break;
      }
      //Postorder
      case 8: {

          break;
      }
      //Inorder
      case 9: {
          tree->PrintInorder();
          break;
      }
      //Levelorder
      case 10: {

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
          std::cout << "Please input a number between 1 and 5.\n\n";
      }
    }
  }
}

/*
void Executive::parseNewInput(std::string input) {
  std::string strInt = "";
  int cellNum = 0;

  std::string name, priceRange;
  int rating;

  for(int lcv = 0; lcv < input.length(); lcv++) {
    char c = input[lcv];
    if(c == ' ') {
      //do nothing
    }
    else if (c != ',' && c != '\n') {
      strInt += c;
    }
    else if(c == ',') {
      if(cellNum == 0) {
        name = strInt;
      }
      else if(cellNum == 1) {
        rating = std::stoi(strInt);
      }
      else {
        std::cout << "ERROR: Trying to place data in unknown spot of Restaurant struct\n";
      }
      strInt = "";
      cellNum++;
    }
    else if(c == '\n') {
      //Do nothing till below
    }
    else {
      strInt = "";
    }
  }
    priceRange = strInt;
    std::cout <<"inserting node with values name: " <<name <<", rating: " <<rating <<", and price range: " <<priceRange <<std::endl;

    if(qHash->Insert(name, priceRange, rating)){
      if(dHash->Insert(name, priceRange, rating)){
        std::cout << "Insertion Status: Success/Success\n";
      }
      else {
        std::cout << "Insertion Status: Success/Failure\n";
      }
    }
    else {
      if(dHash->Insert(name, priceRange, rating)){
        std::cout << "Insertion Status: Failure/Success\n";
      }
      else {
        std::cout << "Insertion Status: Failure/Failure\n";
      }
    }

    strInt = "";
    name = "";
    priceRange = "";
    rating = 0;
    cellNum = 0;
}
*/

bool Executive::parseInputFile() {
  std::ifstream inputFile(filePath);
  std::string strInt = "";

  char c;
  if (inputFile.is_open()) {
    while(inputFile.get(c)) {
      if (c != ' ' && c != '\n') {
        strInt += c;
      }
      else if(c == ' ' || c == '\n') {
        tree->AddItem(std::stoi(strInt));
        strInt = "";
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
