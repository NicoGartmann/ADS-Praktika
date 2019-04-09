#include "TreeNode.h"
#include <string>
#include <iostream>
using namespace std;

TreeNode::TreeNode() {
	this->links = NULL;
	this->rechts = NULL;
}
TreeNode::TreeNode(string name, int alter, double einkommen, int plz, int nodeid) {
	this->links = NULL;
	this->rechts = NULL;
	this->name = name;
	this->alter = alter;
	this->einkommen = einkommen;
	this->plz = plz;
	this->NodePosID = (int)alter + plz + einkommen;
	this->NodeID = nodeid;
}
TreeNode::~TreeNode() {

}
string TreeNode::getName() {
	return this->name;
}
int TreeNode::getAlter() {
	return this->alter;
}
double TreeNode::getEinkommen() {
	return this->einkommen;
}
int TreeNode::getPlz() {
	return this->plz;
}
void TreeNode::setName(string pName) {
	this->name = pName;
}
void TreeNode::setAlter(int pAlter) {
	this->alter = pAlter;
}
void TreeNode::setEinkommen(double pEinkommen) {
	this->einkommen = pEinkommen;
}
void TreeNode::setPlz(int pPlz) {
	this->plz = pPlz;
}
void TreeNode::printData() {
	cout << "NodeID: " << this->NodeID << ", Name: " << this->getName() << ", Alter: " << this->getAlter() << ", Einkommen: " << this->getEinkommen() << ", PLZ: " << this->getPlz() << ", PosID: " << this->NodePosID << endl;
}