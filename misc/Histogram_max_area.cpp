#include<bits/stdc++.h>
using namespace std;
int findMaxArea(int a[],int n)
{
	stack<int>s;
	int m=0,i;
	int t,area;
	for(i=0;i<n;i++)
	{
		if(s.empty())
		s.push(i);
		else
		{
			while(!s.empty()&&a[s.top()]>a[i])
			{
				t=s.top();
				s.pop();
				if(s.empty())
				{
					area=a[t]*i;
				}
				else
				{
					area=a[t]*(i-s.top()-1);
				}
				m=max(m,area);
			}
			s.push(i);
		}
	}
	while(!s.empty())
	{
		t=s.top();
		s.pop();
				if(s.empty())
				{
					area=a[t]*i;
				}
				else
				{
					area=a[t]*(i-s.top()-1);
				}
				m=max(m,area);
	}
	return m;
	
}
int main()
{
	int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << findMaxArea(hist, n);
}
