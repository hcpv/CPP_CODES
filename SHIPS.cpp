#include<queue>
#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  int l=0;
  queue<int>q;
  int sol=0;
  q.push(2);
  while(l<n)
  {
    int s=q.size();
    sol=(sol+s)%m;
    while(s--)
    {
      int t=q.front();
      q.pop();
      int d=(t*t+1)%m;
      for(int i=0;i<d;i++)
      q.push(i);
    }
    l++;
  }
  cout<<sol<<endl;
}
