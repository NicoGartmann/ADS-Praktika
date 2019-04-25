/*************************************************
* ADS Praktikum 2.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>

// Ihr Code hier:
Ring::Ring() {
	this->anker = new RingNode(); 
	this->AnzahlNodes = 0; 
}

void Ring::addNode(string pDescription, string pSymbolicData) {
	//Ring leer 
	if (this->isEmpty()) {
		RingNode* tmp = new RingNode(0, pDescription, pSymbolicData);
		this->anker->setNext(tmp); 
		tmp->setNext(tmp); 
	}
	//Ring voll 
	else if(this->isFull()){
		RingNode* newNode = new RingNode(0,pDescription,pSymbolicData); 
		RingNode* tmp = new RingNode(); 
		tmp = this->anker;
		for(int i=1; i<=this->AnzahlNodes-1; i++) {
			tmp = tmp->getNext();
			tmp->setAge(tmp->getAge() + 1); 
		}
		delete tmp->getNext(); 
		this->AnzahlNodes--; 
		tmp->setNext(newNode); 
		newNode->setNext(this->anker->getNext()); 
		this->anker->setNext(newNode); 
	}
	//Ring weder voll noch leer 
	else {
		RingNode* tmp = new RingNode(); 
		tmp = this->anker;
		for (int i = 1; i <= this->AnzahlNodes; i++) {
			tmp = tmp->getNext();
			tmp->setAge(tmp->getAge() + 1); 
		}
		RingNode* newNode = new RingNode(0, pDescription, pSymbolicData); 
		tmp->setNext(newNode);
		newNode->setNext(this->anker->getNext()); 
		this->anker->setNext(newNode); 
		
	}
	this->AnzahlNodes++;
}

bool Ring::search(string pData) {
	RingNode* tmp = new RingNode(); 
	tmp = this->anker; 
	for(int i=1; i<=this->AnzahlNodes; i++) {
		tmp=tmp->getNext();
		if (tmp->getData() == pData) {
			break; 
		}
	}
	return tmp->getData() == pData; 
}

void Ring::print() {
	RingNode* tmp = new RingNode(); 
	tmp = this->anker; 
	for(int i=1; i<=this->AnzahlNodes; i++)  {
		tmp = tmp->getNext();
		cout << "Old Age: " << tmp->getAge() << ", Describtion: " << tmp->getDescription() << ", Data: " << tmp->getData() << endl; 
		cout << "--------------------------" << endl; 
	}
}
//
bool Ring::isEmpty() {
	return !(this->anker->getNext()); 
}

bool Ring::isFull() {
	return this->AnzahlNodes == 6; 
}
////////////////////////////////////
