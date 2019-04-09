#include "Tree.h"
#include "TreeNode.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Tree::Tree() {
	this->Anker = NULL;
}

void Tree::addNode(string name, int alter, double einkommen, int plz, int id) {
	TreeNode *tmp = this->Anker;
	if (tmp == nullptr) {
		this->Anker = new TreeNode(name, alter, einkommen, plz, 0);
	}
	else {
		int pos = (int)(alter + einkommen + plz);
		TreeNode *tmp2 = NULL;
		while (tmp != NULL) {
			tmp2 = tmp;
			if (tmp->NodePosID > pos) {
				tmp = tmp->links;

			}
			else {
				tmp = tmp->rechts;
			}
		}
		if (tmp2->NodePosID > pos) {
			tmp2->links = new TreeNode(name, alter, einkommen, plz, id);
		}
		else {
			tmp2->rechts = new TreeNode(name, alter, einkommen, plz, id);
		}
	}
}

void Tree::search(string name, TreeNode *start) {
	if (start != NULL) {
		if (name == start->getName()) {
			cout << "+Fundstellen:" << endl;
			start->printData();
		}
		else {
			Tree::search(name, start->links);
			Tree::search(name, start->rechts);
		}
	}
}

void Tree::remove(int posid) {
	TreeNode *tmp = this->Anker;
	TreeNode *tmp2 = nullptr;
	while (tmp->NodePosID != posid) {
		tmp2 = tmp;
		if (tmp->NodePosID > posid) {
			tmp = tmp->links;
		}
		else {
			tmp = tmp->rechts;
		}
	}
	// keine Kinder
	if (tmp->links == nullptr && tmp->rechts == nullptr) {
		if (tmp != Anker)
		{
			if (tmp2->rechts == tmp) {
				tmp2->rechts = nullptr;

			}
			else {
				tmp2->links = nullptr;

			}
		}
	}
	//ein Kind
	else if (tmp->links == nullptr || tmp->rechts == nullptr) {
		if (tmp->links != nullptr) {
			if (tmp2->rechts == tmp) {
				tmp2->rechts = tmp->links;
			}
			else {
				tmp2->links = tmp->links;
			}


		}

		else if (tmp2->rechts == tmp) {
			tmp2->rechts = tmp->rechts;
		}
		else {
			tmp2->links = tmp->rechts;

		}
	}
	else {
		// 2 Kinder
		TreeNode *minNode = tmp->rechts; 
		TreeNode *minParrent = tmp->rechts; 

		//Suche Minimum
		while (minNode->links != nullptr)
			minNode = minNode->links; 
		while (minParrent->links != minNode&& minParrent->links != nullptr)
			minParrent = minParrent->links; 
		if (tmp == Anker)
		{
			minParrent->links = minNode->rechts;
			minNode->links = tmp->links;
			minNode->rechts = tmp->rechts;
			Anker = minNode;
		}
		else
		{
			minNode->links = tmp->links;

			if (tmp2->links == tmp)
				tmp2->links = minNode;
			else tmp2->rechts = minNode;
		}
	}
	delete tmp;
}

void Tree::print(TreeNode *start) {
	TreeNode *tmp = start;
	if (tmp != NULL) {
		cout <<setw(5)<< tmp->NodeID << "|"<< setw(28)<< tmp->getName() << "|"<< setw(13) << tmp->getAlter() << "|" << setw(17) << tmp->getEinkommen() << "|" << setw(9) << tmp->getPlz() << "|" << setw(7) << tmp->NodePosID << endl;
		Tree::print(tmp->links);
		Tree::print(tmp->rechts);

	}

}