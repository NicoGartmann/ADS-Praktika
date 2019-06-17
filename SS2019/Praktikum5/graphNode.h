#pragma once
#include "graph.h"
#include <vector>

class GraphNode {
public:
	struct edge; 

private : 
	int _key;
	vector<edge> _edges; 
	bool _visited; 
	int _component; 

public: 
	GraphNode(int key); 
	int getKey(); 
	void setKey(int value); 
	bool getVisited(); 
	void setVisited(bool value); 
	void addEdge(edge value); 
	edge* getEdge(int value); 
	int getNumberOfEdges(); 
	int getComponent(); 
	void setComponent(int value); 

};