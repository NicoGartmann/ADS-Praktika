#pragma once
#include "TreeNode.h"
#ifndef _TREE_H
#define _TREE_H

class Tree {

public:
	TreeNode *Anker;


public:
	Tree();
	void addNode(string name, int alter, double einkommen, int plz, int id);
	void search(string name, TreeNode *start);
	void print(TreeNode *start);
	void remove(int posid);


};
#endif