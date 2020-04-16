#include "bits/stdc++.h"
using namespace std;
int main()
{
  string a,b;
  cin>>a>>b;
  if(a.size()!=b.size())
  {
    cout<<"NO";
  }
  else
  {
    int e=0,o=0;
    int n=a.size();
    for(int i=0;i<n;i+=2)
    {
      e^=a[i];
      e^=b[i];
    }
    for(int i=1;i<n;i+=2)
    {
      o^=a[i];
      o^=b[i];
    }
    if(e==0&&o==0)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
  }
}
