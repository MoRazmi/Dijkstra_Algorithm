#pragma once

#include <vector>

using namespace std;

class graph
{
public:
	graph();
	graph(int num_nodes);
	
	const int get_num_nodes(void);
	const int get_num_edges(void);
	const bool is_connected(int node_x, int node_y);
	const vector<pair<int, double>> get_neighbors(int node_x);
	void add_edge(const int node_x, const int node_y, const double edge);
	void delete_edge(int node_x, int node_y);
	const double get_edge_value(const int node_x, const int node_y);


private:
	vector<int> nodes;
	vector<vector<double>> edges;
};

