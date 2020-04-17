f#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>A({1,2,2,3,1});
    int n=A.size();
    vector<int>g(n,0);
    stack<int>s;
    s.push(0);
    for(int i=1;i<n;i++)
    {
      if(A[i]>A[s.top()])
      {
        while(!s.empty()&&A[i]>A[s.top()])
        {
          g[s.top()]++;
          s.pop();
        }

      }
      s.push(i);
    }
    for(int i=0;i<n;i++)
    {
      cout<<g[i]<<" ";
    }

}
