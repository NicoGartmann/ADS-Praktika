#pragma once
#ifndef _TREENODE_H
#define _TREENODE_H
#include <string>
using namespace std;
class TreeNode {
	friend class Tree;

protected:
	int NodePosID;
	int NodeID;
	string name;
	int alter;
	double einkommen;
	int plz;
	TreeNode *links;
	TreeNode *rechts;

protected:
	TreeNode();
	TreeNode(string name, int alter, double einkommen, int plz, int nodeid);
	~TreeNode();
	string getName();
	int getAlter();
	double getEinkommen();
	int getPlz();
	void setName(string pName);
	void setAlter(int pAlter);
	void setEinkommen(double pEinkommen);
	void setPlz(int pPlz);
	void printData();



};
#endif