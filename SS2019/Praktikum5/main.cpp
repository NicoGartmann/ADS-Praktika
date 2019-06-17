#include "graph.h"
#include "graphNode.h"
#include "catch.h"
#include <iostream>
using namespace std;

void displayMenue() {
	cout << "Working on Graphs. Please choose:\n";
	cout << "1) Graph einlesen\n";
	cout << "2) Tiefensuche\n"; 
	cout << "3) Breitensuche\n"; 
	cout << "4) Prim\n"; 
	cout << "5) Kruskal\n"; 
	cout << "6) Print Graph\n"; 
	cout << "0) Exit\n"; 
	cout << ">? ";
}

void displayFiles() {
	cout << "Welche Datei moechten Sie einlesen?:\n"; 
	cout << "1) graph1.txt\n"; 
	cout << "2) graph2.txt\n"; 
	cout << "3) graph3.txt\n"; 
	cout << ">? "; 
}

void chooseFile(Graph* g, int bef) {
	bool success; 
	switch (bef) {
	case 1:
		success = g->init("graph1.txt");
		success ? cout << "Graph1.txt erfolgreich eingefuegt.\n\n" : cout << "Graph1.txt konnte nicht eingefuegt werden.\n\n";
		break;
	case 2:
		success = g->init("graph2.txt");
		success ? cout << "Graph2.txt erfolgreich eingefuegt.\n\n" : cout << "Graph2.txt konnte nicht eingefuegt werden.\n\n";
		break;
	case 3:
		success = g->init("graph3.txt");
		success ? cout << "Graph3.txt erfolgreich eingefuegt.\n\n" : cout << "Graph3.txt konnte nicht eingefuegt werden.\n\n";
		break;
	}
}

int main() {
	Graph* myGraph = new Graph(); 
	int bef, file, start; 
	double kosten; 
	bool success; 
	while (bef != 0) {
		do {
			displayMenue(); 
			cin >> bef; 
			cout << endl; 
		} while (bef < 0 || bef >6);

		switch (bef) {
		case 1:
			do {
				displayFiles(); 
				cin >> file; 
				cout << endl; 
			} while (file < 1 || file>3); 
			chooseFile(myGraph, file); 
			break; 
		case 2:
			cout << "Bitte geben Sie den Startpunkt ein: "; 
			cin >> start; 
			cout << "\nTiefensuche wird gestartet.\n"; 
			success = myGraph->depthSearchRek(start); 
			success ? cout << "Tiefensuche war erfolgreich.\n\n" : cout << "Tiefensuche war nicht erfolgreich.\n\n"; 
			break; 
		case 3:
			cout << "Bitte geben Sie den Startpunkt ein: "; 
			cin >> start;
			cout << "\nBreitensuche wird gestartet.\n"; 
			success = myGraph->breathSearchIter(start); 
			success ? cout << "Breitensuche war erfolgreich.\n\n" : cout << "Breitensuche war nicht erfolgreich.\n\n"; 
			break; 
		case 4: 
			cout << "Bitte geben Sie den Startpunkt ein: "; 
			cin >> start; 
			cout << "\nPrim-Algorithmus wird gestartet.\n"; 
			kosten = myGraph->prim(start); 
			cout << "Die Kosten betragen " << kosten << ".\n\n"; 
			break; 
		case 5:
			cout << "Kruskal-Algorithmus wird gestartet.\n"; 
			kosten = myGraph->kruskal(); 
			cout << "Die Kosten betragen " << kosten << ".\n\n"; 
			break; 
		case 6:
			cout << "Ausgabe des Graphen in Adjazens-Liste:\n"; 
			success = myGraph->printAll(); 
			success ? cout << "\nDie Ausgabe des Graphens war erfolgreich\n\n" : cout << "\nDie Ausgabe des Graphens war nicht erfolgreich\n\n";
			break; 
		}
	}

	cout << "!!!Ende Gelaende!!!  Hast genug mit Graphen gespielt, geh saufen oder so!\n"; 
	system("pause"); 
	return 0; 
}