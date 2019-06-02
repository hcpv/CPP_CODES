
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
int findlevel(node root,int k,int level)
{
	if(root==nullptr)
	return 0;
	if(root->data==k)
	return level;
	int l=findlevel(root->left,k,level+1);
	if(!l)
	return findlevel(root->right,k,level+1);
	return l;
}
void printCousinsUtil(node n,int k,int level)
{
	if(n==nullptr||level<2)
	return;
	if(level==2)
	{
	    //cout<<n->left->data<<endl;
	    if((n->left)&&n->right)
	   {
	       if(n->left->data==k||n->right->data==k)
	       return;
	       
	   }
	   //cout<<20<<endl;
	    if(n->left&&n->left->data!=k)
	    cout<<n->left->data<<" ";
	    if(n->right&&n->right->data!=k)
	    cout<<n->right->data<<" ";
	}
	else if(level>2)
	{
	  
	printCousinsUtil(n->left,k,level-1);
	printCousinsUtil(n->right,k,level-1);
	}
}
void printCousin(node root,int k)
{
	int l=findlevel(root,k,1);
	//cout<<l;
	printCousinsUtil(root,k,l);
}
int countNodes(node root)
{
    if(root==nullptr)
	{
		return 0;
		}	
		int l=countNodes(root->left);
		int r=countNodes(root->right);
		if(!l&&!r)
		return (1);
		return l+r+1;
		
}
int main()
{
    pace;
    node root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left=newNode(8);
    root->left->right->left=newNode(9);
    root->right->right->right=newNode(10);
    //cout<<findlevel(root,10,1);
    printCousin(root,8);
}
