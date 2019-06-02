#include <bits/stdc++.h>
using namespace std;
//parenthesis
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    stack <int>b;
    int max=0;
    b.push(a[0]);
    int c=0;
    for(int j=1;j<n;j++)
    {
        int p;
        if(!b.empty())
        {
            p=b.top()+a[j];
            if (p == 0&&b.top()>0)
            {
                b.pop();
                c = c + 2;
            }
            else
            {
                if (c==0||(p==0&&b.top()<0))
                {
                    b.push(a[j]);
                }
                else
                {
                    if(c>max)
                    {max=c;

                    }
                    c=0;
                    while (!b.empty())
                        b.pop();
                }
            }
        }
        else
        {
            b.push(a[j]);
        }

    }
    if(c>max)
        max=c;
    cout<<max;
}