#ifndef _LIST_H
#define _LIST_H
#include "Node.h"
#include <string>
#include <iostream>

template<class T>
class List
{
	/*
	Die Klasse List dient zur Verwaltung von Knoten (Node). Mit Hilfe der Klasse List
	kann ein Stapel oder Warteschlange realisiert werden.
	*/
private:
	struct form { std::string start = "<< "; std::string zwischen = ", "; std::string ende = " >>\n"; } list_form;
	Node<T> * head_tail;						// Zeiger auf Kopf- und End-Element -> next der 1. Knoten; -> prev der letzte Knoten
	int list_size;							// Länge der Kette
	bool temp;								// normalerweise false; ist true, wenn es sich um eine temoräre Liste handelt
											// die innerhalb der überladenen Operatoren angelegt wird
public:
	List();
	List(const List & _List);				// Kopie Konstruktor
	List(const List * _List);				// Kopie Konstruktor
	~List();
	void insertFront(T key);				// Einfügen eines Knotens am Anfang
	void insertFront(List & _List);			// Einfügen einer vorhandenen Liste am Anfang
	void insertFront(List * _List);			// Einfügen einer vorhandenen Liste am Anfang
	void insertBack(T key);				// Einfügen eines Knotesn am Ende
	void insertBack(List & _List);			// Einfügen einer vorhandenen Liste am Ende
	void insertBack(List * _List);			// Einfügen einer vorhandenen Liste am Ende
	bool getFront(T & key);				// Entnehmen eines Knoten am Anfang
	bool getBack(T & key);				// Entnehmen eines Knoten am Ende
	bool del(T key);						// löschen eines Knotens [key]
	bool search(T key);					// Suchen eines Knoten
	bool swap(T key1, T key2);			// Knoten in der Liste vertauschen
	int size(void);							// Größe der Lise (Anzahl der Knoten)
	bool test(void);						// Überprüfen der Zeigerstruktur der Liste
	void format(const std::string & start, const std::string & zwischen, const std::string & ende);	
											// Mit der format-Methode kann die Ausgabe gesteuert werden: operator <<
											// start: stirng vor der Ausgabe der Liste
											// zwischen: string zwischen Listenknoten
											// ende: string am Ende der Liste
	List & operator = (const List<T> & _List);						// Zuweisungsoperator definieren
	List & operator = (const List<T> * _List);						// Zuweisungsoperator definieren
	List & operator + (const List<T> & List_Append);				// Listen zusammenführen zu einer Liste
	List & operator + (const List<T> * List_Append);				// Listen zusammenführen zu einer Liste
	template<typename T>
	friend std::ostream & operator << (std::ostream & stream, List<T> const & Liste);		// Ausgabeoperator überladen
	template<typename T>
	friend std::ostream & operator << (std::ostream & stream, List<T> const * Liste);		// Ausgabeoperator überladen
	template<typename T>
	friend std::ostream & operator << (std::ostream & stream, const List<T> & Liste);
	friend Node<T>* get_anker(List<T>& l);
	friend int get_AnzahlNodes(List<T>& l);
};

#include "List.h"

template<typename T>
List<T>::List()
{
	// Konstruktor für eine leere Liste
	head_tail = new Node<T>;
	list_size = 0;
	temp = false;
	// next = head , prev = tail
	head_tail->next = head_tail;
	head_tail->prev = head_tail;
}

template<typename T>
List<T>::List(const List & _List)
{
	// Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
	// in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
	list_form = _List.list_form;
	head_tail = new Node;
	list_size = 0;
	temp = _List.temp;
	head_tail->next = head_tail;
	head_tail->prev = head_tail;
	Node * tmp_node;
	tmp_node = _List.head_tail->next;
	while (tmp_node != _List.head_tail)
	{
		head_tail->prev = new Node(tmp_node->key, head_tail->prev->next, head_tail->prev);
		head_tail->prev->prev->next = head_tail->prev;
		list_size++;
		tmp_node = tmp_node->next;
	}
	if (_List.temp) delete & _List;		// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
}

