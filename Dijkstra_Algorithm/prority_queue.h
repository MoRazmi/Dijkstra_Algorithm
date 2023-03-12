#pragma once
#include <vector>
using namespace std;


class prority_queue
{

public:
	void pq_changePriotiy(int priority);
	int  pq_minPriority();
	bool pq_contains(int value);
	void pq_insert(int value);
	int  pq_top();
	int pq_size();

public:
	vector<int> pq_heap;

};

