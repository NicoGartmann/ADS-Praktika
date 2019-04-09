#include <iostream>
#include <string>
#include "Ringpuffer.h"
#include "RingNode.h"
using namespace std; 

int main()
{
	int eingabe;
	Ringpuffer Ring;
	cout << "1) Backup einfuegen" << endl;
	cout << "2) Backup suchen" << endl;
	cout << "3) Alle Backups ausgeben" << endl;
	cout << "99) Quit" << endl; 
	cout << "?>";
	cin >> eingabe;

	while (eingabe != 99) {
		if (eingabe == 1) {
			string besch, data;
			cout << "+Neuen Datensatz einfuegen " << endl;
			cout << "Beschreibung ?>";
			cin >> besch; 
			cout << "Daten ?>";
			cin >> data; 
			cout << "+Ihr Datensatz wurde hinzugefuegt." << endl;
			Ring.addNode(besch, data);
			cout << endl;
			cout << "----------------------------------------------------------------------" << endl;
			cout << "?>";
			cin >> eingabe;
		}
		else if (eingabe == 2) {
			string search; 
			cout << "+Nach welchen Daten soll gesucht werden?\n" << "?> "; 
			cin >> search; 
			Ring.search(search);
			cout << endl;
			cout << "----------------------------------------------------------------------" << endl;
			cout << "?>";
			cin >> eingabe;
		}
		else if (eingabe == 3) {
			Ring.print();
			cout << endl;
			cout << "----------------------------------------------------------------------" << endl;
			cout << "?>";
			cin >> eingabe;
		}
	}
	return 0;
}