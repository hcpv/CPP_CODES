#include <iostream>
using namespace std;
int count=0;
void merge(int *a,int *c,int s,int m,int e)
{
    int j=m+1;
    int i=s;
    int p=e-s+1;
    int b[p];
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
    int n;
    cin>>n;
    int *a=new int[n];
    int *c=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        c[i]=i+1;
    }
    merge_sort(a,c,0,n-1);
    int e=0;
    (int i=0;i<n;i++)
    {
        for (int j = 0; j < i; j++) {
            if (c[j] > c[i])
                e++;
        }
    }
    cout<<e;

}