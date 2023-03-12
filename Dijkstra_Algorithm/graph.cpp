#include "graph.h"
#include <vector>

using namespace std;

/**
* Graph constructor
*/
graph::graph() 
{}

graph::graph(int num_nodes)
{
	nodes.resize(num_nodes);
}

const int graph::get_num_nodes(void)
{
	return nodes.size();
}

const int graph::get_num_edges(void)
{
	int num_non_zero_element = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		for (int j = 0; j < edges[i].size(); j++)
		{
			if (edges[i][j] != 0)
			{
				++num_non_zero_element;
			}
		}
	}
	int num_edges = num_non_zero_element / 2;
	
	return num_edges;
}

const bool graph::is_connected(int x, int y)
{
	return(edges[x][y] != 0);
}

const vector<pair<int, double>> graph::get_neighbors(int x)
{
	
	vector<pair<int, double>> neighbors;
	for (int i = 0; i < get_num_nodes(); i++)
	{
		double weight = edges[x][i];
		if (weight != 0)
		{
			neighbors.push_back(make_pair(i, weight));
		}
	}

	return neighbors;
}

void graph::add_edge(const int x, const int y, const double edge)
{
	edges[x][y] = edge;
	edges[y][x] = edge;
}

void graph::delete_edge(const int x, const int y)
{
	edges[x][y] = edges[y][x] = 0.0;
}

const double graph::get_edge_value(const int x, const int y)
{
	return edges[x][y];
}