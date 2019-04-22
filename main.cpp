#include "P11.h"
#include "TestP11.h"
#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void minHeapify(int a[], int size, int i)
{
	int l = 2 * i;
	int r = 2 * i + 1;
	int smallest = i;
	if (l<size && a[l]<a[smallest])
		smallest = l;
	if (r<size && a[r]<a[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&a[i], &a[smallest]);
		minHeapify(a, size, smallest);
	}

}
void buildMinHeap(int a[], int size) {
	for (int i = size / 2; i >= 0; i--)
		minHeapify(a, size, i);

}
void removeMin(list<TElem>& elements, int k)
{
	if (k <= 0)
	{
		exception e;
		throw e;
	}
	if (k >= elements.size())
	{
		list<TElem> aux;
		elements = aux;
		return;
	}
	static const int val = elements.size();
	TElem * elem=new TElem[elements.size()];
	int index = 0;
	for (auto it = elements.begin(); it != elements.end(); it++, index++)
	{
		elem[index] = *it;
	}
	int newK = elements.size() - k;
	TElem * minHeap=new TElem[newK];
	for (int i = 0; i<newK; i++)
		minHeap[i] = elem[i];
	buildMinHeap(minHeap, newK);
	for (TElem i = newK; i<elements.size(); i++)
	{
		if (elem[i]>minHeap[0])
		{
			minHeap[0] = elem[i];
			minHeapify(minHeap, newK, 0);
		}
	}
	while (!elements.empty())
	{
		elements.pop_back();
	}
	for (TElem i = 0; i < newK; i++)
	{
		elements.push_back(minHeap[i]);
	}

}
int main()
{
	testP11();
	return 0;
}