template<typename T>
List<T>::List(const List * _List)
{
	// Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
	// in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
	list_form = _List->list_form;
	head_tail = new Node<T>;
	list_size = 0;
	temp = _List->temp;
	head_tail->next = head_tail;
	head_tail->prev = head_tail;
	Node<T> * tmp_node;
	tmp_node = _List->head_tail->next;
	while (tmp_node != _List->head_tail)
	{
		head_tail->prev = new Node<T>(tmp_node->key, head_tail->prev->next, head_tail->prev);
		head_tail->prev->prev->next = head_tail->prev;
		list_size++;
		tmp_node = tmp_node->next;
	}
	if (_List->temp) delete _List;		// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
}

template<typename T>
List<T>::~List()
{
	// Dekonstruktor
	// Alle Knoten der Liste müssen gelöscht werden, wenn die Liste gelöscht wird.
/*
	hier alle Knoten löschen, die im Objekt List allokiert wurden
*/
	Node<T> * tmp_node = head_tail->next;
	while (tmp_node != head_tail) {
		head_tail->next = tmp_node->next;
		delete tmp_node;
		tmp_node = head_tail->next;
	}
	delete head_tail;
}

template<typename T>
void List<T>::insertFront(T key)
{
	// Einfügen eines neuen Knotens am Anfang der Liste
/*
	Einen neuen Knoten mit dem Schlüsselwert key am Anfang der Liste einfügen
*/
	Node<T> * new_node = new Node<T>(key, 0, 0);
	//Check if List is empty 
	if (head_tail->prev == head_tail && head_tail->next == head_tail) {
		head_tail->prev = new_node;
		head_tail->next = new_node;
		new_node->prev = head_tail;
		new_node->next = head_tail;
	}
	else if (head_tail->next != head_tail) {
		//Update previous head
		head_tail->next->prev = new_node;
		new_node->next = head_tail->next;
		new_node->prev = head_tail;
	}
	//set new head
	head_tail->next = new_node;
	this->list_size++;
}

template<typename T>
void List<T>::insertFront(List & _List)
{
	// Einfügen einer vorhandenen Liste am Anfang
	/*
	Die einzufügenden Knoten werden übernommen (nicht kopiert)
	Die einzufügende Liste _List ist anschließend leer.
	Es darf keine Schleife und kein new benutzt werden.
	*/
	/*
		Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
		Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) übertragen ohne sie zu kopieren!
	*/
	//_List empty, nothing to do
	if (!_List.list_size) return;

	//Set new head_tail for _List
	_List.head_tail->next->prev = head_tail;
	_List.head_tail->prev->next = head_tail->next;
	//Update head
	head_tail->next->prev = _List.head_tail->prev;
	head_tail->next = _List.head_tail->next;

	//empty _List
	_List.head_tail->next = _List.head_tail;
	_List.head_tail->prev = _List.head_tail;
	list_size += _List.list_size;
}

template<typename T>
void List<T>::insertFront(List * _List)
{
	// Einfügen einer vorhandenen Liste am Anfang
	/*
	Die einzufügenden Knoten werden übernommen (nicht kopiert)
	Die einzufügende Liste _List ist anschließend leer.
	Es darf keine Schleife und kein new benutzt werden.
	*/
	/*
		Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
		Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) übertragen ohne sie zu kopieren!
	*/
	if (!_List || !_List->list_size) return;
	//Set new head_tail for _List
	_List->head_tail->next->prev = head_tail;
	_List->head_tail->prev->next = head_tail->next;
	//Update head
	head_tail->next->prev = _List->head_tail->prev;
	head_tail->next = _List->head_tail->next;

	//empty _List
	_List->head_tail->next = _List->head_tail;
	_List->head_tail->prev = _List->head_tail;
	list_size += _List->list_size;
}

template<typename T>
void List<T>::insertBack(T key)
{
	// Einfügen eines neuen Knotens am Ende der Liste
/*
	Einen neuen Knoten mit dem Schlüsselwert key am Ende der Liste einfügen
*/
	Node<T> * new_node = new Node<T>(key, 0, head_tail->next);
	//Check if List is empty
	if (head_tail->prev == head_tail && head_tail->next == head_tail) {
		head_tail->prev = new_node;
		head_tail->next = new_node;
		new_node->prev = head_tail;
		new_node->next = head_tail;
	}
	else if (head_tail->prev != head_tail) {
		//Update previous tail
		head_tail->prev->next = new_node;
		new_node->prev = head_tail->prev;
		new_node->next = head_tail;
	}
	//Set new tail
	head_tail->prev = new_node;
	this->list_size++;
}

