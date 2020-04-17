#include<bits/stdc++.h>
using namespace std;
int main()
{
  int sol;
  int n=2;
  int fact[n];
  fact[0]=1;
  fact[1]=1;
  for(int i=2;i<n;i++)
  {
    fact[i]=fact[i-1]*i;
  }
  for(int i=1500000;i>=1;i--)
  {
    int temp=i,sum=0;
    while(temp>0)
    {
      int d=temp%n;
      temp/=n;
      sum+=fact[d];
    }
    if(i==sum)
    {
      sol=sum;
      cout<<sol<<endl;
    }
  }
  //cout<<sol<<endl;
}
