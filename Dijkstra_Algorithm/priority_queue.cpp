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

/**
* Priority Queue desstructor
*/
Priority_Queue::~Priority_Queue() = default;

void Priority_Queue::pq_insert(node node_start, distance distance_input)
{
    openlist.push(make_pair(node_start, distance_input));
}



pair<node, Priority_Queue::distance>  Priority_Queue::pq_popMinPriority()
{
    pair<node, distance> node_poped = openlist.top();
    openlist.pop();
    return node_poped;
};

void Priority_Queue::pq_changePriotiy(node node_input, distance distance_input)
{
    // create temporary priority queue to store all nodes except the one with the specified node id
    priority_queue<pair<graph::node, Priority_Queue::distance>, vector<pair<graph::node, Priority_Queue::distance>>, greater<pair<graph::node, Priority_Queue::distance>>> temp;

    while (!openlist.empty())
    {
        if (openlist.top().first == node_input)
        {
            // if the node is found, update its distance and reinsert it into the priority queue
            openlist.pop();
            openlist.push(make_pair(node_input, distance_input));
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
    priority_queue<pair<graph::node, distance>, vector<pair<graph::node, distance>>, greater<pair<graph::node, distance>>> temp = openlist;

        // search for the node in the priority queue
        while (!temp.empty())
        {
            if (temp.top().first == node_input)
            {
                return true;
            }
            temp.pop();
        }

    return false;
}


pair<node, Priority_Queue::distance> Priority_Queue::pq_topMinPriority()
{
    return openlist.top();
}

size_t Priority_Queue::pq_size()
{
    return openlist.size();
}