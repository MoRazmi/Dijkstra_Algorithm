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
	pair<node, distance> pq_popMinPriority(void);
	void pq_changePriotiy(node node_input, distance distance_input);
	pair<node, distance>  pq_topMinPriority();
	size_t pq_size();

	~Priority_Queue();

private:
	struct compare_distance
	{
		bool operator() (const pair<node, distance>& lhs, const pair<node, distance>& rhs) const
		{
			return lhs.second > rhs.second;
		}
	};

	priority_queue < pair<node, distance>, vector<pair<node, distance >>, compare_distance> openlist;// pair of node and its priority

};

