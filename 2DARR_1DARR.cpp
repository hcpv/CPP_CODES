#include<bits/stdc++.h>
using namespace std;
int main()
{
  vector<int>A({1,2,3,4,5,6});
  int n=2;
  int m=3;
  int x=1;
  int y=2;
  cout<<A[x*m+y]<<endl;
  cout<<"Row wise:"<<endl;
  int s=A.size();
  for(int i=0;i<s;i+=m)
  {
    for(int j=0;j<m;j++)
    {
      cout<<A[i+j]<<" ";
    }
    cout<<endl;
  }
  cout<<"Coulmn wise:"<<endl;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<s;j+=m)
    {

      cout<<A[j+i]<<" ";
    }
    cout<<endl;
  }
}
