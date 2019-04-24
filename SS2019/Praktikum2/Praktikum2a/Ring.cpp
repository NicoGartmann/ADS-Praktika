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
}

void Ring::addNode(string pDescribtion, string pSymbolicData) {
	//Ring leer 
	if (isEmpty()) {
		RingNode* tmp = new RingNode(0, pDescribtion, pSymbolicData);
		this->anker->setNext(tmp); 
		tmp->setNext(this->anker); 
		this->AnzahlNodes++; 
	}
	//Ring voll 
	else if(this->AnzahlNodes==6){
		RingNode* tmp = new RingNode(); 
		RingNode* tmp2 = new RingNode(); 
		while (tmp->getNext() != this->anker->getNext()) {
			tmp2 = tmp; 
			tmp->setAge(tmp->getAge() + 1); 
			tmp = tmp->getNext(); 
		}
	}
	//Ring weder voll noch leer 
	else {
		RingNode* tmp = new RingNode(); 
		while (tmp->getNext() != this->anker->getNext()) {
			tmp->setAge(tmp->getAge() + 1); 
			tmp = tmp->getNext(); 
		}
		RingNode* newNode = new RingNode(0, pDescribtion, pSymbolicData); 
		tmp->setNext(newNode);
		newNode->setNext(this->anker->getNext()); 
		this->anker->setNext(newNode); 
		this->AnzahlNodes++; 
	}
}

bool Ring::search(string pDescribtion) {

}

void Ring::print() {

}
//
bool Ring::isEmpty() {
	return this->anker->getNext(); 
}
////////////////////////////////////
