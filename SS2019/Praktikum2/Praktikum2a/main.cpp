/*************************************************
* ADS Praktikum 2.1
* main.cpp
*
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.hpp"
using namespace std;

void displayMenue() {
	cout << endl; 
	cout << "OneRingToRuleThemAll v0.1, by Sauron Schmidt" << endl; 
	cout << "==================================" << endl; 
	cout << "1) Backup einfuegen" << endl; 
	cout << "2) Backup suchen" << endl;
	cout << "3) Alle Backups ausgeben" << endl;
	cout << "4) Beenden" << endl; 
	cout << "?> "; 
}

int main()
{
	// int result = Catch::Session().run();
	// Ihr Code hier:
	Ring* myRing = new Ring(); 
	int bef = 0; 
	string besch, dat;
	while (bef != 4) {
		displayMenue(); 
		cin >> bef; 
		cout << endl; 
		switch (bef) {
		case 1:
			cout << "+Neuen Datensatz einfuegen" << endl;
			cout << "Beschreibung ?> "; cin >> besch;  
			cout << "Daten ?> "; cin >> dat; 
			cout << "+Ihr Datensatz wurde hinzugefuegt." << endl; 
			myRing->addNode(besch, dat); 
			break; 
		case 2: 
			cout << "+Nach welchen Daten soll gesucht werden?" << endl; 
			cout << "?> "; 
			getline(cin, dat); 
			if (myRing->search(dat)) {
				cout << "+ Gefunden in Backup:" << endl; 
			}
			else {
				cout << "+ Datensatz konnte nicht gefunden werden." << endl; 
			}
			break; 
		case 3:
			myRing->print(); 
			cout << endl; 
			break; 
		}
	}


	//
	///////////////////////////////////////
	system("Pause");
	return 0;
}
