#include "RingNode.h"

RingNode::RingNode()
{
	this->OldAge = 0;
	this->next = nullptr;
	
}

RingNode::RingNode(string Description, string SymbolicData, RingNode * next)
{
	this->Description = Description; 
	this->SymbolicData = SymbolicData; 
	this->next = next;
}

RingNode::~RingNode()
{
}

int RingNode::getAge()
{
	return this->OldAge; 
}

void RingNode::setAge(int age)
{
	this->OldAge = age; 
}

string RingNode::getDescription()
{
	return this->Description; 
}

void RingNode::setDescription(string description)
{
	this->Description = description; 
}

string RingNode::getData()
{
	return this->SymbolicData; 
}

void RingNode::setData(string data)
{
	this->SymbolicData = data; 
}
