#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n=5;
  int b=3;
  int A[]={10,20,30,40,50};
  vector<int>q;
  int sol=0;
  for(int i=0;i<n;i++)
  {
    while(!q.empty()&&q.front()<=i-b)
    {
      q.erase(q.begin());
    }
    while(!q.empty()&&A[q.back()]>A[i])
    {
      q.pop_back();
    }
    q.push_back(i);
    
    sol+=A[q.front()];
  }
  cout<<sol;
}
