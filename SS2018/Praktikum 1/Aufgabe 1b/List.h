#pragma once
#ifndef _LIST_H
#define _LIST_H
#include "Node.h"
#include <string>
#include <iostream>

template <class T>
class List
{
	/*
	Die Klasse List dient zur Verwaltung von Knoten (Node). Mit Hilfe der Klasse List
	kann ein Stapel oder Warteschlange realisiert werden.
	*/
private:
	struct form { std::string start = "<< "; std::string zwischen = ", "; std::string ende = " >>\n"; } _form;
	Node<T> * head, *tail;			// Zeiger auf Kopf- und End-Element
	int _size;						// Länge der Kette
	bool temp;						// normalerweise false; ist true, wenn es sich um eine temoräre Liste handelt
									// die innerhalb der überladenen Operatoren angelegt wird
public:
	List();
	~List();
	void InsertFront(T key);		// Einfügen eines Knotens am Anfang
	void InsertBack(T key);		// Einfügen eines Knotesn am Ende
	bool getFront(T & key);		// Entnehmen eines Knoten am Anfang
	bool getBack(T & key);		// Entnehmen eines Knoten am Ende
	bool del(T key);				// löschen eines Knotens [key]
	bool search(T key);			// Suchen eines Knoten
	bool swap(T key1, T key2);	// Knoten in der Liste vertauschen
	int size(void);					// Größe der Lise (Anzahl der Knoten)
	bool test(void);				// Überprüfen der Zeigerstruktur der Liste
	void format(const std::string & start, const std::string & zwischen, const std::string & ende);	// Mit der format-Methode kann die Ausgabe gesteuert werden: operator <<
	List<T> & operator = (const List<T> & _List);						// Zuweisungsoperator definieren
	List<T> & operator = (const List<T> * _List);						// Zuweisungsoperator definieren
	List<T> & operator + (const List<T> & List_Append);				// Listen zusammenführen zu einer Liste
	List<T> & operator + (const List<T> * List_Append);	// Listen zusammenführen zu einer Liste
	template <typename T>
	friend std::ostream & operator << (std::ostream & stream, List<T> const & Liste);		// Ausgabeoperator überladen
	template <typename T>
	friend std::ostream & operator << (std::ostream & stream, List<T> const * Liste);		// Ausgabeoperator überladen
};

#include "List.h"

template <typename T>
List<T>::List()
{
	head = new Node<T>;
	tail = new Node<T>;
	_size = 0;
	temp = false;
	head->next = tail;
	tail->prev = head;
}

template <typename T>
List<T>::~List()
{
	/*(... löschen Sie alle noch vorhandenen Knoten Node dieser Instanz
	Denken Sie auch an die Knoten head und tail.)*/
	Node<T> *tmp = head;
	while (head->next != tail) {
		head = head->next;
		delete tmp;
		tmp = head;
	}
	delete head;
	delete tail;
}

template <typename T>
void List<T>::InsertFront(T key)
{
	/*(... Erweitern Sie die Methode so, dass ein neuer Knoten Node vorne
	(hinter dem Knoten head) in die Liste eingefügt wird.)*/
	if (head->next == tail)
	{
		head->next = new Node<T>(key, tail, head);
		tail->prev = head->next;
	}
	else
	{
		head->next->prev = new Node<T>(key, head->next, head);
		head->next = head->next->prev;
	}
}

template <typename T>
void List<T>::InsertBack(T key)
{
	/*(... Erweitern Sie die Methode so, dass ein neuer Knoten Node hinten
	(vor dem Knoten tail) in die Liste eingefügt wird.)*/
	if (head->next == tail)
	{
		head->next = new Node<T>(key, tail, head);
		tail->prev = head->next;
	}
	else {
		tail->prev->next = new Node<T>(key, tail, tail->prev);
		tail->prev = tail->prev->next;
	}
}

