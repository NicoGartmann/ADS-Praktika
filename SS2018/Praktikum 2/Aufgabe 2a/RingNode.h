#pragma once
#include <string>
using namespace std;

class RingNode
{
	friend class Ringpuffer;
public:
	int OldAge=0;
	string Description, SymbolicData; 
	RingNode * next; 
public:
	RingNode();
	RingNode(string Description, string SymbolicData, RingNode * next = 0);
	~RingNode();
	int getAge(); 
	void setAge(int age); 
	string getDescription();
	void setDescription(string description);
	string getData(); 
	void setData(string Data); 
};

