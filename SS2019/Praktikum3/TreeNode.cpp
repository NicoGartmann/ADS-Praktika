#include "TreeNode.h"
#include <iostream>
using namespace std;

TreeNode::TreeNode(int NodePosID, int NodeID, string Name, int Alter, double Einkommen, int PLZ)
{
	this->NodePosID = NodePosID;
	this->NodeID = NodeID;
	this->red = true;
	this->Name = Name;
	this->Alter = Alter;
	this->Einkommen = Einkommen;
	this->PLZ = PLZ;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}


TreeNode::~TreeNode()
{
}

bool TreeNode::getRed() {
	return this->red;
}

void TreeNode::setRed(bool red) {
	this->red = red;
}

int TreeNode::getNodePosID() 
{ 
	return this->NodePosID;
}

int TreeNode::getNodeID() {
	return this->NodeID;
}

string TreeNode::getName() {
	return this->Name;
}

void TreeNode::setName(string name) {
	this->Name = name;
}

int TreeNode::getAlter() {
	return this->Alter;
}

void TreeNode::setAlter(int alter) {
	this->Alter = alter;
}

double TreeNode::getEinkommen() {
	return this->Einkommen;
}

void TreeNode::setEinkommen(double einkommen) {
	this->Einkommen = einkommen;
}

int TreeNode::getPLZ() {
	return this->PLZ;
}

void TreeNode::setPLZ(int plz) {
	this->PLZ = plz;
}

TreeNode* TreeNode::getLeft() {
	return this->left;
}

TreeNode* TreeNode::getRight() {
	return this->right;
}

void TreeNode::setLeft(TreeNode* left) {
	this->left = left;
}

void TreeNode::setRight(TreeNode* right) {
	this->right = right;
}

void TreeNode::print() {
	cout << "NodeID:" << this->getNodeID() << ", Name: " << this->getName() << ", Alter: " << this->getAlter() << ", Einkommen " << this->getEinkommen() << ", PLZ: " << this->getPLZ() << ", PosID: " << this->getNodePosID() << endl;
}

void TreeNode::setParent(TreeNode * parent) {
	this->parent = parent;
}

TreeNode * TreeNode::getParent() {
	return this->parent;
}