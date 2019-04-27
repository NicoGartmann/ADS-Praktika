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
	this->NodeIDCounter = 0; 
}

void Tree::addNode(string pName, int pAlter, double pEinkommen, int pPLZ) {
	this->NodeIDCounter++; 
	int pNodePosID = pAlter + pPLZ + pEinkommen; 
	TreeNode* newNode = new TreeNode(pNodePosID, this->NodeIDCounter, pName, pAlter, pEinkommen, pPLZ);
	if (this->isEmpty()) {
		this->anker->setRight(newNode); 
	}
	else {
		TreeNode* tmp = new TreeNode(); 
		tmp = this->anker->getRight(); 
		TreeNode* tmp2 = new TreeNode(); 
		while (tmp!=nullptr) {
			tmp2 = tmp; 
			if (pNodePosID <= tmp->getNodePosID()) {
				tmp = tmp->getLeft();
			}
			else {
				tmp = tmp->getRight();
			}
		}
		if (pNodePosID <= tmp2->getNodePosID()) {
			tmp2->setLeft(newNode); 
		}
		else {
			tmp2->setRight(newNode); 
		}
	}
}

void Tree::deleteNode(int pNodePosID) {

}

bool Tree::searchNode(string pName) {
	return true; 
}

void Tree::printAll() {
	
}
//
bool Tree::isEmpty() {
	return !(this->anker->getRight()); 
}

TreeNode* Tree::srchmax() {
	TreeNode* tmp = new TreeNode(); 
	if (!this->isEmpty()) {
		tmp = this->anker->getRight(); 
		while (tmp->getRight() != nullptr) {
			tmp = tmp->getRight(); 
		}
	}
	return tmp; 
}

TreeNode* Tree::getFirst() {
	return this->anker->getRight(); 
}

void Tree::printPreorder(TreeNode* tmp) {
	if (tmp != nullptr) {
		tmp->print();
		printPreorder(tmp->getLeft());
		printPreorder(tmp->getRight());
	}
}
////////////////////////////////////