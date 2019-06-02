#include<bits/stdc++.h>
using namespace std;
int factorial(int n)
{
	if(n==1||n==0)
		return 1;
	return n*factorial(n-1);
}
void reduceCount(int *ch, char c)
{
	for (int i = c; i <256; ++i)
	{
		/* code */
		ch[i]--;
	}
}
int main()
{
	int m=1000003;
	string a;
	cin>>a;
	long s=0;
	int l=a.length();
	int sm=0,f,t;
	int ch[256]={0};
	int re[256]={0};
	for (int i = 0; i < l; ++i)
	{
		ch[a[i]]++;
		re[a[i]]++;
	}
	for (int i = 1; i < 256; ++i)
	{
		/* code */
		ch[i]+=ch[i-1];
	}
	for (int i = 0; i < l; ++i)
	{
		sm=ch[a[i]-1];
		f=factorial(l-i-1);
		=
		t=sm*f;
		for (int i = 0; i < 256; ++i)
		{
			/* code */
			if(re[i]>1)
			{
			
				t/=factorial(re[i]);
			}
		}
		s+=t;

		reduceCount(ch,a[i]);
		re[a[i]]--;
	}
	cout<<(s+1);
}