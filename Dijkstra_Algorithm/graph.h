#pragma once

#include <vector>

using namespace std;

class graph
{
public:
	graph();

	typedef int node;
	typedef double edge;

	const size_t get_num_nodes(void);
	const int get_num_edges(void);
	const bool is_connected(node node_x, node node_y);
	vector<pair<node, edge>> get_neighbors(node node_x);
	void add_edge( node node_x, node  node_y, const edge connecting_edge);
	void delete_edge(const node node_x, const node node_y);
	const edge get_edge_value( node node_x,  node node_y);


private:
	vector<node> nodes;
	vector<vector<edge>> edges;
};