template<typename T>
void List<T>::insertBack(List & _List)
{
	// Einfügen einer vorhandenen Liste am Ende
	/*
	Die einzufügenden Knoten werden übernommen (nicht kopiert)
	Die einzufügende Liste _List ist anschließend leer.
	Es darf keine Schleife und kein new benutzt werden.
	*/
	/*
		Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
		Diese Knoten (koplette Kette) werden an das Ende der Liste (this) angehangen ohne sie zu kopieren!
	*/
	//_List empty, nothing to do
	if (!_List.list_size) return;

	//Set new head_tail for _List
	_List.head_tail->prev->next = head_tail;
	_List.head_tail->next->prev = head_tail->prev;
	//Update head
	head_tail->prev->next = _List.head_tail->next;
	head_tail->prev = _List.head_tail->prev;

	//empty _List
	_List.head_tail->next = _List.head_tail;
	_List.head_tail->prev = _List.head_tail;
	list_size += _List.list_size;
}

template<typename T>
void List<T>::insertBack(List * _List)
{
	// Einfügen einer vorhandenen Liste am Ende
	/*
	Die einzufügenden Knoten werden übernommen (nicht kopiert)
	Die einzufügende Liste _List ist anschließend leer.
	Es darf keine Schleife und kein new benutzt werden.
	*/
	/*
		Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
		Diese Knoten (koplette Kette) werden an das Ende der Liste (this) angehangen ohne sie zu kopieren!
	*/
	if (!_List || !_List->list_size) return;
	//Set new head_tail for _List
	_List->head_tail->prev->next = head_tail;
	_List->head_tail->next->prev = head_tail->prev;
	//Update head
	head_tail->prev->next = _List->head_tail->next;
	head_tail->prev = _List->head_tail->prev;

	//empty _List
	_List->head_tail->next = _List->head_tail;
	_List->head_tail->prev = _List->head_tail;
	list_size += _List->list_size;
}

template<typename T>
bool List<T>::getFront(T & key)
{
	// entnehmen des Knotens am Anfang der Liste
	// der Wert wird als Parameter zurückgegeben
	// der Knoten wird entnommen
/*
	Der Wert des vorderen Schlüsselknotens wird rückgegeben und der Knoten gelöscht.
	Die Methode del(key) darf nicht zum löschen benutzt werden.
*/
	if (list_size) {
		key = head_tail->next->key;
		Node<T> * tmp = head_tail->next;
		head_tail->next = head_tail->next->next;
		head_tail->next->prev = head_tail;
		delete tmp;
		return true;
	}
	return false;
}

template<typename T>
bool List<T>::getBack(T & key)
{	// entnehmen des Knotens am Ende der Liste
	// der Wert wird als Parameter zurückgegeben
	// der Knoten wird entnommen
/*
	Der Wert des letzten Schlüsselknotens wird rückgegeben und der Knoten gelöscht.
	Die Methode del(key) darf nicht zum löschen benutzt werden.
*/
	if (list_size && head_tail->prev != head_tail) {
		key = head_tail->prev->key;
		Node<T> * tmp = head_tail->prev;
		head_tail->prev = head_tail->prev->prev;
		head_tail->prev->next = head_tail;
		delete tmp;
		return true;
	}
	return false;
}

template<typename T>
bool List<T>::del(T key)
{
	// Löschen eines gegebenen Knotens
/*
	Löschen des Knotens mit dem Schlüssel key
*/
	Node<T> * tmp_node = head_tail->next;
	while (tmp_node->key != key && tmp_node != head_tail) {
		tmp_node = tmp_node->next;
	}
	if (tmp_node->key != key) return false;

	tmp_node->next->prev = tmp_node->prev;
	tmp_node->prev->next = tmp_node->next;

	delete tmp_node;
	this->list_size--;
	return true;
}

