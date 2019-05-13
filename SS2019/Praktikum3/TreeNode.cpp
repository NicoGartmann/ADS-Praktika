/*************************************************
* ADS Praktikum 3
* TreeNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>


////////////////////////////////////
// Ihr Code hier:
TreeNode::TreeNode() {
	this->left = nullptr;
	this->right = nullptr;
}

TreeNode::TreeNode(int pNodePosID, int pNodeID, string pName, int pAlter, double pEinkommen, int pPLZ, bool pRed) {
	this->NodePosID = pNodePosID;
	this->NodeID = pNodeID;
	this->Name = pName;
	this->Alter = pAlter;
	this->Einkommen = pEinkommen;
	this->PLZ = pPLZ;
	this->left = nullptr;
	this->right = nullptr;
	this->red = pRed; 
}

int TreeNode::getNodePosID() {
	return this->NodePosID;
}

int TreeNode::getNodeID() {
	return this->NodeID;
}

string TreeNode::getName() {
	return this->Name;
}

void TreeNode::setName(string pName) {
	this->Name = pName;
}

int TreeNode::getAlter() {
	return this->Alter;
}

void TreeNode::setAlter(int pAlter) {
	this->Alter = pAlter;
}

double TreeNode::getEinkommen() {
	return this->Einkommen;
}

void TreeNode::setEinkommen(double pEinkommen) {
	this->Einkommen = pEinkommen;
}

int TreeNode::getPLZ() {
	return this->PLZ;
}

void TreeNode::setPLZ(int pPLZ) {
	this->PLZ = pPLZ;
}

bool TreeNode::getRed() {
	return this->red;
}

void TreeNode::setRed(bool pRed) {
	this->red = pRed;
}

TreeNode* TreeNode::getLeft() {
	return this->left;
}

TreeNode* TreeNode::getRight() {
	return this->right;
}

void TreeNode::setLeft(TreeNode* pLeft) {
	this->left = pLeft;
}

void TreeNode::setRight(TreeNode* pRight) {
	this->right = pRight;
}

void TreeNode::print() {
	cout << this->NodeID << " | " << this->Name << " | " << this->Alter << " | " << this->Einkommen << " | " << this->PLZ << " | " << this->NodePosID << " | " << this->red << endl; 
}
//
////////////////////////////////////
