#include<bits/stdc++.h>
using namespace std;
int factorial(int n)
{
	if(n==1||n==0)
		return 1;
	return n*factorial(n-1);
}
int main()
{
	string a;
	cin>>a;
	long s=0;
	int l=a.length();
	int sm=0,f;
	//int a[256];
	for (int i = 0; i < l; ++i)
	{
		/* code */

	}
	for (int i = 0; i < l; ++i)
	{
		sm=0;
		for (int j = i; j < l; ++j)
		{
			
			if(a[i]>a[j])
				sm++;
			
		}
		f=factorial(l-i-1);
		cout<<sm<<"  "<<f<<endl;
		s+=sm*f;
	}
	cout<<(s+1);
}