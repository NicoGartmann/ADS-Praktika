#include "graphNode.h"

GraphNode::GraphNode(int key) {

}

int GraphNode::getKey() {

}

void GraphNode::setKey(int value) {
	this->_key = value; 
}

bool GraphNode::getVisited() {
	return this->_visited; 
}

void GraphNode::setVisited(bool value) {
	this->_visited = value; 
}

void GraphNode::addEdge(edge value) {

}

/*edge* GraphNode::getEdge(int value) {

}*/

int GraphNode::getNumberOfEdges() {
	return 0; 
}

int GraphNode::getComponent() {
	return 0;  
}

void GraphNode::setComponent(int value) {

}