template<typename T>
bool List<T>::search(T key)
{
	// suchen eines Knotens
/*
	suchen ob ein Knoten mit dem Schlüssel key existiert.
*/
	Node<T> * tmp_node = head_tail->next;
	while (tmp_node != head_tail) {
		if (tmp_node->key == key) return true;
		tmp_node = tmp_node->next;
	}
	return false;
}

template<typename T>
bool List<T>::swap(T key1, T key2)
{
	// Vertauschen von zwei Knoten
	// Dabei werden die Zeiger der Knoten und deren Nachbarn verändert.
/*
	Vertauschen von zwei Knoten mit dem key1 und dem key2
	Es dürfen nicht nur einfach die Schlüssel in den Knoten getauscht werden!
	Die Knoten sind in der Kette umzuhängen.
*/
	Node<T> * tmp_node = head_tail->next;
	Node<T> * tmp_node1 = head_tail;
	Node<T> * tmp_node2 = head_tail;
	while (tmp_node != head_tail) {
		if (tmp_node->key == key1 && tmp_node1 == head_tail) tmp_node1 = tmp_node;
		//case key1 == key2, look for another node with the same key
		if (tmp_node->key == key2 && tmp_node != tmp_node1 && tmp_node2 == head_tail) tmp_node2 = tmp_node;
		tmp_node = tmp_node->next;
	}
	if (tmp_node1 == head_tail || tmp_node2 == head_tail) return false;
	//Check if one Node is head or tail, update head_tail
	if (tmp_node1->prev == head_tail) head_tail->next = tmp_node2;
	else if (tmp_node1->next == head_tail) head_tail->prev = tmp_node2;
	if (tmp_node2->prev == head_tail) head_tail->next = tmp_node1;
	else if (tmp_node2->next == head_tail) head_tail->prev = tmp_node1;
	//Check if nodes are neighbours
	if (tmp_node1->next == tmp_node2) {
		//Deep Copy tmp_node1
		tmp_node = new Node<T>(*tmp_node1);
		tmp_node1->prev->next = tmp_node2;
		tmp_node1->next = tmp_node2->next;
		tmp_node1->prev = tmp_node2;
		tmp_node2->next->prev = tmp_node1;
		tmp_node2->next = tmp_node1;
		tmp_node2->prev = tmp_node->prev;
	}
	else if (tmp_node2->next == tmp_node1) {
		tmp_node = new Node<T>(*tmp_node1);
		tmp_node1->next->prev = tmp_node2;
		tmp_node1->next = tmp_node2;
		tmp_node1->prev = tmp_node2->prev;
		tmp_node2->prev->next = tmp_node1;
		tmp_node2->next = tmp_node->next;
		tmp_node2->prev = tmp_node1;
	}
	else {
		tmp_node = new Node<T>(*tmp_node1);
		tmp_node1->next->prev = tmp_node2;
		tmp_node1->prev->next = tmp_node2;
		tmp_node1->next = tmp_node2->next;
		tmp_node1->prev = tmp_node2->prev;
		tmp_node2->next->prev = tmp_node1;
		tmp_node2->prev->next = tmp_node1;
		tmp_node2->next = tmp_node->next;
		tmp_node2->prev = tmp_node->prev;
	}
	return true;
}

template<typename T>
int List<T>::size(void)
{
	// Rückgabe der Knoten in der Liste mit O(1)
/*
	Anzahl der Knoten in der Liste zurückgeben.
*/
	return list_size;
}

template<typename T>
bool List<T>::test(void)
{
	// Testmethode: die Methode durchläuft die Liste vom Anfang bis zum Ende und zurück
	// Es werden dabei die Anzahl der Knoten gezählt.
	// Stimmt die Anzahl der Knoten überein liefert die Methode true
	Node<T> * tmp = head_tail->next;
	int i_next = 0, i_prev = 0;
	while (tmp != head_tail) {
		tmp = tmp->next;
		if (i_next > list_size) return false;
		i_next++;
	}
	if (i_next != list_size) return false;
	tmp = head_tail->prev;
	while (tmp != head_tail) {
		tmp = tmp->prev;
		if (i_prev > list_size) return false;
		i_prev++;
	}
	return i_prev == i_next;
}

