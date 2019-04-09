#include <iostream>
#include <string>
#include <fstream>
#include "Tree.h"
using namespace std;


int main() {

	int index;
	string name;
	int alter;
	double einkommen;
	int plz;
	int rang = 0;
	Tree *baum = new Tree();
	cout << " ==================================== " << endl;
	cout << "Person Analyzer v19.84, by George Orwell" << endl;
	cout << " ==================================== " << endl;
	cout << "1) Datensatz einfuegen, manuell" << endl;
	cout << "2) Datensatz einfuegen, CSV Datei" << endl;
	cout << "3) Datensatz loeschen " << endl;
	cout << "4) Suchen" << endl;
	cout << "5) Datenstruktur anzeigen" << endl;
	cout << "6) Exit" << endl;

	do {
		cout << "?> ";
		cin >> index;
		if (index == 1) {
			cout << "+ Bitte geben Sie die den Datensatz ein" << endl;
			cout << "Name ?> ";
			cin >> name;
			cout << "Alter ?> ";
			cin >> alter;
			cout << "Einkommen ?> ";
			cin >> einkommen;
			cout << "PLZ ?> ";
			cin >> plz;
			baum->addNode(name, alter, einkommen, plz, rang);
			rang++;
			cout << "+ Ihr Datensatz wurde eingefuegt" << endl;
			cout << "______________________________________________________\n\n";
		}
		else {
			if (index == 3) {
				cout << "+ Bitte geben Sie den zu loeschenden Datensatz an" << endl;
				cout << "NodePosID ?>"; 
				int data;
				cin >> data;
				baum->remove(data);
				cout << "______________________________________________________\n\n";
			}
			else {
				if (index == 4) {
					cout << "+Bitte geben Sie den zu suchenden Datensatz an " << endl;
					cout << "Name ?> ";
					string suche;
					cin >> suche;
					baum->search(suche, baum->Anker);
					cout << "______________________________________________________\n\n";
				}
				else {
					if (index == 5) {
						cout << "  ID |"<<"                       Name |"<<"       Alter |"<<"       Einkommen |"<<"     PLZ |"<<"    Pos" << endl;
						cout << "-----+----------------------------+-------------+-----------------+---------+-------" << endl;
						baum->print(baum->Anker);
						cout << "______________________________________________________\n\n";
					}
					else {
						if (index == 2) {
							string file1 = "ExportZielanalyse.csv";
							string file2 = "ExportZielanalyse_Fall2.csv"; 
							string file3 = "ExportZielanalyse_Fall3.csv";
							string dateiname = file3;
							string auswahl;

							do
							{
								cout << "+ Soll die Datei mit dem Namen \"" + dateiname + "\" wirklich eingelesen werden? (y/n)\n ?>";
								cin >> auswahl;

								if (auswahl != "y" && auswahl != "n")
								{
									cout << "+ Ungueltige Eingabe! ja = y, nein = n \n";
								}
							} while (auswahl != "y" && auswahl != "n");

							if (auswahl == "y")
							{
								// Import file
								ifstream datei(dateiname);
								// Get lines & split em
								string zeile;
								while (getline(datei, zeile))
								{
									string Name, sAlter, sEinkommen, sPLZ;
									int Alter, PLZ;
									double Einkommen;

									unsigned int ix = 0;
									// Get Name
									for (; ix < zeile.length(); ix++)
									{
										if (zeile.at(ix) != ';')
										{
											Name += zeile.at(ix);
										}
										else
										{
											ix++;
											break;
										}
									}

									// Get Alter
									for (; ix < zeile.length(); ix++)
									{
										if (zeile.at(ix) != ';')
										{
											sAlter += zeile.at(ix);
										}
										else
										{
											ix++;
											break;
										}
									}
									Alter = stoi(sAlter);	// Parse Alter

															// Get Einkommen
									for (; ix < zeile.length(); ix++)
									{
										if (zeile.at(ix) != ';')
										{
											sEinkommen += zeile.at(ix);
										}
										else
										{
											ix++;
											break;
										}
									}
									Einkommen = stod(sEinkommen);	// Parse Einkommen

																	// Get PLZ
									for (; ix < zeile.length(); ix++)
									{
										if (zeile.at(ix) != ';')
										{
											sPLZ += zeile.at(ix);
										}
										else
										{
											ix++;
											break;
										}
									}
									PLZ = stoi(sPLZ);	// Parse PLZ

														// Create Object
									baum->addNode(Name, Alter, Einkommen, PLZ, rang);
									rang++;

								}
								cout << "Dateien wurden hinzugefuegt.\n"; 
								cout << "______________________________________________________\n\n";
							}
							else
							{
								cout << "Dateien wurden NICHT hinzugefuegt.\n";
								cout << "______________________________________________________\n\n";
							}
						}
					}
				}
			}
		}
	} while (index != 6);

	return 0;
}