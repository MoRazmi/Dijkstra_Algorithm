#include "shortest_path.h"
#include "priority_queue.h"
#include "Path_Element.h"
#include <iostream>

using node = graph::node;
using edge = graph::edge;
using distance = Priority_Queue::distance;



/**
* The Dijkstra Algorithm Constructor
* Which get the graph as input and starting node
*/
dijkstra_algorrithm::dijkstra_algorrithm(graph graph_in, node node_start) : G(graph_in), preceedors(graph_in.get_num_nodes()), start(node_start) {}


/**
* The Dijstra Algorithm destrcutor
*/
dijkstra_algorrithm::~dijkstra_algorrithm()
{
    closed_list.clear();
    vector<Path_Element<node>>().swap(preceedors);
}


/**
* Check whether a node is in the closed list 
*/
bool dijkstra_algorrithm::is_node_in_closed_list(node new_node)
{
    for (vector<node>::const_iterator it = closed_list.begin(); it != closed_list.end(); ++it)
    {
        if (*it == new_node)
        {
            return true;
        }
    }
    return false;
}

/**
* Find the shortest path from source to destination node
*/
list<node> dijkstra_algorrithm::shortest_path( node end)
{
    list<node> path;

    Priority_Queue pq;
    pq.pq_insert(start, 0);
    preceedors[start] = Path_Element<node>(start);

    while (pq.pq_size() != 0)
    {
        node u = pq.pq_topMinPriority().first;

        if (u == end)
        {
            Path_Element<node>* current = &preceedors[end];

            // Construct the path by following predecessors backwards
            while (current != nullptr)
            {
                cout << current<< endl;
                path.push_front(current->node);
                current = &preceedors[current->get_predecessor()->node];
            }

            break; // Exit the while loop
        }


        vector<pair<node, double>> neighbors = G.get_neighbors(u);
        for (int i = 0; i < neighbors.size(); i++)
        {
            double new_dist = neighbors[i].second + pq.pq_topMinPriority().second;
            node v = neighbors[i].first;

            if (!is_node_in_closed_list(v))
            {
                pq.pq_insert(v, new_dist);
            }


            if (preceedors[v].node == -1 || new_dist < pq.pq_topMinPriority().second)
            {
                pq.pq_changePriotiy(v, new_dist);
                preceedors[v] = Path_Element<node>(v, &preceedors[u]);
            }
        }

        closed_list.push_back(u);
        (void)pq.pq_popMinPriority();

    }
    return path;
}