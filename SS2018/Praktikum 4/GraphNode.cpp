#include "Graphnode.h"


GraphNode::GraphNode(int pkey)
{
	_key = pkey;
	_visited = false;
	_distance = 0.;
	_edges.clear();
}

bool GraphNode::hasNeighbor(int neighborKey)
{
	for (int i = 0; i < _edges.size(); i++) {
		if (_edges[i].node->_key == neighborKey) {
			return true;
		}
	}
	return false;
}

GraphNode::edge GraphNode::getEdgeByNeigborkey(int pkey)
{
	for (int i = 0; i != _edges.size(); i++)
	{
		edge currentEdge = _edges[i];
		if (currentEdge.node->_key == pkey)
		{
			return currentEdge;
		}
	}

	return GraphNode::edge(nullptr, nullptr, 0.0);
}
