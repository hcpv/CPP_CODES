#include <bits/stdc++.h>
using namespace std;
#define ull long long int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull n;
    cin>>n;
    ull h[n][n],v[n][n],l[n][n];
    for(ull j=0;j<n;j++)
    {
        for(ull i=0;i<n;i++)
            cin>>h[j][i];
    }
    for(ull j=0;j<n;j++)
    {
        for(ull i=0;i<n;i++)
            cin>>v[j][i];
    }
    ull c=0;
    for(ull j=0;j<n;j++)
    {
        for(ull i=0;i<n;i++)
        {
            l[j][i]=max(h[j][i],v[j][i]);
            c=c+l[j][i];
        }
    }
    ull p=-1,q=-1;
    for(ull j=0;j<n-1;j++)
    {
        for(ull i=0;i<n-1;i++)
        {
            if(l[j][i]==h[j][i]&&l[j+1][i+1]==v[j+1][i+1]||l[j][i]==v[j][i]&&l[j+1][i+1]==h[j+1][i+1])
            {
                if(i!=q||j!=p) {
                    c = c - l[j][i] - l[j + 1][i + 1];
                    c = c + max(v[j][i] + v[j + 1][i + 1], h[j][i] + h[j + 1][i + 1]);
                    p = j + 1;
                    q = i + 1;
                }
            }

        }
    }
    cout<<c;


}