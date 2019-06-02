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
class MaxHeap
{
    ull *heap;
    int capacity;
    int size;

public:
    //Constructor
    MaxHeap(int capacity);

    int size_heap()
    {
        return size;
    }

    //to heapify a subtree
    void MaxHeapify(int );

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
    int extract_maximum();

    //Increase the value at index i to new_val
    void increase_value(int i,int new_val);

    int maximum(){
        return heap[0];
    }

    //delete key at index i
    void deleteKey(int i);

    //insert new key k
    void insertKey(int k);
};
MaxHeap::MaxHeap(int cap)
{
    size=0;
    capacity=cap;
    heap=new ull[capacity];
}
//heapify_down
void MaxHeap::MaxHeapify(int i)
{
    int l=left(i);
    int r=right(i);
    int largest=i;
    if(l<size&&heap[l]>heap[i])
        largest=l;
    if(r<size&&heap[r]>heap[largest])
        largest=r;
    if(largest!=i)
    {
        swap(heap[i],heap[largest]);
        MaxHeapify(largest);
    }

}

int MaxHeap::extract_maximum()
{
    if(size==0)
    {
        cout<< "Can’t remove element as queue is empty";
        return -1;
    }
    int max=heap[0];
    heap[0]=heap[size-1];
    size--;
    cout<<size<<maximum()<<endl;
    MaxHeapify(0);
    return max;
}

void MaxHeap::increase_value(int i, int new_val)
{
    heap[i]=new_val;
    // we have to fix violated heap property //heapify_up
    while(i!=0&&heap[parent(i)]<heap[i])
    {
        swap(heap[parent(i)],heap[i]);
        i=parent(i);
    }
}

void MaxHeap::deleteKey(int i)
{
    increase_value(i,INT_MAX);
    extract_maximum();
}

void MaxHeap::insertKey(int k)
{
    if (size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }
    size++;
    heap[size-1]=-1;
    increase_value(size-1,k);
}

int main()
{
    MaxHeap h(INT_MAX);
    int n,d;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        h.insertKey(d);
    }
    int q;
    cin>>q;
    while(q--)
    {
        cin>>n;
        if(n==1)
        {
            cin>>d;
            h.insertKey(d);
        }
        else
            cout<<h.maximum()<<endl;
    }
}
