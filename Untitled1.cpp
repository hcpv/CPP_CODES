#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ull long long int
//using temporary stack 
stack<int> sort(stack<int>s)
{
	if(s.size()<=1)
	return s;
	stack<int>temp;
	int t;
	while(!s.empty())
	{
		t=s.top();
		s.pop();
		while(!temp.empty()&&t<temp.top())
		{
		    s.push(temp.top());
			temp.pop();	
		}
		temp.push(t);
	}
	return temp;
}
int main()
{
	int n;
	cout<<"Enter the size of stack"<<endl;
	cin>>n;
	stack<int>a;
	int temp;
	for(int i=0;i<n;i++)
	{
	    cin>>temp;
	    a.push(temp);
	}
	a=sort(a);
	while(!a.empty())
	{
	cout<<a.top()<<" ";
	a.pop();
}

}

