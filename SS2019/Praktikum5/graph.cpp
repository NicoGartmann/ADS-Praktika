#include "graph.h"

Graph::Graph() {

}

Graph::~Graph() {

}

GraphNode* Graph::GetNodeByKey(int key) {

}

void Graph::setAllUnvisited() {

}

bool Graph::checkVisited() {

}

void Graph::startDepthSearchRek(GraphNode* node) {

}

bool Graph::testChildComponent(GraphNode* node) {

}

bool Graph::init(string path) {
	ifstream file;
	file.open("graph1.txt", std::ios_base::in);
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
		}

		//Alle Kanten anlegen
		while (std::getline(file, line)) {
			//TODO
		}
		return true;
	}
	return false; 
}

bool Graph::printAll() {

}

bool Graph::depthSearchRek(int startKey) {

}

bool Graph::breathSearchIter(int startKey) {

}

double Graph::prim(int startKey) {

}

double Graph::kruskal() {

}

int Graph::getAnzahlKnoten() {
	return this->_anzKnoten; 
}

