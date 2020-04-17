#include <bits/stdc++.h>
using namespace std;
int count=0;
void merge(int *a,int *c,int s,int m,int e)
{
    int j=m+1;
    int i=s;
    int p=e-s+1;
    int *b=new int[p];
    int *d=new int[p];
    int k=0;
    while(i<=m&&j<=e)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            d[k]=c[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            d[k]=c[j];
            j++;
        }
        k++;
    }
    while(i<=m)
    {
        b[k]=a[i];
        d[k]=c[i];
        k++;
        i++;
    }
    while(j<=e)
    {
        b[k]=a[j];
        d[k]=c[j];
        k++;
        j++;
    }
    for(int i=s;i<=e;i++)
    {
        a[i]=b[i-s];
        c[i]=d[i-s];
    }
}
void merge_sort(int *a,int *c,int s,int e)
{
    if(s<e)
    {
        int m = (s + e) / 2;
        merge_sort(a,c, s, m);
        merge_sort(a,c, m + 1, e);
        merge(a,c, s, m, e);
    }
}
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    for(int i=0;i<t;i++)
    {
        char **a=new char*[50];
        for(int j=0;j<50;j++)
        {
            a[j]=new char[50];
        }
        int *b=new int[50];
        int c=0;
        int d=0;
        int *e=new int[50];
            string n;
            getline(cin,n);
            int l=n.length();
            for(int j=0;j<l;j++)
            {
                if(n[j]==' ')
                {
                    c++;
                    d=0;
                }
                else
                    a[c][d++]=n[j];
            }
        for(int j=0;j<=c;j++)
        {
            n=a[j];
            b[j]=n.length();
            e[j]=j+1;
        }
        merge_sort(b,e,0,c);
        for(int j=0;j<=c;j++)
        {
            cout<<b[e[j]-1]<<" ";
        }
        cout<<endl;
    }


}