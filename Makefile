BinaryTree: main.o Executive.o BinaryTree.o Node.o
	g++ -g -std=c++11 main.o Executive.o BinaryTree.o Node.o -o BinaryTree

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -c main.cpp

Executive.o: Executive.h Executive.cpp BinaryTree.h
	g++ -std=c++11 -g -c Executive.cpp

BinaryTree.o: BinaryTree.h BinaryTree.cpp Node.h
	g++ -std=c++11 -g -c BinaryTree.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp

clean:
	rm *.o BinaryTree
