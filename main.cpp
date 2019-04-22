#include <iostream>
#include "P11.h"
#include "TestP11.h"
#include <algorithm>
#include <vector>

using namespace std;

struct Heap {
    int n; // Size of the heap
    vector<TElem> v;
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
    cout<<k<<" "<<elements.size()<<endl;
    if(k<=0)
    {
        exception e;
        throw e;
    }
    if(k >= elements.size())
    {
        list<TElem> aux;
        elements = aux;
        return;
    }
    Heap h;
    h.n=elements.size();
    //cout<<h.n<<endl;
    int k_aux = k;
    //copy(elements.begin(), elements.end(), h.v);
    int index=0;
    for(auto it=elements.begin();it!=elements.end();it++,index++)
    {
        h.v.push_back(*it);
        //cout<<h.v[h.v.size()-1]<<endl;
        //int val=*it;
        //cout<<index<<" "<<*it<<endl;
        //h.v[index]=val;
    }
    //cout << h.v[h.n - 1] << endl;
    index=0;
    int pozStart=0;

    while(k!=0)
    {
        cout<<pozStart<< " "<<k<<endl;
        heapify(h,pozStart);
        k/=2;
        pozStart+=k;
    }
    while(!elements.empty())
    {
        elements.pop_back();
    }
    cout << elements.size();
    for(int i=k_aux;i<h.v.size();i++)
    {
        elements.push_back(h.v[i]);
    }
}

int main()
{
    testP11();
    return 0;
}
