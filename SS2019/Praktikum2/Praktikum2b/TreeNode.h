/*************************************************
* ADS Praktikum 2.2
* TreeNode.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode {

private:
	///////////////////////////////////////
	// Ihr Code hier:	
	int NodePosID; 
	int NodeID; 
	string Name; 
	int Alter; 
	double Einkommen; 
	int PLZ; 
	TreeNode* left; 
	TreeNode* right; 
	//
	////////////////////////////////////

public:
	///////////////////////////////////////
	// Ihr Code hier:
	TreeNode(); 
	TreeNode(int pNodePosID, int pNodeID, string pName, int pAlter, double pEinkommen, int pPLZ); 
	int getNodePosID(); 
	int getNodeID(); 
	string getName(); 
	void setName(string pName); 
	int getAlter(); 
	void setAlter(int pAlter); 
	double getEinkommen(); 
	void setEinkommen(double pEinkommen); 
	int getPLZ(); 
	void setPLZ(int pPLZ); 
	TreeNode* getLeft(); 
	TreeNode* getRight(); 
	void setLeft(TreeNode* pLeft); 
	void setRight(TreeNode* pRight); 
	void print(); 
	//
	////////////////////////////////////
};
