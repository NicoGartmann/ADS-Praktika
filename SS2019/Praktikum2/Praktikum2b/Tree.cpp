/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include <queue>

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
	if (!this->isEmpty()) {
		TreeNode* tmp = new TreeNode(); 
		tmp = this->getFirst();
		TreeNode* parrent = new TreeNode(); 
		parrent = this->anker; 
		while (tmp != nullptr) {
			if (pNodePosID == tmp->getNodePosID())
				break; 
			parrent = tmp; 
			if (pNodePosID <= tmp->getNodePosID())
				tmp = tmp->getLeft();
			else
				tmp = tmp->getRight(); 
		}
		if (tmp != nullptr) {
			//Key gefunden
			//1. Fall: tmp ist Blattknoten
			if (tmp->getRight() == nullptr && tmp->getLeft() == nullptr) {
				if (parrent->getRight() == tmp)
					parrent->setRight(nullptr);
				else
					parrent->setLeft(nullptr);
				delete tmp;
			}
			//2. Fall: tmp hat ein Kind
			else if (tmp->getRight() == nullptr || tmp->getLeft() == nullptr) {
				if (parrent->getRight() == tmp)
					parrent->setRight(tmp->getRight());
				else
					parrent->setLeft(tmp->getLeft());
				delete tmp;
			}
			//3. Fall: tmp hat zwei Kinder 
			else {
				TreeNode* maxLTB = new TreeNode();
				TreeNode* parrentMax = new TreeNode();
				maxLTB = this->srchmax(tmp->getLeft());
				if (maxLTB == tmp->getLeft()) {
					maxLTB->setRight(tmp->getRight());
				}
				else {
					parrentMax = this->srchparmax(tmp->getLeft());
					maxLTB->setRight(tmp->getRight());
					maxLTB->setLeft(tmp->getLeft());
					parrentMax->setRight(nullptr);
				}

				if (parrent->getRight() == tmp)
					parrent->setRight(maxLTB);
				else
					parrent->setLeft(maxLTB);
				delete tmp;
			}
			cout << "Loeschen erfolgreich." << endl;
		}
		else
			cout << "Loeschen nicht erfolgreich." << endl; 
	}
	else cout << "Loeschen nicht erfolgreich." << endl; 
}

bool Tree::searchNode(string pName) {
	TreeNode* tmp = new TreeNode(); 
	tmp = this->getFirst(); 
	queue<TreeNode*> q;
	queue<TreeNode*> res; 
	if(tmp!=nullptr) {
		q.push(tmp); 
	}
	while(!q.empty()) {
		TreeNode* srch = new TreeNode(); 
		srch = q.back();
		q.pop(); 
		if(srch->getName==pName) {
			res.push(srch);  
		} 
		q.push(tmp->getLeft()); 
		q.push(tmp->getRight()); 
	}
	
	if(!res.empty()) {
		cout << "+ Fundstellen: " << endl; 
		while(!res.empty()) {
			TreeNode* found = new TreeNode(); 
			found = res.back(); 
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
	//preorderS
}
//
bool Tree::isEmpty() {
	return !(this->anker->getRight()); 
}

TreeNode* Tree::srchmax(TreeNode* tmp) {
	if (!this->isEmpty()) {
		while (tmp->getRight() != nullptr) {
			tmp = tmp->getRight(); 
		}
	}
	return tmp; 
}

TreeNode* Tree::srchparmax(TreeNode* tmp) {
	if (!this->isEmpty()) {
		while (tmp->getRight()->getRight() != nullptr) {
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