#include<bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000000007
#define pace ios::sync_with_stdio(false);cin.tie(0)
typedef struct tree *node;
struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};
node newNode(int value)
{
    node n=(node)malloc(sizeof(node));
    n->data=value;
    n->right=n->left= nullptr;

    return n;
}
node findNode(node n,int k)
{
    if(n== nullptr)
        return nullptr;
    if(n->data==k)
        return n;
    node l=findNode(n->left,k);
    node r=findNode(n->right,k);
    return l!= nullptr?l:r;
}
bool findPath(node n,vector<int>*path,int k)
{
    if (n== nullptr)
        return false;
    (*path).push_back(n->data);
    if(n->data==k)
        return true;
    if(n->left&&findPath(n->left,path,k)||n->right&&findPath(n->right,path,k))
        return true;
    (*path).pop_back();
    return false;
}
int findSum(node A,int &sum)
{
	//cout<<s
    if(A==nullptr)
        return 0;
    sum=sum+A->data;
    if(A->left==nullptr&&A->right==nullptr)
        return sum;
    if(A->left||A->right)
        return findSum(A->left,sum)+findSum(A->right,sum);
}

int sumNumbers(node A) {
    if(A==nullptr)
        return 0;
    int sum1=0,sum2=0;
    int sum=findSum(A->left,sum1)+findSum(A->right,sum2);
    
    return sum%1003;
}
int main()
{
	node root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(4);
    root->left->right = newNode(3);
    root->right->right = newNode(5);
    root->right->right->left = newNode(6);
    vector<int>a;
    if(findPath(root,&a,5))
    {
    	for(auto x:a)
    	{
    		if(x!=5)
    		cout<<x<<endl;
		}
    	
	}
	
}
