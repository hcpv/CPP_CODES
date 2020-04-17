#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<vector<int>>A({{9,17}});
  int B=18;
  int n=A.size();
  sort(A.begin(),A.end());
  int st=1,s,sol=0;
  for(int i=0;i<n;i++)
  {
    s=A[i][0]-st;
    while(s>0)
    {
      sol=sol+(s&1);
      s>>=1;
    }
    st=A[i][1]+1;
  }
  s=B+1-st;
  while(s>0)
  {
    sol=sol+(s&1);
    s>>=1;
  }
  cout<<sol;
}