template<typename T>
List<T> & List<T>::operator = (const List & _List)
{
	// in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return *this;		//  !! keine Aktion notwendig
	list_form = _List.list_form;
	Node<T> * tmp_node;
	if (list_size)
	{
		Node<T> * tmp_del;
		tmp_node = head_tail->next;
		while (tmp_node != head_tail)		// Alle eventuell vorhandenen Knoten in this löschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		list_size = 0;
		head_tail->next = head_tail;
		head_tail->prev = head_tail;
	}
	tmp_node = _List.head_tail->next;		// Die Listen-Knotenwerte werden kopiert
	while (tmp_node != _List.head_tail)
	{
		insertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List.temp) delete & _List;			// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}

template<class T>
List<T> & List<T>::operator = (const List<T> * _List)
{
	// in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;		//  !! keine Aktion notwendig
	list_form = _List->list_form;
	Node<T> * tmp_node;
	if (list_size)
	{
		Node<T> * tmp_del;
		tmp_node = head_tail->next;
		while (tmp_node != head_tail)		// Alle eventuell vorhandenen Knoten in this löschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		list_size = 0;
		head_tail->next = head_tail;
		head_tail->prev = head_tail;
	}
	tmp_node = _List->head_tail->next;
	while (tmp_node != _List->head_tail)	// Die Listen-Knotenwerte werden kopiert
	{
		insertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List->temp) delete _List;			// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}

template<typename T>
List<T> & List<T>::operator + (const List & List_Append)
{
	// Die Methode +
	// Es werden zwei Listen aneinander gehangen.
	// Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue Ergebnisliste.
	Node<T> * tmp_node;
	List<T> * tmp;
	if (temp) {										// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List(this);						// this ist keine temporäre Liste -> Kopie erzeugen
		tmp->temp = true;							// Merker setzten, dass es sich um eine temporäre Liste handelt
	}
	if (List_Append.list_size) {					// anhängen der übergebenen Liste an tmp
		tmp_node = List_Append.head_tail->next;
		while (tmp_node != List_Append.head_tail) {
			tmp->insertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append.temp) delete & List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht						
	return *tmp;
}

template<typename T>
List<T> & List<T>::operator + (const List * List_Append)
{
	// Die Methode +
	// Es werden zwei Listen aneinander gehangen.
	// Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue Ergebnisliste.
	Node<T> * tmp_node;
	List<T> * tmp;
	if (temp) {										// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List(this);						// this ist keine temporäre Liste -> Kopie erzeugen
		tmp->temp = true;							// Merker setzten, dass es sich um eine temporäre Liste handelt
	}
	if (List_Append->list_size) {					// anhängen der übergebenen Liste an tmp
		tmp_node = List_Append->head_tail->next;
		while (tmp_node != List_Append->head_tail) {
			tmp->insertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append->temp) delete List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht					
	return *tmp;
}

template<typename T>
void List<T>::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	// Setzen des Formates für die Ausgabesteuerung der Liste bei cout
	// das Format wird für den überladenen Operator << verwendet
	list_form.start = start;
	list_form.zwischen = zwischen;
	list_form.ende = ende;
}

template<class T>
std::ostream & operator << (std::ostream  & stream, List<T> const & Liste)
{
	// Ausgabe der Liste mit cout
	stream << Liste.list_form.start;
	for (Node<T> * tmp = Liste.head_tail->next; tmp != Liste.head_tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.head_tail ? Liste.list_form.ende : Liste.list_form.zwischen);
	if (Liste.temp) delete & Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}

template<class T>
std::ostream & operator << (std::ostream & stream, List<T> const * Liste)
{
	// Ausgabe der Liste mit cout
	stream << Liste->list_form.start;
	for (Node<T> * tmp = Liste->head_tail->next; tmp != Liste->head_tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->head_tail ? Liste->list_form.ende : Liste->list_form.zwischen);
	if (Liste->temp) delete Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}


#endif