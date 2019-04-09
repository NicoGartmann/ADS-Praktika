#include "Graph.h"
#include "GraphNode.h"
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main()
{
	int bef = 0;
	int key = 0;
	Graph* g = new Graph();

	while (bef != 7)
	{
		do
		{
			cout << "Bitte treffen Sie Ihre Auswahl:\n"
				<< "1. Graph einlesen\n"
				<< "2. Tiefensuche\n"
				<< "3. Breitensuche\n"
				<< "4. Prim\n"
				<< "5. Kruskal\n"
				<< "6. Graph ausgeben\n"
				<< "7. Beenden\n"
				<< ">? ";
			cin >> bef;
			cout << endl;
		} while (bef > 7 || bef < 1);

		if (bef == 1)
		{
			string path;
			path = "graph3.txt";
			bool success = g->init(path);
			if (success) cout << "Graph erfolgreich eingefuegt.\n";
			else cout << "Fehler beim Lesen der Datei.\n";
			cout << endl;
		}
		else if (bef == 2)
		{
			cout << "Bitte Startknoten angeben: >? "; cin >> key;
			if (g->depthSearch(g, g->GetNodeByKey(key)))
				cout << "Alle Knoten erreicht.\n";
			else cout << "Es wurden nicht alle Knoten erreicht.\n";
			g->setAllUnvisited();
			cout << endl;
		}
		else if (bef == 3)
		{
			cout << "Bitte Startknoten angeben: >? "; cin >> key;

			if (g->breadthSearch(g, g->GetNodeByKey(key)))
				cout << "Alle Knoten erreicht.\n";
			else cout << "Es wurden nicht alle Knoten erreicht.\n";
			g->setAllUnvisited();
			cout << endl;
		}
		else if (bef == 4)
		{
			cout << "Bitte Startknoten angeben: >? "; cin >> key;
			g->prim(key);
			g->setAllUnvisited();
			cout << endl;
		}
		else if (bef == 5)
		{
			g->kruskal();
			g->setAllUnvisited();
			cout << endl;
		}
		else if (bef == 6)
		{
			g->print();
			cout << endl;
		}

	}

	delete g;
	return 0;
}
