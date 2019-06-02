w#include <bits/stdc++.h>
using namespace std;
//Arrange given numbers to form the biggest number 
// A comparison function which is used by sort() in printLargest()
int myCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);
 
    // then append X at the end of Y
    string YX = Y.append(X);
 
    // Now see which of the two formed numbers is greater
    return XY.compare(YX) > 0 ? 1: 0;
}
 
// The main function that prints the arrangement with the largest value.
// The function accepts a vector of strings
void printLargest(vector<string> arr)
{
    // Sort the numbers using library sort funtion. The function uses
    // our comparison function myCompare() to compare two strings.
    // See http://www.cplusplus.com/reference/algorithm/sort/ for details
    sort(arr.begin(), arr.end(), myCompare);
 
    for (int i=0; i < arr.size() ; i++ )
        cout << arr[i];
}


//Sort by frequenvy
// function to compare two pairs for inbuilt sort
bool compare(pair<int,int> &p1,
             pair<int, int> &p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;//ascending
    return p1.second > p2.second;//descendin
}
// function to print elements sorted by freq
void printSorted(int arr[], int n)
{
    map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
    int s = m.size();
 
    // an array of pairs,pair contain element and its frequencies
    pair<int, int> p[s];
 
    // Fill (val, freq) pairs in an array
    // of pairs.
    int i = 0;
    for (auto it = m.begin(); it != m.end(); ++it)
        p[i++] = make_pair(it->first, it->second);
 
    // sort the array of pairs using above
    // compare function.
    sort(p, p + s, compare);
 
    cout << "Elements sorted by frequency are: ";
    for (int i = 0; i < s; i++)
    {
        int freq = p[i].second;
        while (freq--)
            cout << p[i].first << " ";
    }
}
//print array in spiral
void spiralPrint(int m, int n, int a[R][C])
{
    int i, k = 0, l = 0;
 
    /*  k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
 
    while (k < m && l < n)
    {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i)
        {
            printf("%d ", a[k][i]);
        }
        k++;
 
        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i)
        {
            printf("%d ", a[i][n-1]);
        }
        n--;
 
        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                printf("%d ", a[m-1][i]);
            }
            m--;
        }
 
        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                printf("%d ", a[i][l]);
            }
            l++;    
        }        
    }
}
 
//Largest subarray of 0's and 1's 
int findSubArray(int arr[], int n)
{
    int sum = 0;
    int maxsize = -1, startindex;
 
    // Pick a starting point as i
 
    for (int i = 0; i < n-1; i++)
    {
        sum = (arr[i] == 0)? -1 : 1;
 
        // Consider all subarrays starting from i
 
        for (int j = i+1; j < n; j++)
        {
            (arr[j] == 0)? (sum += -1): (sum += 1);
 
            // If this is a 0 sum subarray, then 
            // compare it with maximum size subarray
            // calculated so far
 
            if (sum == 0 && maxsize < j-i+1)
            {
                maxsize = j - i + 1;
                startindex = i;
            }
        }
    }
    if (maxsize == -1)
        printf("No such subarray");
    else
        printf("%d to %d", startindex, startindex+maxsize-1);
 
    return maxsize;
}
//Relative Sorting
void relativeSort(vector<int>&a1,int n1,int a2[],int n2)
{
    map<int,int>b1;
    for(int i=0;i<n1;i++)
    b1[a1[i]]++;
    a1.clear();
    for(int i=0;i<n2;i++)
    {
        int x=a2[i];
        if(b1.find(x)!=b1.end())
        {
            while(--b1[x]>=0)
            a1.push_back(x);
            a2[i]=0;
        }
    }
    for(auto i:b1)
    {
        while(--b1[i.first]>=0)
        a1.push_back(i.first);
    }

}
//sort in zigzag
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void zigzag(int a[],int n)
{
    bool flag=true;
    for(int i=0;i<n-1;i++)
    {
        if(flag)
        {
            if(a[i]>a[i+1])
            swap(a[i],a[i+1]);
            flag=false;
        }
        else
        {
            if(a[i]<a[i+1])
            swap(a[i],a[i+1]);
            flag=true;
        }
    }
}
//Stock buy and sell
struct interval
{
    int start,end;
};
void stock(int a[],int n)
{
    interval b[n/2 + 1];
    int i=0,c=0;
    while(i<n-1)
    {
        while(i<n-1&&a[i+1]<=a[i])
        {
            i++;
        }
        if(i==n-1)
        break;
        b[c].start=i++;
        while(i<n&&a[i]>=a[i-1])
        i++;
        b[c].end=i-1;
        c++;
    }
    if(c==0)
    {
        cout<<"No Profit"<<endl;
        return;
    }
    for(int i=0;i<c;i++)
    {
        cout<<"("<<b[i].start<<" "<<b[i].end<<")"<<" ";
    }
    cout<<endl;
}
//a contains squares in sorted order
void pythagoreanTriplet(int a[],int n)
{
    for(int i=n-1;i>=0;i--)
	    {
	        int l=0,r=i-1;
	        while(l<r)
	        {
	            if(a[i]==a[l]+a[r])
	            {
	                cout<<"Yes"<<endl;
	                return;
	            }
	            else if(a[i]<a[l]+a[r])
	            {
	                r--;
	            }
	            else
	            l++;
	        }
	    }
    cout<<"No"<<endl;
}
//Segregate 0's, 1's and 2's together in an array[O(n)](Dutch National Flag Problem)
void sort(int arr[],int n)
{
    int low=0,high=n-1;
    int mid=0;
    int temp;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            arr[mid]=arr[low];
            arr[low]=0;
            mid++;
            low++;
        }
        else if(arr[mid]==1)
        mid++;
        else
        {
            arr[mid]=arr[high];
            arr[high]=2;
            high--;
        }
    }
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
int main() {
	int t;
	cin>>t;
	while(--t>=0)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    sort(a,n);
	}
	return 0;
}
/*Sliding Window Maximum (Maximum of all subarrays of size k)
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(--t>=0)
	{
	    int n,k,x;
	    cin>>n>>k;
	    map<int,int,greater<int>>q;
	    int a[n-k+1],b[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>b[i];
	        if(i<k-1)
	        {
	            q[b[i]]++;
	        }
	        else
	        {
	            q[b[i]]++;
	            a[i-k+1]=q.begin()->first;
	            
	            if(--q[b[i-k+1]]==0)
	            q.erase(b[i-k+1]);
	        }
	    }
	    for(int i=0;i<=n-k;i++)
	    cout<<a[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
//Trapping Rain Water
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(--t>=0)
	{
	    int n,k;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    int l=0,r=n-1;
	    int lmax=0,rmax=0,result=0;
	    while(l<r)
	    {
	        if(a[l]<a[r])
	        {
	            if(a[l]>lmax)
	            lmax=a[l];
	            else
	            result+=lmax-a[l];
	            l++;
	        }
	        else
	        {
	            if(a[r]>rmax)
	            rmax=a[r];
	            else
	            result+=rmax-a[r];
	            r--;
	        }
	    }
	    cout<<result<<endl;
	}
	return 0;
}
*/
