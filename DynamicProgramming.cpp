#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ull long long int
ull a[100001]={-1};
//factorial usin top-down DP
int solve(int x)
{
	if(x==0)
	return 1;
	if(a[x]!=-1)
	return a[x];
	return a[x]=(x*a[x-1])%mod;
}
int getNthUglyNo(int n)
{
    int ugly[n]; // To store ugly numbers
    int i2 = 0, i3 = 0, i5 = 0;
    int next_multiple_of_2 = 2;
    int next_multiple_of_3 = 3;
    int next_multiple_of_5 = 5;
    int next_ugly_no = 1;

    ugly[0] = 1;
    for (int i=1; i<n; i++)
    {
        next_ugly_no = min(next_multiple_of_2,
                           min(next_multiple_of_3,
                               next_multiple_of_5));
        ugly[i] = next_ugly_no;
        if (next_ugly_no == next_multiple_of_2)
        {
            i2 = i2+1;
            next_multiple_of_2 = ugly[i2]*2;
        }
        if (next_ugly_no == next_multiple_of_3)
        {
            i3 = i3+1;
            next_multiple_of_3 = ugly[i3]*3;
        }
        if (next_ugly_no == next_multiple_of_5)
        {
            i5 = i5+1;
            next_multiple_of_5 = ugly[i5]*5;
        }
    } /*End of for loop (i=1; i<n; i++) */
    return next_ugly_no;
}
//nth catalan number
ull catalan(int n)
{
	ull cat[n+1];
	cat[0]=cat[1]=1;
	for(int i=2;i<=n;i++)
	{
		cat[i]=0;
		for(int j=0;j<i;j++)
		{	
		    cat[i]+=(cat[j]*cat[i-1-j]);		
		}
	}
	return cat[n];
}
//Count number of ways to partition a set into k subsets:S(n,k) ,n=number of elements, k=no of subsets
int countP(int n,int k)
{
	int dp[n+1][k+1];
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(int i=0;i<=k;i++)
	{
		dp[0][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=min(i,k);j++)
		{
			if(j==i||j==1)
			dp[i][j]=1;
			else
			dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1];
		}
	}
	return dp[n][k];
}
//nCk binomial coefficient C(n, k)
int binomialCoef(int n,int k)
{
	int c[n+1][k+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=min(i,k);j++)
		{
			if(j==0||j==i)
			c[i][j]=1;
			else
			{
				c[i][j]=c[i-1][j-1]+c[i-1][j];
			}
		}
	}
	return c[n][k];
}
int permutationCoeff(int n, int k)
{
    int P[n + 1][k + 1];
 
    // Caculate value of Permutation 
    // Coefficient in bottom up manner
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= std::min(i, k); j++)
        {
            // Base Cases
            if (j == 0)
                P[i][j] = 1;
 
            // Calculate value using
            // previosly stored values
            else
                P[i][j] = P[i - 1][j] + 
                          j*( P[i - 1][j - 1]);
 
            // This step is important
            // as P(i,j)=0 for j>i
            if(i==j)
            P[i][j + 1] = 0;
        }
    }
    return P[n][k];
}
//Total number of Ways to reach in Matrix Dynamic Programming
int numberWays(int i,int j)
{
	int a[i][j];
	for(int x=0;x<i;x++)
	a[x][0]=1;
	for(int x=0;x<j;x++)
	a[0][x]=1;
	for(int x=1;x<i;x++)
	{
		for(int y=1;y<j;y++)
		{
			a[x][y]=a[x-1][y]+a[x][y-1];
		}
	}
	return a[i-1][j-1];
}
//min-cost path
int minCostPath(int a[][4],int x,int y)
{
	int b[x][y];
	for(int i=1;i<x;i++)
	{
		a[i][0]+=a[i-1][0];
	}
	for(int i=1;i<y;i++)
	{
		a[0][i]+=a[0][i-1];
	}
	for(int i=1;i<x;i++)
	{
		for(int j=1;j<y;j++)
		{
			a[i][j]+=min(a[i-1][j],a[i][j-1]);
		}
	}
	return a[x-1][y-1];
}
//Longest Common Substring
int longestCommonSubstring(string a,string b)
{
	int max=0;
	int l[a.length()][b.length()];
	for(int i=0;i<a.length();i++)
	{
		for(int j=0;j<b.length();j++)
		{
			l[i][j]=0;
			if(a[i]==b[j])
			{
				if(i==0||j==0)
				{
					if(++l[i][j]>max)
					max=l[i][j];
				}
			    else
				{
					l[i][j]=1+l[i-1][j-1];
					if(l[i][j]>max)
					max=l[i][j];
				}
			}
		}
	}
	return max;
}
//Longest Common Subsequence
int longestCommonSubsequence(string a,string b)
{
	int max1=0;
	int l[a.length()+1][b.length()+1];
	for(int i=0;i<=a.length();i++)
	l[i][0]=0;
	for(int i=0;i<=b.length();i++)
	l[0][i]=0;
	for(int i=1;i<=a.length();i++)
	{
		for(int j=1;j<=b.length();j++)
		{
			l[i][j]=0;
			if(a[i-1]==b[j-1])
			{
				l[i][j]=1+l[i-1][j-1];
				if(l[i][j]>max1)
				max1=l[i][j];
			}
			else
			{
				l[i][j]=max(l[i-1][j],l[i][j-1]);
				max1=max(max1,l[i][j]);
			}
		}
	}
	return l[a.length()][b.length()];
}
//longest increasing subsequence
int longestIncreasingSubsequence(int arr[],int n)
{
	int len[n];
	len[0]=1;
	for(int i=1;i<n;i++)
	{
		len[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			{
				len[i]=max(len[i],len[j]+1);
			}
		}
	}
	return len[n-1];
}
//Maximum sum increasing subsequence
int maxSubsequence(int arr[],int n)
{
    int sum[n];
    int m=-100000;
    for(int i=0;i<n;i++)
    {
        sum[i]=arr[i];
        m=max(m,sum[i]);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                sum[i]=max(sum[i],sum[j]+arr[i]);
                m=max(m,sum[i]);
            }
        }
    }

    return m;
}
//longest pallindromic subsequence
int lps(string str)
{
	int n=str.length();
	int L[n][n];
	for(int i=0;i<n;i++)
	{
		L[i][i]=1;
	}
	int j,cl,i;
	for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
	return L[0][n-1];
}
//egg dropping problem
int minEggBreak(int n,int k)
{
	int eggFloor[n+1][k+1];
	for (int i = 1; i <= n; i++)
    {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }
    for (int i = 1; i <= k; i++)
    {
        eggFloor[1][i] = i;
    }
    for(int i=2;i<=n;i++)
    {
    	for(int j=2;j<=k;j++)
    	{
    		if(i>=j)
    		eggFloor[i][j]=eggFloor[i-1][j];
    		else
    		{
    			int min1=INT_MAX;
    			for(int l=1;l<=j;l++)
    			{
    				int max1=max(eggFloor[i][j-l],eggFloor[i-1][l-1]);
    				min1=min(min1,max1);
				}
				eggFloor[i][j]=1+min1;
			}
		}
	}
	return eggFloor[n][k];
}
// 0-1 Knapsack Problem Dynamic Programming
int knapsack(int w,int wt[],int val[],int n)
{
	int m[n+1][w+1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(i==0||j==0)
			m[i][j]=0;
			else if(wt[i]>j)
			m[i][j]=m[i-1][j];
			else
			{
				m[i][j]=max(val[i]+m[i-1][j-wt[i]],m[i-1][j]);
			}
		}
	}
	return m[n-1][w];
}
// Subset Sum Problem
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a 
    // subset of set[0..j-1] with sum equal to i
    bool subset[n+1][sum+1];
  
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[i][0] = true;
  
    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[0][i] = false;
  
     // Fill the subset table in botton up manner
     for (int i = 1; i <= n; i++)
     {
       for (int j = 1; j <= sum; j++)
       {
         if(j<set[i-1])
         subset[i][j] = subset[i-1][j];
         if (j >= set[i-1])
           subset[i][j] = subset[i-1][j] || 
                                 subset[i - 1][j-set[i-1]];
       }
     }
  
     // uncomment this code to print table
     for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     }
  
     return subset[n][sum];
}
//cutting rod
int maxProfit(int arr[],int n)
{
	int val[n+1][n+1];
	for(int i=0;i<=n;i++)
	{
		val[i][0]=0;
		val[1][i]=i*arr[0];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i>j)
			val[i][j]=val[i-1][j];
			else
			val[i][j]=max(val[i-1][j],arr[i-1]+val[i][j-i]);
		}
	}
	return val[n][n];
}
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<maxProfit(arr,size);
    return 0;
}


