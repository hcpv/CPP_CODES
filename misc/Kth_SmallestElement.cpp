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
    int *heap;
    int capacity;
    int size;

public:
    //Constructor
    MaxHeap(int a[],int size);



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

    void replaceMax(int x){
        heap[0]=x;
        MaxHeapify(0);
    }
    //delete key at index i
    void deleteKey(int i);

    //insert new key k
    void insertKey(int k);
};
MaxHeap::MaxHeap(int a[],int s)
{
    size=s;
    heap=a;
    int i=(size-1)/2;
    while(i>=0)
    {
        MaxHeapify(i);
        i--;
    }
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
//using maxHeap
int kthSmallest(int arr[],int n,int k)
{
    MaxHeap mh(arr,k);

    for(int i=k;i<n;i++)
    {
        if(arr[i]<mh.maximum())
        {
            mh.replaceMax(arr[i]);
        }
    }
    return mh.maximum();
}
//Using temporary array
int kthLargest(int arr[],int n,int k)
{
    int a[k];
    for(int i=0;i<k;i++)
        a[i]=arr[i];
    sort(a,a+k);
    for(int i=k;i<n;i++)
    {
        if(a[0]<arr[i])
        {
            a[0]=arr[i];
            sort(a,a+k);
        }

    }
    return a[0];
}
int main()
{
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr)/sizeof(arr[0]), k = 4;
    cout << "K'th smallest element is " <<  kthLargest(arr, n, k);
}
