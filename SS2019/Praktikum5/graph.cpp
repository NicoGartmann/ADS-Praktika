#include "graph.h"

Graph::Graph() {

}

Graph::~Graph() {

}

GraphNode* Graph::GetNodeByKey(int key) {
	GraphNode* tmp = new GraphNode(key); 
	return tmp; 
}

void Graph::setAllUnvisited() {

}

bool Graph::checkVisited() {
	return true; 
}

void Graph::startDepthSearchRek(GraphNode* node) {

}

bool Graph::testChildComponent(GraphNode* node) {
	return true; 
}

bool Graph::init(string path) {
	ifstream file;
	file.open(path, std::ios_base::in);
	if (!file) {
		std::cout << "Cannot open file." << std::endl;
					return false;
	}
	else {
		std::string line;
		std::getline(file, line);
		std::istringstream iss(line);

		iss >> _anzKnoten;

		//Alle Knoten anlegen 
		for (int i = 0; i < _anzKnoten; i++) {
			//TODO
			GraphNode* currentNode = new GraphNode(i); 
			_nodes.push_back(currentNode); 
		}

		//Alle Kanten anlegen
		while (std::getline(file, line)) {
			//TODO
			std::istringstream edges(line);
			int from, value, to;
			if (!(edges >> from >> to >> value)) { break; } // error
			GraphNode* currentNode = GetNodeByKey(from);
			GraphNode* currentNeighbour = GetNodeByKey(to);
			//Hinrichrung:
			GraphNode::edge edge(currentNode, currentNeighbour, value);
			currentNode->addEdge(edge);
			//Rückrichtung:
			GraphNode::edge backEdge(currentNeighbour, currentNode, value);
			currentNeighbour->addEdge(backEdge);
		}
		return true;
	}
	return false; 
}

bool Graph::printAll() {
	return true; 
}

bool Graph::depthSearchRek(int startKey) {
	return true; 
}

bool Graph::breathSearchIter(int startKey) {
	return true; 
}

double Graph::prim(int startKey) {
	return double(startKey); 
}

double Graph::kruskal() {
	return 0.0; 
}

int Graph::getAnzKnoten() {
	return this->_anzKnoten; 
}

