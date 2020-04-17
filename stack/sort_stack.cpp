#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ull long long int
//sorting stack using recursion
/*void sortedInsert(stack<int>*s,int k)
{
	// Base case: Either stack is empty or newly inserted
    // item is greater than top (more than all existing)
	if(s->empty()||s->top()<k)
	{
		s->push(k);
		return;
	}
	// If top is greater, remove the top item and recur
	int temp=s->top();
	s->pop();
	sortedInsert(s,k);
	 // Put back the top item removed earlier
	s->push(temp);
	return;
}
void sortStack(stack<int>*s)
{
	 // If stack is not empty
	if(s->empty())
	return;
	// Remove the top item
	int temp=s->top();
	s->pop();
	// Sort remaining stack
	sortStack(s);
	// Push the top item back in sorted stack
	sortedInsert(s,temp);
	return;
}*/
//using temporary stack 
stack<int> sort(stack<int>s)
{
	if(s.size()<=1)
	return s;
	//cout<<10<<endl;
	stack<int>temp;
	int t;
	while(!s.empty())
	{
		t=s.top();
		s.pop();
		//cout<<10<<endl;
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
	int arr[]={40,-5,6,9,8,10,-9};
	int n=(sizeof(arr)/sizeof(arr[0]));
	stack<int>a;
	for(int i=0;i<n;i++)
	a.push(arr[i]);
	a=sort(a);
	while(!a.empty())
	{
	cout<<a.top()<<" ";
	a.pop();
}

}
