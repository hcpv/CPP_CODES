#include <bits/stdc++.h>
using namespace std;
#define ull long long int
#define pace ios::sync_with_stdio(false);cin.tie(0)
ull d,x,y;
ull modularExponent(ull x,ull y,ull m)
{
    ull result=1;
    while(y>0)
    {
        if(y%2==1)
            result=(result*x)%m;
        x=(x*x)%m;
        y=y/2;
    }
    return result;

}
void extendedEuclid(long long int c,long long int m)
{
    if(m == 0)
    {
        d = c;
        x = 1;
        y = 0;
    }
    else
    {
        extendedEuclid(m, c%m);
        long long int temp = x;
        x= y;
        y = temp - (c/m)*y;
    }
}
long long int modInverse(int c, int M)
{
    extendedEuclid(c,M);
    return (x%M+M)%M;
}
int main()
{
    pace;
    ull a,b,c,m;
    cin>>a>>b>>c>>m;
    ull r=(modularExponent(a,b,m)*(modInverse(c,m)%m))%m;
    cout<<r;

}