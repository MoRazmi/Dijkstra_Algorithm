#include "priority_queue.h"
#include <vector>
#include "graph.h"

using namespace std;
using node = graph::node;
using distance = Priority_Queue::distance;


/**
* Priority Queue constructor
*/
Priority_Queue::Priority_Queue() {}
Priority_Queue::Priority_Queue(node)
{}


void Priority_Queue::pq_insert(node node_start, distance distance_input)
{
    openlist.push(make_pair(distance_input , node_start));
}



node  Priority_Queue::pq_minPriority()
{
    node node_poped = openlist.top().second;
    openlist.pop();
    return node_poped;
};

void Priority_Queue::pq_changePriotiy(node node_input, distance distance_input)
{
    // create temporary priority queue to store all nodes except the one with the specified node id
    priority_queue<pair<Priority_Queue::distance, graph::node>, vector<pair<Priority_Queue::distance, graph::node>>, greater<pair<Priority_Queue::distance, graph::node>>> temp;

    while (!openlist.empty())
    {
        if (openlist.top().second == node_input)
        {
            // if the node is found, update its distance and reinsert it into the priority queue
            openlist.pop();
            openlist.push(make_pair(distance_input, node_input));
            break;
        }
        else
        {
            // otherwise, add the current node to the temporary priority queue
            temp.push(openlist.top());
            openlist.pop();
        }
    }

    // add all remaining nodes from the temporary priority queue back into the main priority queue
    while (!temp.empty())
    {
        openlist.push(temp.top());
        temp.pop();
    }
}

bool Priority_Queue::pq_contains(node node_input)
{
    priority_queue<pair<distance, graph::node>, vector<pair<distance, graph::node>>, greater<pair<distance, graph::node>>> temp = openlist;

        // search for the node in the priority queue
        while (!temp.empty())
        {
            if (temp.top().second == node_input)
            {
                return true;
            }
            temp.pop();
        }

    return false;
}


node Priority_Queue::pq_top()
{
    return openlist.top().second;
}

node Priority_Queue::pq_size()
{
    return openlist.size();
}