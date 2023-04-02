
#include <iostream>
#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"

using namespace std;

int main()
{ 
	graph g_test(9);
	graph::node first_node = 0;
	graph::node second_node = 2;
	graph::edge edge = 3.0;

	g_test.add_edge(first_node, second_node, edge);
#if 1
	g_test.add_edge(0, 1, 4);
	g_test.add_edge(0, 4, 7);
	g_test.add_edge(1, 3, 1);
	g_test.add_edge(3, 5, 1);
	g_test.add_edge(4, 5, 1);
	g_test.add_edge(3, 4, 3);
	g_test.add_edge(2, 4, 4);
	g_test.add_edge(5, 7, 2);
	g_test.add_edge(7, 8, 3);
	g_test.add_edge(5, 8, 4);
	g_test.add_edge(4, 8, 3);
	g_test.add_edge(4, 6, 5);
	g_test.add_edge(6, 8, 5);


	dijkstra_algorrithm path(g_test, 0);
	(void)path.shortest_path(8);

#endif
	return 0;
}