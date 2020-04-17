#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int low,int high, int key)
{
  if (high < low)
    return -1;
     
  int mid = (low + high)/2; 
  if (key == arr[mid])
    return mid;
     
  if (key > arr[mid])
    return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid -1), key);
}
int findPivot(int arr[],int s,int e)
{
	if(s>e)
	return -1;
	if(s==e)
	return s;
	int m=(s+e)/2;
 if ( arr[m] > arr[m + 1])
    return m;
     
   /*if (m > s && arr[m] < arr[m - 1])
    return (m-1);*/
	if(arr[s]>=arr[m])
	return findPivot(arr,s,m-1);
	else
	return findPivot(arr,m+1,e);
}
int pivotBinarySearch(int arr[],int s,int e,int k)
{
	cout<<s<<e<<endl;
	int pivot=findPivot(arr,s,e);
	cout<<pivot<<endl;
	if(pivot==-1)
	return binarySearch(arr,s,e,k);
	if(arr[pivot]==k)
	return pivot;
	if(arr[s]<=k)
	return binarySearch(arr,s,pivot-1,k);
	return binarySearch(arr,pivot+1,e,k);
}
int main()
{
  // Let us search 3 in below array
  int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
  int n = sizeof(arr1)/sizeof(arr1[0]);
  int key = 3;
   
  // Function calling
  cout << "Index of the element is : " << 
           pivotBinarySearch(arr1,0, n-1, key);
            
  return 0;
}
