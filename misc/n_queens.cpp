#include <bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000000007
#define pace ios::sync_with_stdio(false);cin.tie(0)

bool is_attacked(ull x,ull y,ull **a,ull n)
{
    for(ull i=0;i<n;i++)
    {
        if(a[x][i]==1)
            return true;
        if(a[i][y]==1)
            return true;
        for(ull j=0;j<n;j++)
        {
            if((i+j==x+y)&&a[i][j]==1)
                return true;
            if((i-j==x-y)&&a[i][j]==1)
                return true;
        }
    }
    return false;
}
bool n_queens(ull s,ull **a,ull n)
{
    if(n==0)
        return true;
    for(ull i=0;i<s;i++)
    {
        for(ull j=0;j<s;j++) {
            if (is_attacked(i, j, a, s)) {
                continue;
            }
            a[i][j] = 1;//Place current queen at cell (i,j)
            if (n_queens(s,a, n - 1)) // Solve subproblem
                return true;// if solution is found
            a[i][j] = 0; /* if solution is not found undo whatever changes
                                       were made i.e., remove  current queen from (i,j)*/
        }
    }
    return false;
}
int main()
{
    ull n;
    cin>>n;
    ull **a=new ull*[n];
    for(ull i=0;i<n;i++)
    {
        a[i]=new ull[n];
    }
    for(ull i=0;i<n;i++)
    {
        for(ull j=0;j<n;j++)
            a[i][j]=0;
    }
    if(n_queens(n,a,n))
    {
        cout<<"YES"<<endl;
        for(ull i=0;i<n;i++)
        {
            for(ull j=0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
    else
    {
        cout<<"NO";
    }
}