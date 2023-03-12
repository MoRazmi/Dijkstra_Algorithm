#pragma once

#include "node.h"
#include <vector>

using namespace std;

class graph
{
public:
	graph();
	graph(int numNodes);
	graph(vector<pair<int, double>>& edges);
	graph(vector<pair<double, double>>& position);

	void addEdge(int start, int end);
	void addNode(int NodeId);
	void addNode(double x, double y);
	void addNode(int NodeId, double x, double y);

private:
	vector<node*> nodes;
	vector<vector<int, double>> edges;
};

