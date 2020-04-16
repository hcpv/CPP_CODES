#include <bits/stdc++.h>
using namespace std;

float convert(int n)
{
  float f ;
  f = float(n)/3;
  //cout<<f;
  cout<<fixed<<setprecision(6);

  return f;
}
int main()
{
  int n =10;
  float f=5.0;
  cout<<f;
  cout<<convert(n);

  return 0;
}
