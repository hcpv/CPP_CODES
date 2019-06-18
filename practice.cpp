#include <iostream>
using namespace std;
int sti(string x)
{
	char ch;
	int ans=0;
	int p=1;
	int d;
	int l=x.length();
	for(int i=l-1;i>=0;i--)
	{
		ch=x[i];
		d=ch-'0';
		ans+=d*p;
		p*=10;
	}
	return ans;
}
void swap(string &x,int i,int j)
{
	char temp=x[i];
	x[i]=x[j];
	x[j]=temp;
}
void swapMax(string x,int s,int &max,int c,int l,int h)
{
	if(l>=h)
	return;
	if(c==s)
	{
		if(sti(x)>max)
		max=sti(x);
		return;
	}
	for(int i=l;i<h;i++)
	{
		swap(x,l,i);
		swapMax(x,s,max,c+1,l+1,h);
		swap(x,l,i);
	}
}
int main()
{
	int s;
	string x;
	cin>>x>>s;
	
	int l=x.length();
	int max=-100000;
	swapMax(x,s,max,0,0,l);
	cout<<max;
}
