#pragma once
#include "TreeNode.h"
#include <string>

class Tree
{
private: 
	TreeNode * anker;
	int NodeIDCounter;
	void printPreOrder(TreeNode * node);
	bool rotateTreeRight(TreeNode * n1, TreeNode * n2);
	bool rotateTreeLeft(TreeNode * n1, TreeNode * n2);

public:
	Tree();
	~Tree();
	void addNode(string Name, int Alter, double Einkommen, int PLZ);
	bool searchNode(string name);
	void printAll();

	bool balanceTree(TreeNode * node);
	void printLevelOrder();

	friend TreeNode * get_anker(Tree& TN);
};

