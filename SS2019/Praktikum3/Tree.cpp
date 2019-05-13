/*************************************************
* ADS Praktikum 3
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>


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
		while (tmp != nullptr) {
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


bool Tree::searchNode(string pName) {
	TreeNode* tmp = new TreeNode();
	tmp = this->getFirst();
	queue<TreeNode*> q;
	queue<TreeNode*> res;
	if (tmp != nullptr) {
		q.push(tmp);
	}
	while (!q.empty()) {
		TreeNode* srch = new TreeNode();
		srch = q.front();
		q.pop();
		if (srch->getName() == pName) {
			res.push(srch);
		}
		if(srch->getLeft())
			q.push(srch->getLeft());
		if(srch->getRight())
			q.push(srch->getRight());
	}

	if (!res.empty()) {
		cout << "+ Fundstellen: " << endl;
		while (!res.empty()) {
			TreeNode* found = new TreeNode();
			found = res.front();
			found->print();
			res.pop();
		}
		return true;
	}
	else {
		cout << "+ Datensatz konnte nicht gefunden werden." << endl;
		return false;
	}
}

void Tree::printAll() {
	//preorder
	if (this->isEmpty()) {
		cout << "+ Datensatz ist leer." << endl;
	}
	else {
		TreeNode* tmp = new TreeNode();
		tmp = this->getFirst();
		stack<TreeNode*> nodes;
		nodes.push(tmp);
		while (!nodes.empty()) {
			TreeNode* print = new TreeNode();
			print = nodes.top();
			print->print();
			nodes.pop();
			if (print->getRight())
				nodes.push(print->getRight());
			if (print->getLeft())
				nodes.push(print->getLeft());
		}
	}
}
//
bool Tree::isEmpty() {
	return !(this->anker->getRight());
}


TreeNode* Tree::getFirst() {
	return this->anker->getRight();
}


////////////////////////////////////
