#include <list>
#include <cassert>
#include "priority_queue.h"

priority_queue<int> create_pq();
vector<int> construct_heap(list<int> list);

int main() {
	priority_queue<int> pq;
	assert(heap.empty());
	
	pq = create_pq();
	assert(!heap.empty());
	assert(heap.size() == 9);
	assert(heap.top() == 105);
	
	pq.pop();
	assert(heap.top() == 95);
}

priority_queue<int> create_pq() {
	priority_queue<int> pq;
	
	pq.push(105);
	pq.push(85);
	pq.push(25);
	pq.push(5);
	pq.push(45);
	pq.push(35);
	pq.push(95);
	pq.push(55);
	pq.push(75);
	pq.push(15);
	
	return pq;
}
