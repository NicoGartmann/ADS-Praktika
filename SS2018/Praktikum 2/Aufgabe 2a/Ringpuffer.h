#pragma once
#include "RingNode.h"

class Ringpuffer
{
	/*Klasse dient zur Verwaltung des Rings*/
private: 
	RingNode *anker; 
	int size = 0; 
public: 
	Ringpuffer();  
	void addNode(string description,string data); 
	void search(string data); 
	void print(); 
};