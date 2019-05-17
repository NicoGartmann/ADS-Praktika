#include "Tree.h"
#include <string>
#include <queue>
#include <iostream>
using namespace std;

Tree::Tree()
{
	this->anker = NULL;
	this->NodeIDCounter = 1;
}


Tree::~Tree()
{
	if (!this->anker) return;
	queue<TreeNode *> q;
	//Use a queue as processing pipeline
	q.push(this->anker);
	while (!q.empty()) {
		TreeNode * curPos = q.front();
		q.pop();
		if (curPos->getLeft()) {
			q.push(curPos->getLeft());
		}
		if (curPos->getRight()) {
			q.push(curPos->getRight());
		}
		delete curPos;
	} 
}

void Tree::addNode(string Name, int Alter, double Einkommen, int PLZ) {
	int pos = Alter + PLZ + (int)Einkommen;
	TreeNode * newNode = new TreeNode(pos, this->NodeIDCounter, Name, Alter, Einkommen, PLZ);
	if (anker == NULL) {
		newNode->setRed(false);
		this->anker = newNode;
	}
	// Assumption: NodePosID must differ
	else {
		TreeNode * tmp = this->anker;
		TreeNode * pParent = this->anker;
		while (tmp != NULL) {
			pParent = tmp;
			if (pos < tmp->getNodePosID()) {
				tmp = tmp->getLeft();
			}
			else {
				tmp = tmp->getRight();
			}
		}
		newNode->setParent(pParent);
		if (pos < pParent->getNodePosID()) {
			pParent->setLeft(newNode);
		}
		else pParent->setRight(newNode);
	}
	this->NodeIDCounter++;
	this->balanceTree(newNode);
}

bool Tree::searchNode(string name) {
	if (this->anker == NULL) return false;
	bool f_flag = false;;
	queue<TreeNode *> q;
	q.push(this->anker);
	while (!q.empty()) {
		TreeNode * curPos = q.front();
		if (curPos->getName() == name) {
			f_flag++;
			cout << "+Fundstellen:" << endl;
			curPos->print();
		}
		q.pop();
		if (curPos->getLeft()) {
			q.push(curPos->getLeft());
		}
		if (curPos->getRight()) {
			q.push(curPos->getRight());
		}
	}
	return f_flag;
}

void Tree::printAll() {
	if (!this->anker) return;
	printPreOrder(this->anker);
}

void Tree::printPreOrder(TreeNode * node) {
	if (!node) return;
	cout << node->getNodeID() << " | " << node->getName() << " | " << node->getAlter() << " | " << node->getEinkommen() << " | " << node->getPLZ() << " | " << node->getNodePosID() << endl;
	printPreOrder(node->getLeft());
	printPreOrder(node->getRight());
}

void Tree::printLevelOrder() {
	if (this->anker == NULL) return;
	queue<TreeNode *> q;
	//Use a queue as processing pipeline
	q.push(this->anker);
	while (!q.empty()) {
		TreeNode * curPos = q.front();
		cout << curPos->getNodeID() << " | " << curPos->getName() << " | " << curPos->getAlter() << " | " << curPos->getEinkommen() << " | " << curPos->getPLZ() << " | " << curPos->getNodePosID() << endl;
		q.pop();
		if (curPos->getLeft()) {
			q.push(curPos->getLeft());
		}
		if (curPos->getRight()) {
			q.push(curPos->getRight());
		}
	}
}

bool Tree::balanceTree(TreeNode * node) {
	TreeNode * parent = NULL;
	TreeNode * grandparent = NULL;

	while ((node != this->anker) && node->getParent()->getRed())
	{
		parent = node->getParent();
		grandparent = parent->getParent();

		//A: Parent of node is left child of Grand-parent of node
		if (parent == grandparent->getLeft())
		{
			TreeNode * uncle = grandparent->getRight();

			//The uncle of node is also red -> Only Recoloring required
			if (uncle != NULL && uncle->getRed())
			{
				grandparent->setRed(true);
				parent->setRed(false);
				uncle->setRed(false);
				node = grandparent;
			}
			else
			{
				//node is right child of its parent -> Left-rotation required
				if (node == parent->getRight())
				{
					node = parent;
					rotateTreeLeft(this->anker, node);
				}

				//node is left child of its parent -> Right-rotation required
				node->getParent()->setRed(false);
				node->getParent()->getParent()->setRed(true);
				rotateTreeRight(this->anker, node->getParent()->getParent());
			}
		}
		else
		{
			TreeNode * uncle = grandparent->getLeft();

			//The uncle of node is also red -> Only Recoloring required
			if (uncle && uncle->getRed())
			{
				grandparent->setRed(true);
				parent->setRed(false);
				uncle->setRed(false);
				node = grandparent;
			}
			else
			{
				//node is left child of its parent -> Right-rotation required
				if (node == parent->getLeft())
				{
					node = parent;
					rotateTreeRight(this->anker, node);
				}

				//node is right child of its parent -> Left-rotation required
				node->getParent()->setRed(false);
				node->getParent()->getParent()->setRed(true);
				rotateTreeLeft(this->anker, node->getParent()->getParent());
			}
		}
	}
	this->anker->setRed(false);
	return true;
}


bool Tree::rotateTreeLeft(TreeNode * root, TreeNode * node) {
	TreeNode * pt_right = node->getRight();
	//Turn pt_rights subtree into node's right subtree
	node->setRight(pt_right->getLeft());
	if(pt_right->getLeft())
		pt_right->getLeft()->setParent(node);
	//pt_right's new parent was node's parent
	pt_right->setParent(node->getParent());
	//Set the parent to point to pt_right instead of node
	//First check, if we're at the root
	if (!node->getParent())
		this->anker = pt_right;
	else if (node == node->getParent()->getLeft())
		//node was the left child
		node->getParent()->setLeft(pt_right);
	else
		//node was the right child
		node->getParent()->setRight(pt_right);

	pt_right->setLeft(node);
	node->setParent(pt_right);
	return true;
}

bool Tree::rotateTreeRight(TreeNode * root, TreeNode * node) {
	TreeNode * pt_left = node->getLeft();
	//Turn pt_left's subtree into node's right subtree
	node->setLeft(pt_left->getRight());
	if(pt_left->getRight())
		pt_left->getRight()->setParent(node);
	//Update pt_left's parents
	pt_left->setParent(node->getParent());
	//Set the parent to point to pt_left instead of node
	//First check if we're at the root
	if (!node->getParent())
		this->anker = pt_left;
	else if (node == node->getParent()->getRight())
		node->getParent()->setRight(pt_left);
	else
		node->getParent()->setLeft(pt_left);

	pt_left->setRight(node);
	node->setParent(pt_left);
	return true;
}