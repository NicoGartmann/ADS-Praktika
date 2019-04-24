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
	string Describtion; 
	string SymbolicData; 
	RingNode* next; 
	//	
public:
	// Ihr Code hier:
	RingNode(); 
	RingNode(int pOldAge, string pDescribtion, string pSymbolicData); 
	int getAge(); 
	void setAge(int pOldAge); 
	string getDescribtion(); 
	void setDescribtion(string pDescribtion); 
	string getData(); 
	void setData(string pSymbolicData); 
	RingNode* getNext(); 
	void setNext(RingNode* pNext); 
	//
};