template <typename T>
bool List<T>::getFront(T & key)
{
	/*(... Erweitern Sie die Methode so, dass der erste Knoten der Liste
	(hinter head) zurückgegeben und dieser Knoten dann gelöscht wird.
	Im Erfolgsfall geben Sie true zurück, sonst false.)*/
	if (head->next == tail)
	{
		return false;
	}
	else {
		key = head->next->key;
		Node *tmp = head->next;
		head->next = tmp->next;
		tmp->next->prev = head;
		delete tmp;
		return true;
	}
}

template <typename T>
bool List<T>::getBack(T & key)
{
	/*(... Erweitern Sie die Methode so, dass der letzte Knoten der Liste
	(vor tail) zurückgegeben und dieser Knoten dann gelöscht wird.
	Im Erfolgsfall geben Sie true zurück, sonst false.)*/
	if (head->next == tail)
		return false;
	else {
		key = tail->prev->key;
		Node<T> *tmp = tail->prev;
		tail->prev = tmp->prev;
		tmp->prev->next = tail;
		delete tmp;
		return true;
	}
}

template <typename T>
bool List<T>::del(T key)
{
	/*(... Die Methode del sucht den Knoten mit dem Wert Key und löscht diesen
	im Erfolgsfall aus der Liste.
	Im Erfolgsfall geben Sie true zurück, sonst false.)*/
	if (head->next == tail)
		return false;
	else {
		Node *tmp = head->next;
		while (tmp->key != key && tmp != tail)
		{
			tmp = tmp->next;
		}
		if (tmp == tail)
			return false;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		delete tmp;
		return true;
	}
}

template <typename T>
bool List<T>::search(T key)
{
	/*(... Die Methode search sucht den Knoten mit dem Wert key
	Im Erfolgsfall geben Sie true zurück, sonst false.)*/
	if (head->next == tail)
		return false;
	else {
		Node<T>*tmp = head->next;
		while (tmp->key != key && tmp != tail)
		{
			tmp = tmp->next;
		}
		if (tmp->key == key)
			return true;
		return false;
	}
}

template <typename T>
bool List<T>::swap(T key1, T key2)
{
	/*(... Die Methode swap sucht den Knoten mit dem Wert key1,
	dann den Knoten mit dem Wert key2.Diese Knoten werden dann
	getauscht, indem die Zeiger der Knoten entsprechend geändert
	werden.)*/

	if (head->next == tail)
		return false;
	else {
		Node<T> *k1 = head->next;
		Node<T> *k2 = head->next;
		Node<T> *k1l;
		Node<T> *k1r;
		Node<T> *k2l;
		Node<T> *k2r;
		while (k1->key != key1 && k1 != tail)
		{
			k1 = k1->next;
		}
		if (k1->key == key1)
		{
			k1l = k1->prev;
			k1r = k1->next;
		}
		else return false;
		while (k2->key != key2 && k2 != tail)
		{
			k2 = k2->next;
		}
		if (k2->key == key2)
		{
			k2l = k2->prev;
			k2r = k2->next;
		}
		else return false;

		if (k2l == k1 && k1r == k2)
		{
			k1l->next = k2;
			k2->prev = k1l;
			k1r->prev = k2;
			k2->next = k1;

			k2l->next = k1;
			k1->prev = k2;
			k2r->prev = k1;
			k1->next = k2r;
		}
		else if (k1l == k2 && k2r == k1)
		{
			k1l->next = k2;
			k2->prev = k1;
			k1r->prev = k2;
			k2->next = k1r;

			k2l->next = k1;
			k1->prev = k2l;
			k2r->prev = k1;
			k1->next = k2;
		}
		else {
			k1l->next = k2;
			k2->prev = k1l;
			k1r->prev = k2;
			k2->next = k1r;

			k2l->next = k1;
			k1->prev = k2l;
			k2r->prev = k1;
			k1->next = k2r;
		}

		return true;

	}

}

