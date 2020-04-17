#include <bits/stdc++.h>
using  namespace std;
void merge(int *a,int *b,int s,int m,int e)
{
    int i=s;
    int j=m+1;
    int p=e-s+1;
    int *c=new int[p];
    int *d=new int[p];
    int k=0;
    while(i<=m&&j<=e)
    {
        if(a[i]>=a[j])
        {
            c[k]=a[i];
            d[k]=b[i];
            i++;
        }
        else
        {
            c[k]=a[j];
            d[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<=m)
    {
        c[k]=a[i];
        d[k]=b[i];
        i++;
        k++;
    }
    while(j<=e)
    {
        c[k]=a[j];
        d[k]=b[j];
        j++;
        k++;
    }
    for(int l=s;l<=e;l++)
    {
        a[l]=c[l-s];
        b[l]=d[l-s];
    }
}
void merge_sort(int *a,int *b,int s,int e)
{
    if(s<e)
    {
        int m=(s+e)/2;
        merge_sort(a,b,s,m);
        merge_sort(a,b,m+1,e);
        merge(a,b,s,m,e);
    }
}

int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    int *b=new int[n];
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        a[i]=(int)s[i];
        b[i]=i+1;
    }
    merge_sort(a,b,0,n-1);
    s=(char)a[0];
    char y=(char)a[0];
    int p=b[0];
    for(int i=1;i<n;i++)
    {
        if(b[i]>p&&(char)a[i]!=y)
        {
            p=b[i];
            y=(char)a[i];
            s=s+(char)a[i];
        }
    }
    /*for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" "<<b[i]<<endl;
    }*/
    cout<<s;

}