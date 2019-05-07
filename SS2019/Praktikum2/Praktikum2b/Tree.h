/*************************************************
* ADS Praktikum 2.2
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
	void deleteNode(int pNodePosID);
	bool searchNode(string pName); 
	void printAll(); 
	//
	bool isEmpty(); 
	TreeNode* srchmax(TreeNode* tmp); 
	TreeNode* srchparmax(TreeNode* tmp); 
	TreeNode* getFirst(); 
	void printPreorder(TreeNode* tmp); 
	////////////////////////////////////
	// friend-Funktionen sind für die Tests erforderlich und müssen unangetastet bleiben! 
	friend TreeNode * get_anker(Tree& TN);
};
