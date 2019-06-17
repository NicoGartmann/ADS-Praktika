#pragma once
#include "graph.h"
#include <vector>

class GraphNode {
public:
	struct edge {
		GraphNode *node; //Destination node
		double value; //Edge Weight
		GraphNode *prev; //Vorgänger

		edge() {
			node = nullptr;
			value = 0;

		}

		edge(GraphNode * either, GraphNode * other, double val)
		{
			prev = either;
			node = other;
			value = val;
		}

		bool operator<(const edge& comp) const
		{
			return value > comp.value;
		}
	};

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
	//edge* getEdge(int value); 
	int getNumberOfEdges(); 
	int getComponent(); 
	void setComponent(int value); 

};