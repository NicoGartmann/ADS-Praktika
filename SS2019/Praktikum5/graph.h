#pragma once
#include "graphNode.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std; 


class Graph {
private: 
	int _anzKnoten; 
	bool _ger; 
	bool _gew; 
	vector<GraphNode*> _nodes; 

	GraphNode* GetNodeByKey(int key); 
	void setAllUnvisited(); 
	bool checkVisited(); 
	void startDepthSearchRek(GraphNode* node); 
	bool testChildComponent(GraphNode* node);

public: 
	Graph(); 
	~Graph(); 
	bool init(string file); 
	bool printAll(); 
	bool depthSearchRek(int startKey); 
	bool breathSearchIter(int startKey); 
	double prim(int startKey); 
	double kruskal(); 
	int getAnzKnoten();

};