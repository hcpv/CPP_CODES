#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<int>A({19,9,8,10,13});
  int n=A.size();
  sort(A.begin(),A.end());
  int sol=0;
  for(int i=0;i<n-2;i++)
  {
    int t=A[i]+A[i+1];
    int l=i+2;
    int r=n-1;
    int s;
    while(l<=r)
    {
      int mid=(l+r)/2;
      if(A[mid]<t)
      {
        s=mid;
        l=mid+1;
      }
      else
      r=mid-1;
    }
    
    sol=max(sol,s-i+1);
  }
  cout<<sol<<endl;
}
