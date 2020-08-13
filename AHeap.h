#include "AQueue.h"
class AHeap
{
	public:
		int* harr;
		int capacity;
		int heap_size;
		AHeap();
		AHeap(int);
		void MinHeapify(int);
		int parent(int);
		int left(int);
		int right(int);
		int extractMin();
		void decreaseKey(int, int);
		int getMin();
		void deleteKey(int);
		void insertKey(int);
		void swap(int*, int*);
		void display();
};

