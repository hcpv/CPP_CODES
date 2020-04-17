#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,l,y=0,z;
	cin>>n;
	if((n&(n+1))==0)
	{
	    l=log2(n+1);
	    z=pow(2,l-2);
	}
	else
	{
	    l=log2(n+1);
	    z=pow(2,l-2);
	    y=n-pow(2,l)+1;
	    if(y%2!=0)
	    {
	        y++;
	    }
	}
	int x=l;
	int sum=z*2;
	cout<<sum<<endl;
	for(int i=3;i<=l;i++)
	{
		int numberOfnodes=pow(2,x-i);
		int numberOfedges=pow(2,i)-2;
		sum+=numberOfnodes*numberOfedges;
	}
	//cout<<y<<endl;
	if(y!=0)
	{
	    sum+=y*(l);
	    }
	
	cout<<sum;
}
