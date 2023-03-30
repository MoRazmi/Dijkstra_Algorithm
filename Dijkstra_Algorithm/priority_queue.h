#pragma once
#include <vector>
#include <queue>
#include "graph.h"
using namespace std;
using node = graph::node;

class Priority_Queue
{

public:
	Priority_Queue();
	Priority_Queue(node start_node);

	typedef double distance;

	void pq_insert(node node_input, distance distance_input);
	node pq_minPriority(void);
	void pq_changePriotiy(node node_input, distance distance_input);
	bool pq_contains(node node_input);
	node  pq_top();
	node pq_size();

private:
	priority_queue < pair<distance, node>, vector<pair<distance, node >>, greater<pair<distance, node>>> openlist;// pair of node and its priority
};

