#include<bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000000007
#define pace ios::sync_with_stdio(false);cin.tie(0)
void swap(int &a,int &b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}
class MinHeap
{

    int *heap;
    int capacity;
    int size;

public:
    //Constructor
    MinHeap(int arr,int n);

    int size_heap()
    {
        return size;
    }
    //to heapify a subtree
    void MinHeapify(int );

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }

    //to extract maximum element i.e.root
    int extract_minmum();

    //insert new key k
    void insertKey(int k);
    void buildHeap();

    MinHeap(int *arr, int n);
};
MinHeap::MinHeap(int arr[],int n)
{
    size=n;
    heap=arr;
    buildHeap();
}
void MinHeap::buildHeap() {
    int n=size;
    for(int i=(n-2)/2;i>=0;i--)
        MinHeapify(i);
}
//heapify_down
void MinHeap::MinHeapify(int i)
{
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if(l<size&&heap[l]<heap[i])
        smallest=l;
    if(r<size&&heap[r]<heap[smallest])
        smallest=r;
    if(smallest!=i)
    {
        swap(heap[i],heap[smallest]);
        MinHeapify(smallest);
    }

}

int MinHeap::extract_minmum()
{
    if(size==0)
    {
        cout<< "Can’t remove element as queue is empty";
        return -1;
    }
    int max=heap[0];
    heap[0]=heap[size-1];
    size--;
    MinHeapify(0);
    return max;
}

void MinHeap::insertKey(int k)
{
    if (size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
    size++;
    heap[size-1]=k;
    int i=size-1;
    while(i&&heap[i]<heap[parent(i)])
    {
        swap(heap[i],heap[parent(i)]);
        i=parent(i);
    }
}
int minCost(int arr[],int n)
{
    MinHeap mh(arr,n);
    int cost=0;
    while(mh.size_heap()!=1)
    {
        int min=mh.extract_minmum();
        int secMin=mh.extract_minmum();
        cost+=min+secMin;
        mh.insertKey(min+secMin);
    }
    return cost;
}

int main()
{
    int len[] = {4, 3, 2, 6};
    int size = sizeof(len)/sizeof(len[0]);
    cout << "Total cost for connecting ropes is " << minCost(len, size);
    return 0;
}
