#pragma once
#include <vector>
#include <list>
using namespace std;

class GraphNode
{
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

	//Maybe helpful for your Work
	GraphNode(int pkey);
	bool hasNeighbor(int neighborKey);
	edge getEdgeByNeigborkey(int pkey);

	int _key;
	vector<edge> _edges;
	bool _visited;
	double _distance;
	GraphNode *_prev;
	int _component;

};
