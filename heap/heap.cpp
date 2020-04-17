#include <bits/stdc++.h>
using namespace std;
bool isHeap(int arr[],int i,int n)
{
    if(i>=(n-2)/2)
        return true;
    if(arr[i]>=arr[2*i+1]&&arr[i]>=arr[2*i+2]&&isHeap(arr,2*i+1,n)&&isHeap(arr,2*i+2,n))
    {
        return true;
    }
    return false;
}
int main()
{
    int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
    int n = sizeof(arr) / sizeof(int);

    isHeap(arr, 0, n)? printf("Yes"): printf("No");

    return 0;
}