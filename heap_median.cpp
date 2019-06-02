#include <bits/stdc++.h>
using namespace std;
priority_queue<int>max_heap_left;//to store left half element of the sorted array
priority_queue<int,vector<int>,greater<int>>min_heap_right;//to store right half elements i.e. right of the median of the sorted array
void calculateMedian(double x,double &m)
{
    // case1(left side heap has more elements)
    if(max_heap_left.size()>min_heap_right.size())
    {
        if(x<m) {
            min_heap_right.push(max_heap_left.top());
            max_heap_left.pop();
            max_heap_left.push(x);
        }
        else
            min_heap_right.push(x);
        m=((double )max_heap_left.top()+(double )min_heap_right.top())/2.0;
        return;
    }
    //case2(both heaps are balanced
    else if(max_heap_left.size()==min_heap_right.size())
    {
        if(x<m)
        {
            max_heap_left.push(x);
            m=max_heap_left.top();
            return;
        }
        else
        {
            min_heap_right.push(x);
            m=min_heap_right.top();
            return;
        }
    }
    else if(max_heap_left.size()<min_heap_right.size())
    {
        if(x<=m)
            max_heap_left.push(x);
        else
        {
            max_heap_left.push(min_heap_right.top());
            min_heap_right.pop();
            min_heap_right.push(x);
        }
        m=((double)max_heap_left.top()+(double)min_heap_right.top())/2.0;
        return;
    }
}
int main()
{
    double arr[] = {5, 15, 10, 20, 3};
    double median = 0;//stores the median

    // size of stream
    int n = 5;

    // reading elements of stream one by one
    for (int i=0; i < n; i++)
    {
        // calculating new median for each
        // new element added to the stream
        calculateMedian(arr[i], median);
        cout << setprecision(1) << fixed << median << endl;
    }
    return 0;
}