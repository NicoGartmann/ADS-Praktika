/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>

using namespace std;

////////////////////////////////////
// Ihr Code hier:
Tree::Tree() {
	this->anker = new TreeNode(); 
}

void Tree::addNode(string pName, int pAlter, double pEinkommen, int pPLZ) {

}

void Tree::deleteNode(int pNodePosID) {

}

bool Tree::searchNode(string pName) {

}

void Tree::printAll() {

}
//
bool Tree::isEmpty() {
	return !(this->anker->getRight()); 
}
////////////////////////////////////