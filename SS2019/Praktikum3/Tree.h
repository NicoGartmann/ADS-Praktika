/*************************************************
* ADS Praktikum 3
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.hpp"

using namespace std;

class Tree {

private:
	///////////////////////////////////////
	// Ihr Code hier:
	TreeNode* anker;
	int NodeIDCounter;
	//
	////////////////////////////////////

public:
	///////////////////////////////////////
	// Ihr Code hier:
	Tree();
	void addNode(string pName, int pAlter, double pEinkommen, int pPLZ);
	bool searchNode(string pName);
	void printAll();

	void balanceTree(int pNodePosID);
	void rotateTreeRight(TreeNode* pFirst, TreeNode* pSecond);
	void rotateTreeLeft(TreeNode* pFirst, TreeNode* pSecond);
	//
	bool isEmpty();
	TreeNode* getFirst();
	bool viererNode(TreeNode* pTmp); 
	void umfaerben(TreeNode* pTmp); 
	int balanceNeeded(TreeNode* pTmp); 
	////////////////////////////////////
	// friend-Funktionen sind f�r die Tests erforderlich und m�ssen unangetastet bleiben!
	friend TreeNode * get_anker(Tree& TN);
};
