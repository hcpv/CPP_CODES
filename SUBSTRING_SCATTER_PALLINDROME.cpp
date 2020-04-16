#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s="bbrrg";
  int n=s.size();
  vector<int>A(n+1);
  A[0]=0;
  for(int i=0;i<n;i++)
  {
    A[i+1]=A[i]^(1<<(s[i]-'a'));
  }
  int sol=0;
  for(int i=0;i<n;i++)
  {
    int t;
    for(int j=i;j<n;j++)
    {
      t=A[j+1]^A[i];
      t=t&(t-1);
      if(t==0)
      sol++;
    }
  }
  cout<<sol<<endl;
}
