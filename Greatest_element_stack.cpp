#include <bits/stdc++.h>
using namespace std;
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
    int b[n],c[n];
    stack <int>d;
    d.push(0);
    //next greatest element
    for(int i=1;i<n;i++)
    {
        while (!d.empty())
        {
            if(a[d.top()]<a[i])
            {

                b[d.top()]=i;
                d.pop();
            }
            else
            {
                break;
            }
        }
        d.push(i);
    }
    while(!d.empty())
    {
        b[d.top()]=-1;
        d.pop();
    }
    d.push(0);
    //next smallest element
    for(int i=1;i<n;i++)
    {
        while (!d.empty())
        {
            int pos=d.top();
            if(a[pos]>a[i])
            {
                c[pos]=i;
                d.pop();
            }
            else
            {
                break;
            }
        }
        d.push(i);
    }
    while(!d.empty())
    {
        c[d.top()]=-1;
        d.pop();
    }


}