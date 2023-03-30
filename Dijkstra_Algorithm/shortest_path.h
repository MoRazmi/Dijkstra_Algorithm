#pragma once

#include "graph.h"
#include "priority_queue.h"
#include "list.h"

using node = graph::node;
using distance = Priority_Queue::distance;

class path
{
public:
	path();

	void path_add_node(node new_node);
	list<node> path_get(node start, node end);
	Priority_Queue::distance path_get_size();

private:
	list<node> path_list;
};