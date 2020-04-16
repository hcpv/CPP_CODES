#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n=5;
  int A[]={4,5,3,6,2};
  vector<int>gr(n,-1);
  stack<int>s;
  s.push(0);
  //cout<<n<<endl;
  for(int i=1;i<n;i++)
  {
    while(!s.empty()&&A[i]>A[s.top()])
    {
      s.pop();
    }
    if(!s.empty())
    gr[i]=s.top();
    s.push(i);
  }
  int sol=0;
  for(int i=0;i<n;i++)
  {
    cout<<gr[i]<<endl;
    if(gr[i]==-1)
    sol+=i;
    else
    sol+=(i-gr[i]);
  }
  cout<<sol<<endl;
}
