#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<int>A({1,4,3,2,6,5,8,7});
  int n=A.size();
  vector<int>lm(n);
  vector<int>rm(n);
  lm[0]=A[0];
  rm[n-1]=A[n-1];
  for(int i=1;i<n;i++)
  {
    lm[i]=max(A[i],lm[i-1]);
    rm[n-1-i]=min(A[n-1-i],rm[n-i]);
  }
  int sol=1;
  for(int i=0;i<n-1;i++)
  {
    if(lm[i]<=rm[i+1])
    sol++;
  }
  cout<<sol<<endl;
}
