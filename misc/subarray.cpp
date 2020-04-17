#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ull long long int
void subArraySum(int arr[],int n,int s)
{
	int curr_sum=arr[0],start=0;
	for(int i=1;i<n;i++)
	{
		while(curr_sum>s&&start<i-1)
		{
			curr_sum=curr_sum-arr[start];
			start++;
		}
		if(curr_sum==s)
		{
			cout<<" Sum found"<<start<<"-"<<i-1<<endl;
			return ;
		}
		curr_sum+=arr[i];
	}
	cout<<"No subarray";
}
//K-th Largest Sum Contiguous Subarray
int kthLargestSum(int arr[],int n,int k)
{

	int sum[n+1];
	sum[0]=0;
	sum[1]=arr[0];
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]+arr[i-1];
	}
	priority_queue<int,vector<int>,greater<int>>p;
	// loop to calculate the contigous subarray
    // sum position-wise
	for(int i=1;i<=n;i++)
	{
		int x;
		for(int j=i;j<=n;j++)
		{
			// calculates the contiguous subarray
            // sum from j to i index
		//	if(i!=0)
			x=sum[j]-sum[i-1];
		/*	else
			x=sum[j];*/
			if(p.size()<k)
			{
				p.push(x);
			}
			else
			{
				if(p.top()<x)
				{
					p.pop();
					p.push(x);
				}
			}
		}
	}
	/*while(!p.empty())
	{
	cout<<p.top()<<endl;
	p.pop();
}*/
	return p.top();
}

int main()
{
    int a[] = { 1, 2, 3, 4 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 6;
 
    // calls the function to find out the
    // k-th largest sum
    cout << kthLargestSum(a, n, 1);
    return 0;
}
