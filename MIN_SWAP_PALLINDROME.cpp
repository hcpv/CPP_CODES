#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
  int A[256]={0};
  string s;
  s="abcabcdde";
  int n=s.size();
  for(int i=0;i<n;i++)
  {
    A[s[i]]++;
  }
  int o=0;
  for(int i=0;i<256;i++)
  {
    if(A[i]%2!=0)
    o++;
  }
  if(o>1)
  {
    cout<<"IMPOSSIBLE";
  }
  else
  {
    int sol=0;
    for(int i=0;i<n/2;i++)
    {
      int j=n-1-i;
      if(s[i]!=s[j])
      {
        int k,l;
        for(k=i+1;s[k]!=s[j];k++);
        for(l=j-1;s[i]!=s[l];l--);
        sol+=min(k-i,j-l);
        if(k-i<j-l)
        {
          for(l=k;l>i;l--)
          {
            char t=s[l];
            s[l]=s[l-1];
            s[l-1]=t;
          }
        }
        else
        {
          for(k=l;k<j;k++)
          {
            char t=s[k];
            s[k]=s[k+1];
            s[k+1]=t;
          }
        }
      }
    }
    cout<<s<<endl;
    cout<<sol<<endl;
  }

}
