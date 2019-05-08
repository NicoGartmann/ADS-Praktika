/*************************************************
* ADS Praktikum 2.2
* main.cpp
*
*************************************************/
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Tree.h"
#include "catch.h"

using namespace std;

///////////////////////////////////////
// Hilfsmethoden f�rs Men� hier:



//
///////////////////////////////////////
int main() {

	//int result = Catch::Session().run();

	///////////////////////////////////////
	// Ihr Code hier:
	Tree* myTree = new Tree();
	myTree->addNode("Nico", 1, 1, 1);
	myTree->addNode("Kiara", 2, 2, 2);
	myTree->addNode("Sassa", 3, 3, 3);
	myTree->addNode("Mucky", 0, 0, 0);
	myTree->addNode("Ashkan", 0, 0, 1);
	myTree->addNode("Ashkan", 4, 4, 4); 
	myTree->printPreorder(myTree->getFirst());
	myTree->deleteNode(23);
	myTree->printAll();
	myTree->searchNode("Ashkan");
	myTree->searchNode("Georgios");
	//
	///////////////////////////////////////
	system("PAUSE");

	return 0;
}
