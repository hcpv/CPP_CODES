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
void max_heapify(int arr[],int i,int n)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&arr[i]<arr[l])
        largest=l;
    if(r<n&&arr[largest]<arr[r])
        largest=r;
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        max_heapify(arr,largest,n);
    }
    return;
}

void heap_sort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        max_heapify(arr,i,n);
    for(int i=n-1;i>=1;i--)
    {
        swap(arr[0],arr[i]);
        max_heapify(arr,0,i);
       /* for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";*/
        //cout<<endl;
    }
    return;
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    //max_heapify(arr,0,n);
    heap_sort(arr, n);

    cout << "Sorted array is \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
