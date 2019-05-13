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
    newNode->setRed(false);
	}
	else {
		TreeNode* srchPos = new TreeNode();
    srchPos = this->getFirst();
    TreeNode* parrent = new TreeNode();
    parrent = this->anker;
    TreeNode* checkTree = new TreeNode();
    checkTree = this->anker;
    TreeNode* parrentCheck = new TreeNode();
    parrentCheck = this->anker;
    TreeNode* tmp = new TreeNode();
    tmp = this->anker;
    while(srchPos!=nullptr) {
      tmp = parrentCheck;
      parrentCheck = checkTree;
      checkTree = parrent;
      parrent = srchPos;

      //einfuege Position ermitteln
      if(srchPos->getNodePosID() <= pNodePosID) {
        srchPos = srchPos->getLeft();
      }
      else {
        srchPos = srchPos->getRight();
      }

      //4-er Knoten aufloesen durch umfaerben
      if(!parrent->getRed() && parrent->getLeft()->getRed() && parrent->getRight()->getRed()) {
        parrent->setRed(true);
        parrent->getLeft()->setRed(false);
        parrent->getRight()->setRed(false);
      }

      //SW-Baum Kriterien checken
      if(checkTree->getRed() && parrent->getRed()) {
        // 1. Fall: Linksrotation
        if(parrentCheck->getRight()==checkTree && checkTree->getRight()==parrent) {
          this->rotateTreeLeft(parrentCheck, checkTree);
          checkTree->setRed(false);
          parrentCheck->setRed(true);
          parrent->setRed(true);
          if(tmp->getNodePosID()<=checkTree->getNodePosID()) {
            tmp->setLeft(checkTree);
          }
          else {
            tmp->setRight(checkTree);
          }
        }
        // 2. Fall: Rechtsrotation
        else if(parrentCheck->getLeft()==checkTree && checkTree->getLeft()== parrent) {
          this->rotateTreeRight(parrentCheck, checkTree);
          checkTree->setRed(false);
          parrentCheck->setRed(true);
          parrent->setRed(true);
          if(tmp->getNodePosID()<=checkTree->getNodePosID()) {
            tmp->setLeft(checkTree);
          }
          else {
            tmp->setRight(checkTree);
          }
        }
        //3 . Fall: Rechts-Links-Rotation
        else if(parrentCheck->getRight() == checkTree && checkTree->getLeft()==parrent) {
          this->rotateTreeRight(checkTree, parrent);
          this->rotateTreeLeft(parrentCheck,parrent);
          parrent->setRed(false);
          parrentCheck->setRed(true);
          checkTree->setRed(true);
          if(tmp->getNodePosID()<=parrent->getNodePosID()) {
            tmp->setLeft(parrent);
          }
          else {
            tmp->setRight(parrent);
          }
        }
        // 4. Fall: Links-Rechts-Rotation
        else if(parrentCheck->getLeft()==checkTree && checkTree->getRight()== parrent) {
          this->rotateTreeLeft(checkTree,parrent);
          this->rotateTreeRight(parrentCheck, parrent);
          parrent->setRed(false);
          parrentCheck->setRed(true);
          checkTree->setRed(true);
          if(tmp->getNodePosID()<=parrent->getNodePosID()) {
            tmp->setLeft(parrent);
          }
          else {
            tmp->setRight(parrent);
          }
        }
      }
    }
    // eigentliches einfuegen
    if(parrent->getNodePosID() <= pNodePosID) {
      parrent->setLeft(newNode);
    }
    else {
      parrent->setRight(newNode);
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

void Tree::printLevelOrder() {
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
		if(srch->getLeft())
			q.push(srch->getLeft());
		if(srch->getRight())
			q.push(srch->getRight());
	}
}

void Tree::balanceTree() {

}

void Tree::rotateTreeRight(TreeNode* pFirst, TreeNode* pSecond) {
  pFirst->setLeft(pSecond->getRight();
  pSecond->setRight(pFirst);

}

void Tree::rotateTreeLeft(TreeNode* pFirst, TreeNode* pSecond) {
  pFirst->setRight(pSecond->getLeft());
  pSecond->setLeft(first); 
}
//
bool Tree::isEmpty() {
	return !(this->anker->getRight());
}


TreeNode* Tree::getFirst() {
	return this->anker->getRight();
}


////////////////////////////////////
