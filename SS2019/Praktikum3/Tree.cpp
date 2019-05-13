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
	TreeNode* newNode = new TreeNode(pNodePosID, this->NodeIDCounter, pName, pAlter, pEinkommen, pPLZ, true);
	if (this->isEmpty()) {
		this->anker->setRight(newNode);
		newNode->setRed(false);
	}
	else {
		if (this->balanceTree()) {

			//Einfuegeposition finden 
			TreeNode* tmp = new TreeNode();
			TreeNode* parrent = new TreeNode();
			while (tmp != nullptr) {
				parrent = tmp;
				if (pNodePosID <= tmp->getNodePosID()) {
					tmp = tmp->getLeft();
				}
				else {
					tmp = tmp->getRight();
				}
			}

			//einfuegen
			if (pNodePosID <= parrent->getNodePosID()) {
				parrent->setLeft(newNode);
			}
			else {
				parrent->setRight(newNode);
			}
		}
		else {
			cout << "Balancieren fehlgeschlagen" << endl; 
		}

		if (this->balanceTree()) {
			cout << "Erfolgreich balanciert" << endl; 
		}
		else {
			cout << "Balancieren nach Einfuegen fehlgeschlagen" << endl; 
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
		if (srch->getLeft())
			q.push(srch->getLeft());
		if (srch->getRight())
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
	TreeNode* tmp = new TreeNode();
	tmp = this->getFirst();
	queue<TreeNode*> q;
	if (tmp != nullptr) {
		q.push(tmp);
	}
	while (!q.empty()) {
		TreeNode* srch = new TreeNode();
		srch = q.front();
		q.pop();
		srch->print();
		if (srch->getLeft())
			q.push(srch->getLeft());
		if (srch->getRight())
			q.push(srch->getRight());
	}
}

bool Tree::balanceTree() {

}

bool Tree::rotateTreeRight(TreeNode* pFirst, TreeNode* pSecond) {
	pFirst->setLeft(pSecond->getRight());
	pSecond->setRight(pFirst);

}

bool Tree::rotateTreeLeft(TreeNode* pFirst, TreeNode* pSecond) {
	pFirst->setRight(pSecond->getLeft());
	pSecond->setLeft(pFirst);
}
//
bool Tree::isEmpty() {
	return !(this->anker->getRight());
}


TreeNode* Tree::getFirst() {
	return this->anker->getRight();
}


////////////////////////////////////
