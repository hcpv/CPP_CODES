#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ull long long int
struct job
{
	int start,finish,profit;
};
bool comparator(job s1,job s2)
{
	return s1.finish<s2.finish;
}
bool doNotOverlap(job s1,job s2)
{
	return s1.finish<=s2.start;
}
int findMaxProfit(job arr[],int n)
{
	int p[n];
	int max1=INT_MIN;
	sort(arr,arr+n,comparator);
	p[0]=arr[0].profit;
	max1=p[0];
	for(int i=1;i<n;i++)
	{
		p[i]=arr[i].profit;
		for(int j=0;j<i;j++)
		{
			if(doNotOverlap(arr[j],arr[i]))
			{
				p[i]=max(p[i],arr[i].profit+p[j]);
				max1=max(max1,p[i]);
			}
		}
	}
	return max1;
}
int main()
{
    job arr[] = {{1,3,5}, {2,5,6}, {7,9,2},{5,8,11}, {4,6,4}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The optimal profit is " << findMaxProfit(arr, n);
    return 0;
}
