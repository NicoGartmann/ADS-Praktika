#pragma once
#include "GraphNode.h"
#include <vector>
#include <map>
using namespace std;

class Graph
{
public:
	Graph();
	~Graph();

	GraphNode* GetNodeByKey(int pkey);
	void setAllUnvisited();
	bool checkVisited();

	bool depthSearch(Graph *g, GraphNode* v);
	bool breadthSearch(Graph *g, GraphNode *v);
	double prim(int pKey);
	double kruskal();
	bool init(string path);
	bool print();

	int numNodes;
	int get_V();
	bool _weighted;
	bool _directed;
	vector<GraphNode*> _nodes;
};