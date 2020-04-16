#include<bits/stdc++.h>
using namespace std;
int main()
{
  vector<vector<int>>pre{{2,5},{7,17}};
  int n=pre.size();
  int m=pre[0].size();
  vector<vector<int>>A(n,vector<int>(m));
  A[0][0]=pre[0][0];
  for(int i=1;i<m;i++)
  {
    A[0][i]=pre[0][i]-pre[0][i-1];
  }
  for(int i=1;i<n;i++)
  {
    A[i][0]=pre[i][0]-pre[i-1][0];
  }
  for(int i=1;i<n;i++)
  {
    for(int j=1;j<m;j++)
    {
      A[i][j]=pre[i][j]+pre[i-1][j-1]-pre[i-1][j]-pre[i][j-1];
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cout<<A[i][j]<<" ";
    }
    cout<<endl;
  }
}
