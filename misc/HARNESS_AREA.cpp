#include <bits/stdc++.h>
using namespace std;
int fun(int A[], int n, int k)
{
	int count = 0;
	int i = 0;
	int j = n - 1;
	while (i < j)
	{
		if (A[i] * A[j] <= k) {
			count += 2*(j - i);
			i++;
		}
		else {
			j--;
		}
	}
  i=0;
  while(i<n&&A[i]*A[i]<=k)
  {
    count++;
    i++;
  }
	return count;
}
int main()
{

	int A[] = { 1, 2, 4 };
	int n = sizeof(A) / sizeof(int);
	int k = 4;
	cout << "Number of pairs with product less than equal to "
		<< k << " = " << fun(A, n, k) << endl;

	return 0;
}
