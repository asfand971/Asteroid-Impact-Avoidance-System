#include "AHeap.h"
AHeap::AHeap()
{
	heap_size = 0;
	capacity = 5;
	harr = new int[5];
}
AHeap::AHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

int AHeap::parent(int indx)
{
	return (indx - 1) / 2;
}
int AHeap::left(int indx)
{
	return (2 * indx + 1);
}
int AHeap::right(int indx)
{
	return (2 * indx + 2);
}

int AHeap::getMin()
{
	return harr[0];
}
void AHeap::insertKey(int newval)
{
	if (heap_size == capacity)
	{
		cout << "Can not insert Key" << endl;
		return;
	}
	heap_size++;
	int indx = heap_size - 1;
	harr[indx] = newval;
	while (indx != 0 && harr[parent(indx)] > harr[indx])
	{
		swap(&harr[indx], &harr[parent(indx)]);
		indx = parent(indx);
	}
	cout << "Key = " << newval << " has been inserted in heap !" << endl;
}
void AHeap::decreaseKey(int old_val, int new_val)
{
	int loc = 0;
	for (int indx = 0; indx < heap_size; indx++)
	{
		if (harr[indx] == old_val)
		{
			harr[indx] = new_val;
			loc = indx;
		}
	}
	while (loc != 0 && harr[parent(loc)] > harr[loc])
	{
		swap(&harr[loc], &harr[parent(loc)]);
		loc = parent(loc);
	}
}
int AHeap::extractMin()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		delete harr;
		return 0;
	}
	int root = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	MinHeapify(0);
	return root;
}
void AHeap::deleteKey(int indx)
{
	if (indx == getMin())
	{
		extractMin();
		cout << "Min deleted" << endl;

	}
	else
	{
		decreaseKey(indx, INT_MIN);
		extractMin();
		cout << "Key = " << indx << " has been deleted from the heap !" << endl;
	}
}
void AHeap::MinHeapify(int indx)
{
	int l = left(indx);
	int r = right(indx);
	int smallest = indx;
	if (l < heap_size && harr[l] < harr[indx])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != indx)
	{
		swap(&harr[indx], &harr[smallest]);
		MinHeapify(smallest);
	}
}
void AHeap::swap(int* val1, int* val2)
{
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}
void AHeap::display()
{
	for (int indx = 0; indx < heap_size; indx++)
	{
		cout << harr[indx] << " ";
	}
	cout << endl;
}
