/*************************************************
* ADS Praktikum 2.1
* RingNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "RingNode.h"


// Ihr Code hier:
RingNode::RingNode() {

}

RingNode::RingNode(int pOldAge, string pDescribtion, string pSymbolicData) {
	this->OldAge = pOldAge; 
	this->Describtion = pDescribtion; 
	this->SymbolicData = pSymbolicData; 
}

int RingNode::getAge() {
	return this->OldAge; 
}

void RingNode::setAge(int pOldAge) {
	this->OldAge = pOldAge; 
}

string RingNode::getDescribtion() {
	return this->Describtion; 
}

void RingNode::setDescribtion(string pDescribtion) {
	this->Describtion = pDescribtion; 
}

string RingNode::getData() {
	return this->SymbolicData; 
}

void RingNode::setData(string pSymbolicData) {
	this->SymbolicData = pSymbolicData; 
}

RingNode* RingNode::getNext() {
	return this->next; 
}

void RingNode::setNext(RingNode* pNext) {
	this->next = pNext; 
}
// 
////////////////////////////////////