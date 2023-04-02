#pragma once

#include "graph.h"
#include "priority_queue.h"
#include "Path_Element.h"
#include <list>

using node = graph::node;
using distance = Priority_Queue::distance;

class dijkstra_algorrithm
{
public:
	dijkstra_algorrithm(graph graph_in, node node_start);

	list<node> shortest_path( node end);

	bool is_node_in_closed_list(node new_node);

	~dijkstra_algorrithm();

private:
	graph G;
	vector <node> closed_list;
	vector<Path_Element<node>> preceedors;
	node start;
};