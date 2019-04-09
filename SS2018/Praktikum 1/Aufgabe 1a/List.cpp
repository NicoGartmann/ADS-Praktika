#include "List.h"
List::List()
{
	head = new Node;
	tail = new Node;
	_size = 0;
	temp = false;
	head->next = tail;
	tail->prev = head;
}
List::~List()
{
	/*(... löschen Sie alle noch vorhandenen Knoten Node dieser Instanz
		Denken Sie auch an die Knoten head und tail.)*/
	Node *tmp = head;
	while (head->next!=tail) {
		head = head->next; 
		delete tmp;
		tmp = head;
	}
	delete head; 
	delete tail; 
}

void List::InsertFront(int key)
{
	/*(... Erweitern Sie die Methode so, dass ein neuer Knoten Node vorne
	(hinter dem Knoten head) in die Liste eingefügt wird.)*/
	if (head->next == tail)
	{
		head->next = new Node(key,tail, head); 
		tail->prev = head->next; 
	}
	else
	{
		head->next->prev = new Node(key, head->next, head);
		head->next = head->next->prev; 
	}
}
void List::InsertBack(int key)
{
	/*(... Erweitern Sie die Methode so, dass ein neuer Knoten Node hinten
	(vor dem Knoten tail) in die Liste eingefügt wird.)*/
	if (head->next == tail)
	{
		head->next = new Node(key, tail, head);
		tail->prev = head->next; 
	}
	else {
		tail->prev->next = new Node(key, tail, tail->prev); 
		tail->prev = tail->prev->next;
	}
}
bool List::getFront(int & key)
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
bool List::getBack(int & key)
{
	/*(... Erweitern Sie die Methode so, dass der letzte Knoten der Liste
	(vor tail) zurückgegeben und dieser Knoten dann gelöscht wird.
		Im Erfolgsfall geben Sie true zurück, sonst false.)*/
	if (head->next == tail)
		return false; 
	else {
		key = tail->prev->key; 
		Node *tmp = tail->prev; 
		tail->prev = tmp->prev; 
		tmp->prev->next = tail;
		delete tmp;
		return true; 
	}
}
bool List::del(int key)
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
bool List::search(int key)
{
	/*(... Die Methode search sucht den Knoten mit dem Wert key
		Im Erfolgsfall geben Sie true zurück, sonst false.)*/
	if (head->next == tail)
		return false; 
	else {
		Node *tmp = head->next; 
		while (tmp->key != key && tmp != tail)
		{
			tmp = tmp->next; 
		}
		if (tmp->key == key)
			return true; 
		return false; 
	}
}
bool List::swap(int key1, int key2)
{
	/*(... Die Methode swap sucht den Knoten mit dem Wert key1,
		dann den Knoten mit dem Wert key2.Diese Knoten werden dann
		getauscht, indem die Zeiger der Knoten entsprechend geändert
		werden.)*/

	if (head->next == tail)
		return false; 
	else {
		Node *k1 = head->next; 
		Node *k2 = head->next; 
		Node *k1l; 
		Node *k1r; 
		Node *k2l; 
		Node *k2r; 

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
int List::size(void)
{
	//(... Die Methode git den Wert von size(Anzahl der Knoten in der Liste) zurück.)
	int size = 0; 
	if (head->next == tail)
	{
		size = 0; 
		return size; 
	}
	else {
		Node *tmp = head; 
		while (tmp->next != tail)
		{
			size++; 
			tmp = tmp->next; 
		}
		return size; 
	}
}
bool List::test(void)
{
	/*(... Die Methode überprüft die Pointer der Liste.Gestartet wird mit head.Es werden alle
		Knoten bis zum tail durchlaufen von dort aus dann die prev - Zeiger bis zum head.
		Bei Erfolg wird true zurück gegeben.)*/
	Node *tmp = head; 
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

void List::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	_form.start = start;
	_form.zwischen = zwischen;
	_form.ende = ende;
}

List & List::operator = (const List & _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return *this;	//  !! keine Aktion notwendig
	Node * tmp_node;
	if (_size)
	{
		Node * tmp_del;
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

List & List::operator = (const List * _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;	//  !! keine Aktion notwendig
	Node * tmp_node;
	if (_size)
	{
		Node * tmp_del;
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

List & List::operator + (const List & List_Append)
{
	Node * tmp_node;
	List * tmp;
	if (temp) {								// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List;						// this ist keine temporäre Liste -> Kopie erzeugen
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

List & List::operator + (const List * List_Append)
{
	Node * tmp_node;
	List * tmp;
	if (temp) {								// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List;						// this ist keine temporäre Liste -> Kopie erzeugen
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

std::ostream & operator<<(std::ostream  & stream, List const & Liste)
{
	stream << Liste._form.start;
	for (Node * tmp = Liste.head->next; tmp != Liste.tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.tail ? Liste._form.ende : Liste._form.zwischen);
	if (Liste.temp) delete & Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}

std::ostream & operator << (std::ostream & stream, List const * Liste)
{
	stream << Liste->_form.start;
	for (Node * tmp = Liste->head->next; tmp != Liste->tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->tail ? Liste->_form.ende : Liste->_form.zwischen);
	if (Liste->temp) delete Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}