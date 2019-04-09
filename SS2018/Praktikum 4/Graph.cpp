#include "Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <list>
#include <string>
#include <deque>
#include <queue>
using namespace std;

Graph::Graph()
{
	numNodes = 0;
	_nodes.clear();
}

Graph::~Graph()
{
	for (int i = 0; i < _nodes.size(); i++) {
		delete _nodes[i];
	}
	_nodes.clear();
}

GraphNode* Graph::GetNodeByKey(int pkey)
{
	for (int i = 0; i < numNodes; i++)
	{
		GraphNode* currentNode = _nodes[i];
		if (currentNode->_key == pkey)
		{
			return currentNode;
		}
	}
	return nullptr;
}

void Graph::setAllUnvisited()
{
	for (int i = 0; i < _nodes.size(); i++)
	{
		GraphNode* currentNode = _nodes[i];
		currentNode->_visited = false;
	}
}

bool Graph::checkVisited()
{
	for (int i = 0; i < _nodes.size(); i++)
	{
		GraphNode* currentNode = _nodes[i];
		if (currentNode->_visited == false)
			return false;
	}
	return true;
}

bool Graph::depthSearch(Graph* g, GraphNode* v)
{
	for (int i = 0; i < _nodes.size(); i++)
	{
		GraphNode* currentNode = _nodes[i];
		if (v == NULL)
			return false;
	}

	cout << v->_key << endl;
	v->_visited = true;
	for (int i = 0; i < v->_edges.size(); i++)
	{
		GraphNode::edge currentEdge = v->_edges[i]; //über kante von v
		GraphNode *dest = GetNodeByKey(currentEdge.node->_key);
		if (dest->_visited == false)
		{

			depthSearch(g, dest);
		}
	}

	if (g->checkVisited()) return true;
	else return false;
}

bool Graph::breadthSearch(Graph* g, GraphNode* v)
{
	for (int i = 0; i < _nodes.size(); i++)
	{
		GraphNode* currentNode = _nodes[i];
		if (v == NULL)
			return false;
	}

	list <GraphNode*> q;
	v->_visited = true;
	q.push_back(v);
	while (!q.empty())
	{
		v = q.front();
		cout << v->_key << endl;
		q.pop_front();
		for (int w = 0; w < v->_edges.size(); w++)
		{
			GraphNode::edge currentEdge = v->_edges[w];
			GraphNode *kind = GetNodeByKey(currentEdge.node->_key);
			if (kind->_visited == false)
			{
				kind->_visited = true;
				q.push_back(kind);
			}
		}
	}

	if (g->checkVisited()) return true;
	else return false;
}

double Graph::prim(int pKey)
{
	cout << "Starte Prim-Algorithmus !" << endl;

	priority_queue<GraphNode::edge> Q;
	GraphNode *n = GetNodeByKey(pKey);
	double kosten = 0.0;

	// Schreibe Kanten von startKey in Queue
	for (int i = 0; i < n->_edges.size(); i++)
	{
		// Kanten werden in die Queue hinzugefügt
		Q.push(n->_edges[i]);
	}

	_nodes[pKey]->_visited = true;

	// Arbeite solange, bis Queue abgearbeitet ist
	while (!Q.empty()) {
		// Wähle Kante mit niedgristen Gewicht und lösche aus Queue
		GraphNode::edge u = Q.top();
		Q.pop();

		if (!u.node->_visited) {

			// Gehe alle Kanten von nächstem Knoten durch
			for (int j = 0; j < u.node->_edges.size(); j++) {
				// Falls noch nicht besucht, füge in Queue hinzu
				if (!u.node->_edges[j].node->_visited) {
					Q.push(u.node->_edges[j]);
				}
			}
			// Kosten des MST erhöhen
			kosten += u.value;
			cout << u.prev->_key << "->" << u.node->_key << ": " << u.value << endl;

			// Knoten auf besucht setzen
			u.node->_visited = true;


		}
	}

	cout << "Die Kosten dieses MST betragen " << kosten << endl << endl;

	return kosten;
}

double Graph::kruskal()
{
	queue<GraphNode::edge> mst; // MST - Kanten
	vector<int> marked(this->_nodes.size()); // Besucht-flag
	priority_queue<GraphNode::edge> Q;
	vector<GraphNode::edge> e; // Liefert alle Kanten von G

	double kosten = 0.0;

	// Gehe alle Knoten durch
	for (int i = 0; i < _nodes.size(); i++) {
		// Gehe alle Kanten durch
		for (int j = 0; j < _nodes[i]->_edges.size(); j++) {
			// Speichere alle Kanten in e
			e.push_back(_nodes[i]->_edges[j]);
		}
	}

	// Füge alle Kanten in Queue
	for (int i = 0; i < e.size(); i++) Q.push(e[i]);
	// Fülle Vektor entsprechend der Knotenanzahl
	for (int i = 0; i < _nodes.size(); i++) marked[i] = i;

	// Arbeite Queue durch
	while (!Q.empty()) {
		GraphNode::edge e = Q.top();
		Q.pop();

		// Nachfolger
		int v = e.node->_key;
		// Vorgänger
		int w = e.prev->_key;

		// Prüfe, ob Markierung gleich, wenn ja, verwerfe
		if (marked[v] != marked[w]) {
			// Füge in MST ein
			mst.push(e);
			kosten += e.value;

			// Vorgänger der Kante
			int from = marked[e.prev->_key];

			// Setze Markierung auf Markierung von Vorgänger
			for (int i = 0; i < marked.size(); i++) {
				if (marked[i] == from) {
					marked[i] = marked[v];
				}
			}
			cout << e.prev->_key << "->" << e.node->_key << ": " << e.value << endl;
		}
	}

	cout << "Die Kosten des MST betragen " << kosten << endl << endl;

	return kosten;
}

bool Graph::init(string path)
{
	ifstream file;
	file.open(path, ios_base::in);

	if (!file)
	{
		cout << "Cannot open file.\n";
		return false;
	}
	else
	{
		string line;
		getline(file, line);
		istringstream iss(line);

		//Erste Zeile auslesen
		iss >> this->numNodes;

		//Knoten anlegen
		for (int i = 0; i < this->numNodes; i++)
		{
			GraphNode* currentNode = new GraphNode(i);
			_nodes.push_back(currentNode);

		}
		//Kanten anlegen
		while (getline(file, line))
		{
			std::istringstream edges(line);
			int from, value, to;
			if (!(edges >> from >> to >> value)) { break; } // error
			GraphNode* currentNode = GetNodeByKey(from);
			GraphNode* currentNeighbour = GetNodeByKey(to);
			//Hinrichrung:
			GraphNode::edge edge(currentNode, currentNeighbour, value);
			currentNode->_edges.push_back(edge);
			//Rückrichtung:
			GraphNode::edge backEdge(currentNeighbour, currentNode, value);
			currentNeighbour->_edges.push_back(backEdge);
		}
		return true;
	}
	return false;
}

bool Graph::print()
{
	if (_nodes.empty()) return false;
	//Print with Node ID: 1st neighbour, 2nd neighbour ...
	for (int i = 0; i < numNodes; i++)
	{
		GraphNode* currentNode = _nodes[i];
		cout << currentNode->_key << " ";
		for (int k = 0; k < currentNode->_edges.size(); k++)
		{
			if (!currentNode->_edges.empty()) {
				GraphNode::edge currentEdge = currentNode->_edges[k];
				cout << " -> " << currentEdge.node->_key << " [" << currentEdge.value << "] ";
			}
		}
		cout << endl;

	}

	return true;
}

int Graph::get_V()
{
	return numNodes;
}




