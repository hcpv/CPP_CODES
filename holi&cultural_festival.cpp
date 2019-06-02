#include <bits/stdc++.h>
using namespace std;
void merge(int *a,int *b,int *f,int s,int m,int e)
{
    int i=s;
    int j=m+1;
    int p=e-s+1;
    int *c=new int[p];
    int *d=new int[p];
    int *g=new int[p];
    int k=0;
    while(i<=m&&j<=e)
    {
        if(a[i]<a[j])
        {
            c[k]=a[i];
            d[k]=b[i];
            g[k]=f[i];
            i++;
        }
        else
        {
            c[k]=a[j];
            d[k]=b[j];
            g[k]=f[j];
            j++;
        }
        k++;
    }
    while(i<=m)
    {
        c[k]=a[i];
        d[k]=b[i];
        g[k]=f[i];
        i++;
        k++;
    }
    while(j<=e)
    {
        c[k]=a[j];
        d[k]=b[j];
        g[k]=f[j];
        j++;
        k++;
    }
    for(int l=s;l<=e;l++)
    {
        a[l]=c[l-s];
        b[l]=d[l-s];
        f[l]=g[l-s];
    }
}
void merge_sort(int *a,int *b,int *c,int s,int e)
{
    if(s<e)
    {
        int m=(s+e)/2;
        merge_sort(a,b,c,s,m);
        merge_sort(a,b,c,m+1,e);
        merge(a,b,c,s,m,e);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n,p,d,m;
    cin>>n>>p>>d>>m;
    int *a=new int[3*n];
    int *b=new int[3*n];
    int *c=new int[3*n];
    for(int i=0;i<3;i++)
    {
        int k=0;
        for(int j=3*i;j<3*i+n;j++)
        {cin>>a[j];
            b[j]=k++;
            c[j]=i;
            //cout<<b[j]<<endl;
        }
    }
    merge_sort(a,b,c,0,3*n-1);
    for(int i=0;i<3*n;i++)
        cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
    long r=0;
    int z=b[3*n-1];
    for(int i=3*n-1;i>=0;i--)
    {
        if(p==0&&d==0&&m==0)
            break;
        else {
            if (p!=0&&c[i]==0&&b[i]!=-1)
            {
                if(i==3*n-1) {
                    r += a[i];
                    for(int j=0;j<3*n;j++)
                    {
                        if(b[j]==b[i])
                            b[j]=-1;
                    }
                    int g=i;
                    while(z==b[g])
                        g--;
                    z=b[g];
                }
                else
                {
                    if(b[i]!=z&&b[i]!=-1)
                    {
                        z=b[i];
                        r+=a[i];
                        for(int j=0;j<3*n;j++)
                        {
                            if(b[j]==b[i])
                                b[j]=-1;
                        }

                    }
                }
                p--;
            }
            if (d!=0&&c[i]==1&&b[i]!=-1)
            {
                if(i==3*n-1) {
                    r += a[i];
                    for(int j=0;j<3*n;j++)
                    {
                        if(b[j]==b[i])
                            b[j]=-1;
                    }
                    int g=i;
                    while(z==b[g])
                        g--;
                    z=b[g];
                }
                else
                {
                    if(b[i]!=z&&b[i]!=-1)
                    {
                        z=b[i];
                        r+=a[i];
                        for(int j=0;j<3*n;j++)
                        {
                            if(b[j]==b[i])
                                b[j]=-1;
                        }

                    }
                }
                d--;
            }
            if (m!=0&&c[i]==2&&b[i]!=-1)
            {
                if(i==3*n-1) {
                    r += a[i];
                    for(int j=0;j<3*n;j++)
                    {
                        if(b[j]==b[i])
                            b[j]=-1;
                    }
                    int g=i;
                    while(z==b[g])
                        g--;
                    z=b[g];
                }
                else
                {
                    if(b[i]!=z&&b[i]!=-1)
                    {
                        z=b[i];
                        r+=a[i];
                        for(int j=0;j<3*n;j++)
                        {
                            if(b[j]==b[i])
                                b[j]=-1;
                        }

                    }
                }
                m--;
            }
        }

    }

    cout<<r;
}