template <typename T>
int List<T>::size(void)
{
	//(... Die Methode git den Wert von size(Anzahl der Knoten in der Liste) zurück.)
	int size = 0;
	if (head->next == tail)
	{
		size = 0;
		return size;
	}
	else {
		Node<T> *tmp = head;
		while (tmp->next != tail)
		{
			size++;
			tmp = tmp->next;
		}
		return size;
	}
}

template <typename T>
bool List<T>::test(void)
{
	/*(... Die Methode überprüft die Pointer der Liste.Gestartet wird mit head.Es werden alle
	Knoten bis zum tail durchlaufen von dort aus dann die prev - Zeiger bis zum head.
	Bei Erfolg wird true zurück gegeben.)*/
	Node<T> *tmp = head;
	while (tmp != tail)
	{
		tmp = tmp->next;
	}
	if (tmp != tail)
		return false;
	while (tmp != head)
	{
		tmp = tmp->prev;
	}
	if (tmp != head)return false;
	return true;
}

template <typename T>
void List<T>::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	_form.start = start;
	_form.zwischen = zwischen;
	_form.ende = ende;
}

template <typename T>
List<T> & List<T>::operator = (const List<T> & _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return *this;	//  !! keine Aktion notwendig
	Node<T> * tmp_node;
	if (_size)
	{
		Node<T> * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventuell vorhandenen Knoten in this löschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		_size = 0;
		head->next = tail;
		tail->prev = head;
	}
	tmp_node = _List.head->next;
	while (tmp_node != _List.tail)
	{
		InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List.temp) delete & _List;		// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}

template <typename T>
List<T> & List<T>::operator = (const List<T> * _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;	//  !! keine Aktion notwendig
	Node<T> * tmp_node;
	if (_size)
	{
		Node<T> * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventuell vorhandenen Knoten in this löschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		_size = 0;
		head->next = tail;
		tail->prev = head;
	}
	tmp_node = _List->head->next;
	while (tmp_node != _List->tail)
	{
		InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List->temp) delete _List;		// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}

template <typename T>
List<T> & List<T>::operator + (const List<T> & List_Append)
{
	Node<T> * tmp_node;
	List<T> * tmp;
	if (temp) {								// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List<T>;						// this ist keine temporäre Liste -> Kopie erzeugen
		tmp->temp = true;					// Merker setzten, dass es sich um eine temporäre Liste handelt
		tmp_node = head->next;
		while (tmp_node != tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append._size) {				// anhängen der übergebenen Liste an tmp
		tmp_node = List_Append.head->next;
		while (tmp_node != List_Append.tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append.temp) delete & List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht							// 
	return *tmp;
}

template <typename T>
List<T> & List<T>::operator + (const List<T> * List_Append)
{
	Node<T> * tmp_node;
	List<T> * tmp;
	if (temp) {								// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List<T>;						// this ist keine temporäre Liste -> Kopie erzeugen
		tmp->temp = true;					// Merker setzten, dass es sich um eine temporäre Liste handelt
		tmp_node = head->next;
		while (tmp_node != tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append->_size) {				// anhängen der übergebenen Liste an tmp
		tmp_node = List_Append->head->next;
		while (tmp_node != List_Append->tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append->temp) delete List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht							// 
	return *tmp;
}

template <typename T>
std::ostream & operator<<(std::ostream  & stream, List<T> const & Liste)
{
	stream << Liste._form.start;
	for (Node<T> * tmp = Liste.head->next; tmp != Liste.tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.tail ? Liste._form.ende : Liste._form.zwischen);
	if (Liste.temp) delete & Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}

template <typename T>
std::ostream & operator << (std::ostream & stream, List<T> const * Liste)
{
	stream << Liste->_form.start;
	for (Node<T> * tmp = Liste->head->next; tmp != Liste->tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->tail ? Liste->_form.ende : Liste->_form.zwischen);
	if (Liste->temp) delete Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}
#endif

