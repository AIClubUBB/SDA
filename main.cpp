#include <iostream>
#include "P11.h"
#include "TestP11.h"
using namespace std;

struct Heap {
    int n; // Size of the heap
    TElem v[];
};
int left(int i)
{
    return 2 * i + 1;
}
int right(int i)
{
    return 2 * i + 2;
}
void heapify(Heap& h, int i)
{
    int l = left(i), r = right(i), m = i;
    if (l < h.n && h.v[i] > h.v[l])
        m = l;
    if (r < h.n && h.v[m] > h.v[r])
        m = r;
    if (m != i) {
        swap(h.v[m], h.v[i]);
        heapify(h, m);
    }
}
void removeMin(list<TElem>& elements, int k)
{
    if(k<=0)
    {
        exception e;
        throw e;
    }
    Heap h;
    h.n=elements.size();
    h.v[h.n];
    int index=0;
    for (list<int>::iterator it=elements.begin(); it != elements.end(); it++,index++)
    {
        h.v[index]=*it;
    }
    int pozStart=0;
    while(k!=0)
    {
        heapify(h,pozStart);
        k/=2;
        pozStart+=k;
    }

}

int main()
{
    testP11();
    return 0;
}
