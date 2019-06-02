#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ull long long int
struct activity
{
	int start,finish;
};
bool comparator(activity s1,activity s2)
{
	return s1.finish<s2.finish;
}
void printMaxActivity(activity arr[],int n)
{
	sort(arr,arr+n,comparator);
	int i=0;
	cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";
	for(int j=1;j<n;j++)
	{
		if(arr[i].finish<=arr[j].start)
		{
			cout << "(" << arr[j].start << ", " << arr[j].finish << "), ";
			i=j;
		}
	}
}
int main()
{
    struct activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMaxActivity(arr, n);
    return 0;
}
