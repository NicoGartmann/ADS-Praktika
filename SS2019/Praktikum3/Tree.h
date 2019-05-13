/*************************************************
* ADS Praktikum 3
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.h"

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
	//
	bool isEmpty();
	TreeNode* getFirst();
	////////////////////////////////////
	// friend-Funktionen sind f�r die Tests erforderlich und m�ssen unangetastet bleiben!
	friend TreeNode * get_anker(Tree& TN);
};
