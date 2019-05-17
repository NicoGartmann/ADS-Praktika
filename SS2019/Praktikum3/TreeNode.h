#pragma once
#include <string>
using namespace std;
class TreeNode
{
private:
	int NodePosID;
	int NodeID;
	bool red;
	string Name;
	int Alter;
	double Einkommen;
	int PLZ;
	TreeNode * left;
	TreeNode * right;
	TreeNode * parent;
public:
	TreeNode(int NodePosID, int NodeID, string Name, int Alter, double Einkommen, int PLZ);
	~TreeNode();
	int getNodePosID();
	int getNodeID();
	string getName();
	void setName(string name);
	int getAlter();
	void setAlter(int alter);
	double getEinkommen();
	void setEinkommen(double einkommen);
	int getPLZ();
	void setPLZ(int plz);

	bool getRed();
	void setRed(bool red);

	void setParent(TreeNode * parent);
	TreeNode * getParent();

	TreeNode* getLeft();
	TreeNode* getRight();
	void setLeft(TreeNode* left);
	void setRight(TreeNode* right);
	void print();
};

