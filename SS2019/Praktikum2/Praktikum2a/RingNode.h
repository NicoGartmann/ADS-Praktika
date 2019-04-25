/*************************************************
* ADS Praktikum 2.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>
using namespace std; 

class RingNode {

private:
	// Ihr Code hier:
	int OldAge; 
	string Description; 
	string SymbolicData; 
	RingNode* next; 
	//	
public:
	// Ihr Code hier:
	RingNode(); 
	RingNode(int pOldAge, string pDescription, string pSymbolicData); 
	int getAge(); 
	void setAge(int pOldAge); 
	string getDescription(); 
	void setDescription(string pDescription); 
	string getData(); 
	void setData(string pSymbolicData); 
	RingNode* getNext(); 
	void setNext(RingNode* pNext); 
	//
};
