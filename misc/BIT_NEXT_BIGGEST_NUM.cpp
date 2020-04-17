#include<bits/stdc++.h>
using namespace std;
int nearestSmallest(int n)
{
  int p1=0,p0=0;
  int c=n;
  while(c>0&&((c&1)==0))
  {
    p0++;
    c>>=1;
  }
  while((c&1)==1)
  {
    p1++;
    c>>=1;
  }
  n=n+(1<<p0)+(1<<(p1-1))-1;
  return n;
}
int nearestBiggest(int n)
{
  int p1=0,p0=0;
  int c=n;
  while((c&1)==1)
  {
    p1++;
    c>>=1;
  }
  while(((c&1)==0)&&c>0)
  {
    p0++;
    c>>=1;
  }
  n=n-(1<<p1)-(1<<(p0-1))+1;
  return n;
}
int main()
{
  int n;
  cin>>n;
  cout<<nearestBiggest(n)<<endl;
  cout<<nearestSmallest(n)<<endl;
}
