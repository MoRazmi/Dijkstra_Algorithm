
#include <iostream>
#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"

using namespace std;

graph generate_radom_graph(int num_nodes, double density);

int main()
{ 
	/*
	* Lecture example code
	*/
	const node start = 0;
	const node end = 8;
	graph g_test(9);
	g_test.add_edge(start, 2, 3);
	g_test.add_edge(start, 1, 4);
	g_test.add_edge(start, 4, 7);
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

	cout << "Lecture example"<<endl;
	dijkstra_algorrithm path(g_test, 0);
	(void)path.shortest_path(end);

	/*
	* Random graph with size of 50
	*/
	cout << "Random graph with the size of 50" << endl;
	dijkstra_algorrithm path_1(generate_radom_graph(50, 0.1), 0);
	(void)path_1.shortest_path(49);

	return 0;
}


graph generate_radom_graph(int num_nodes, double density)
{
	graph g(num_nodes);

	// Seed the random number generator
	srand(time(NULL));

	// Loop over all nodes
	for (int i = 0; i < num_nodes; i++) {
		// Add 5 random edges for each node
		for (int j = 0; j < num_nodes* density; j++) {
			// Generate a random node index between 0 and num_nodes-1
			int node_index = rand() % num_nodes;

			// Make sure not to create self-loops or duplicate edges
			if (node_index != i && !g.is_connected(i, node_index)) {
				// Generate a random weight between 1 and 10
				double weight = 1 + (rand() % 10);

				// Add the edge to the graph
				g.add_edge(i, node_index, weight);
			}
		}
	}

	// Return the generated graph
	return g;
}