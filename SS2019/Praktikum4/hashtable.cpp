#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size) {

	//*****************************
	// implement constructor here *
	//*****************************
	this->size = size; 
	this->hashTable = new vector<int>; 
	this->hashTable->resize(size); 
	for (int i = 0; i < size; i++) {
		this->hashTable->at(i) = -1; 
	}
}

HashTable::~HashTable()
{
	//****************************
	// implement destructor here *
	//****************************
}

int HashTable::hashValue(int item) {

	int index = -1; //dummy initializtation

	//******************************************
	// implement calculation of hashindex here *
	//******************************************
	for (int i = 0; i < this->getSize(); i++) {
		index = (item + i * i) % this->size; 
		if (this->hashTable->at(index) == -1) {
			break; 
		}
		this->collisionCount++; 
	}

	return index;
}

int HashTable::insert(int item) {

	//******************************************
	// implement insertion of new element here *
	//******************************************
	int index = this->hashValue(item); 
	this->hashTable->at(index) = item; 
	this->elements++; 

	if (this->fuellStand() >= 70) {
		cout << "Groesse vorher: " << this->getSize() << endl; 
		if (this->rehashing()) {
			cout << "Groesse nachher: " << this->getSize() << endl; 
			cout << "Erfolgreich vergroessert.\n"; 
		}
		else {
			cout << "Groesse nachher: " << this->getSize() << endl; 
			cout << "Nicht erfolgreich.\n"; 
		}
	}
	return 0; //dummy return
}


int HashTable::at(int i) {
	return hashTable->at(i);
}

int HashTable::getCollisionCount() {
	return this->collisionCount;
}

int HashTable::getSize() {
	return this->size;
}

int HashTable::getElements() {
	return this->elements;
}

int HashTable::fuellStand() {
	double res = (double(this->getElements()) / this->getSize())*100;
	return int(res);
}

int HashTable::setNewSize() {
	int res = this->getSize() * 2; 
	if (res > 997) {
		return this->getSize(); 
	}
	else {
		for (int i = 0; i < 168; i++) {
			if (prim[i] >= res) {
				res = prim[i];
				break;
			}
		}
		return res; 
	}
}

bool  HashTable::rehashing() {
	HashTable* newTable = new HashTable(this->setNewSize()); 

	for (int i = 0; i < this->hashTable->size(); i++) {
		if (this->hashTable->at(i) != -1) {
			newTable->insert(this->hashTable->at(i));
		}
	}

	this->hashTable = newTable->hashTable; 
	this->collisionCount = newTable->collisionCount; 
	this->size = newTable->size; 
	return (this->getSize() == newTable->getSize()); 
}
