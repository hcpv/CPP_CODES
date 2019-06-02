#include <bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n,char from,char to,char aux)
{
	if(n>0)
	{
		towerOfHanoi(n-1,from,aux,to);
		cout<<"Move disk "<<n<<" "<<from<<" to "<<to<<endl;
		towerOfHanoi(n-1,aux,to,from);
	}
}
int main() {
	int n;
	cin>>n;
	towerOfHanoi(n,'A','C','B');
	return 0;
}
