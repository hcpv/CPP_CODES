#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <iomanip>
using namespace std;
int main()
{
  int s;
  cin>>s;
  int n,x,y;
  cin>>n;
  vector<pair<int,int>>v;
  for(int i=0;i<n;i++)
  {
    cin>>x>>y;
    v.push_back(make_pair(x,y));
  }
  cout<<fixed<<setprecision(6);
  float sol=0.0,temp;
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      float dx=v[i].first-v[j].first;
      float dy=v[i].second-v[j].second;
      dx=dx*dx;
      dy=dy*dy;
      temp=sqrt(dx+dy);
      sol=max(sol,temp);
    }
  }
  sol=sol/s;
  cout<<sol<<endl;
}
