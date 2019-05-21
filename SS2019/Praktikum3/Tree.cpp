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
		//entlang des Suchpfades balancieren
		this->balanceTree(pNodePosID); 

		//Einfuegeposition finden 
		TreeNode* tmp = new TreeNode();
		tmp = this->getFirst(); 
		TreeNode* parrent = new TreeNode();
		parrent = this->anker; 
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

		//erneut balancieren
		this->balanceTree(pNodePosID);
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

void Tree::balanceTree(int pNodePosID) {
	TreeNode* tmp = new TreeNode();
	tmp = this->getFirst();
	while (tmp != nullptr) {
		if (this->viererNode(tmp)) {
			this->umfaerben(tmp);
		}
		//rausfinden ob und wenn ja welche Rotation benoetigt wird
		if (this->balanceNeeded(tmp) == 0) {
			TreeNode* tmpRight = new TreeNode();
			tmpRight = tmp->getRight();
			this->rotateTreeRight(tmp, tmpRight);
			this->umfaerben(tmpRight); 
		}
		else if (this->balanceNeeded(tmp) == 1) {
			TreeNode* tmpLeft = new TreeNode();
			tmpLeft = tmp->getLeft();
			this->rotateTreeLeft(tmp, tmpLeft);
			this->umfaerben(tmpLeft); 
		}
		else if (this->balanceNeeded(tmp) == 2) {
			TreeNode* tmpRight = new TreeNode();
			tmpRight = tmp->getRight();
			TreeNode* tmpRightLeft = new TreeNode();
			tmpRightLeft = tmpRight->getLeft();
			this->rotateTreeRight(tmpRight, tmpRightLeft);	
			this->rotateTreeLeft(tmp, tmpRightLeft);
			this->umfaerben(tmpRightLeft); 
		}
		else if (this->balanceNeeded(tmp) == 3) {
			TreeNode* tmpLeft = new TreeNode();
			tmpLeft = tmp->getLeft();
			TreeNode* tmpLeftRight = new TreeNode();
			tmpLeftRight = tmpLeft->getRight();
			this->rotateTreeLeft(tmpLeft, tmpLeftRight);
			this->rotateTreeRight(tmp, tmpLeftRight);
			this->umfaerben(tmpLeftRight); 
		}
		//weiter den Suchpfad entlang
		if (pNodePosID <= tmp->getNodePosID()) {
			tmp = tmp->getLeft();
		}
		else {
			tmp = tmp->getRight();
		}
	}
}

void Tree::rotateTreeRight(TreeNode* pFirst, TreeNode* pSecond) {
	if (pSecond->getRight() != nullptr)
		pFirst->setLeft(pSecond->getRight());
	else
		pFirst->setLeft(nullptr); 

	pSecond->setRight(pFirst);

}

void Tree::rotateTreeLeft(TreeNode* pFirst, TreeNode* pSecond) {
	if (pSecond->getLeft() != nullptr)
		pFirst->setRight(pSecond->getLeft());
	else
		pFirst->setRight(nullptr); 


	pSecond->setLeft(pFirst);
}
//
bool Tree::isEmpty() {
	return !(this->anker->getRight());
}


TreeNode* Tree::getFirst() {
	return this->anker->getRight();
}

bool Tree::viererNode(TreeNode* pTmp) {
	if (pTmp->getLeft() != nullptr && pTmp->getRight() != nullptr) {
		TreeNode* tmpLeft = new TreeNode();
		TreeNode* tmpRight = new TreeNode();
		tmpLeft = pTmp->getLeft();
		tmpRight = pTmp->getRight();
		return (!pTmp->getRed() && tmpLeft->getRed() && tmpRight->getRed());
	}
	return false; 
}

void Tree::umfaerben(TreeNode* pTmp) {
	if (pTmp->getLeft() != nullptr && pTmp->getRight() != nullptr) {
		TreeNode* tmpLeft = new TreeNode();
		TreeNode* tmpRight = new TreeNode();
		tmpLeft = pTmp->getLeft();
		tmpRight = pTmp->getRight();
		pTmp->setRed(true);
		tmpLeft->setRed(false);
		tmpRight->setRed(false);
	}
}

int Tree::balanceNeeded(TreeNode* pTmp) {
	TreeNode* tmpRight = new TreeNode(); 
	TreeNode* tmpRightRight = new TreeNode(); 
	TreeNode* tmpLeft = new TreeNode();
	TreeNode* tmpLeftLeft = new TreeNode(); 
	TreeNode* tmpRightLeft = new TreeNode(); 
	TreeNode* tmpLeftRight = new TreeNode(); 
	if (pTmp->getRight() != nullptr) {
		tmpRight = pTmp->getRight();

		if (tmpRight->getRight() != nullptr) {
			tmpRightRight = tmpRight->getRight();

			//Linksrotation - return 1
			if (!pTmp->getRed() && tmpRight->getRed() && tmpRightRight->getRed()) {
				return 1;
			}
		}
		else {
			tmpRightRight = nullptr;
		}

		if (tmpRight->getLeft() != nullptr) {
			tmpRightLeft = tmpRight->getLeft();
			//RechtslinksRotation - return 2
			if (!pTmp->getRed() && tmpRight->getRed() && tmpRightLeft->getRed()) {
				return 2;
			}
		}
		else {
			tmpRightLeft = nullptr;
		}
	} 
	else {
		tmpRight = nullptr; 
	}

	if (pTmp->getLeft() != nullptr) {
		tmpLeft = pTmp->getLeft(); 

		if (tmpLeft->getLeft() != nullptr) {
			tmpLeftLeft = tmpLeft->getLeft();
			//Rechtsrotation - return 0
			if (!pTmp->getRed() && tmpLeft->getRed() && tmpLeftLeft->getRed()) {
				return 0;
			}
			
		}
		else {
			tmpLeftLeft = nullptr;
		}

		if (tmpLeft->getRight() != nullptr) {
			tmpLeftRight = tmpLeft->getRight();
			//LinksRechtsRotation - return 3
			if (!pTmp->getRed() && tmpLeft->getRed() && tmpLeftRight->getRed()) {
				return 3;
			}
		}
		else {
			tmpLeftRight = nullptr;
		}
	}
	else {
		tmpLeft = nullptr; 
	}
	//keine Rotation benötigt - return 4
	return 4; 
}

////////////////////////////////////
