#include "Ringpuffer.h"
#include <iostream>
#include <string>
using namespace std; 

Ringpuffer::Ringpuffer()
{
	anker = new RingNode; 
	this->size = 0; 
}

void Ringpuffer::addNode(string description, string data)
{
	if (anker->next == nullptr) //Falls der Ring leer ist 
	{
		anker->next = new RingNode(description, data, nullptr);
		anker->next->next = anker->next; 
		size++;
	}
	else if(size<6) // Falls der Ring nicht voll aber auch nicht leer ist 
	{			
		RingNode *tmp = anker->next->next; 
		anker->next->next = new RingNode(description, data, tmp);
		size++; 
		anker->next = anker->next->next;  
		while (tmp!=anker->next)
		{
			tmp->setAge(tmp->OldAge + 1);
			tmp = tmp->next; 
		}
	}
	else // Falls der Ring voll ist 
	{
		RingNode *t1 = anker->next->next; 
		RingNode *t2 = anker->next->next->next;
		delete t1; 
		anker->next->next = new RingNode(description, data, t2); 
		anker->next = anker->next->next; 
		while (t2 != anker->next)
		{
			t2->setAge(t2->OldAge + 1);
			t2 = t2->next; 
		}

	}
}

void Ringpuffer::search(string data)
{
	RingNode *tmp = anker->next; 
	do
	{
		if (tmp->getData() == data) break; 
		tmp = tmp->next;
	} while (tmp != anker->next); 
	if (tmp->getData() == data)
	{
		cout << "+ Gefunden in Backup: OldAge " << tmp->getAge() << ", Beschreibung: " << tmp->getDescription() << ", Daten: "
			<< tmp->getData() << endl << endl; 
	}
	else cout << "+ Datensatz konnte nicht gefunden werden.\n" << endl; 
}

void Ringpuffer::print()
{
	int s = 0; 
	RingNode *tmp = anker->next; 
	if (tmp == NULL)cout << "Liste leer.\n"; 
	else {
		while (s <= 6)
		{

			do {
				if (tmp->getAge() == s)
				{
					cout << "OldAge " << tmp->getAge() << ", Descr: " << tmp->getDescription() << ", Data; " << tmp->getData() << endl
						<< "--------------------------" << endl << endl;
				}
				tmp = tmp->next;
			} while (tmp != anker->next);
			s++;
		}
	}
}