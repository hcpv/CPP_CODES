#include <bits/stdc++.h>
#include <cmath>
#define ull long long int
#define mod 1000000007
#define pace ios::sync_with_stdio(false);cin.tie(0)
using namespace std;
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
void deleteTree(node n)
{
    if(n== nullptr)
        return;
    deleteTree(n->left);
    deleteTree(n->right);
    cout<<"Deleting Node: "<<n->data<<endl;
    free(n);
}
bool identicalTrees(node n1,node n2)
{
    if(n1== nullptr&&n2== nullptr)
        return true;
    if(!(n1== nullptr)&&!(n2== nullptr))
    {
        return (n1->data==n2->data)&&identicalTrees(n1->left,n2->left)&&identicalTrees(n1->right,n2->right);
    }
    return false;
}
//symmetric about root
int symmetric(node l,node r)
{
    if(l==nullptr&&r==nullptr)
        return 1;
    if(l!=nullptr&&r!=nullptr)
        return (l->data==r->data)&&symmetric(l->left,r->right)&&symmetric(l->right,r->left);
    return 0;
}
int isSymmetric(node A) {
    return symmetric(A->left,A->right);
}

int height(node n)
{
    if(n== nullptr)
        return 0;
    int l=height(n->left);
    int r=height(n->right);
    return 1+max(l,r);
}
int minDepth(node A) {
    if(A==nullptr)
        return 0;
    int l=minDepth(A->left);
    int r=minDepth(A->right);
    return 1+min(l,r);
}
//different from last one as we have to check if right or left node is null
int minDepth2(node root) {
    // Corner case. Should never be hit unless the code is called on root = NULL
    if (root == NULL) return 0;
    // Base case : Leaf node. This accounts for height = 1.
    if (root->left == NULL && root->right == NULL) return 1;

    if (!root->left) return minDepth(root->right) + 1;//when left node is null
    if (!root->right) return minDepth(root->left) + 1;//when right node is null

    return min(minDepth(root->left), minDepth(root->right)) + 1;//when both left and right node is not null
}
bool isBalanced(node n)
{
    if(n== nullptr)
        return true;
    if(height(n->left)-height(n->right)<=1&&(isBalanced(n->left)&&isBalanced(n->right)))
        return true;
    else
        return false;
}
int diameterOfTree(node n)
{
    if(n== nullptr)
        return 0;
    int lh=height(n->left);
    int rh=height(n->right);
    int ld=diameterOfTree(n->left);
    int rd=diameterOfTree(n->right);
    return max((lh+rh+1),max(ld,rd));
}
int numberLeaf(node n)
{
    if(n== nullptr)
        return 0;
    if(n->right== nullptr&&n->left== nullptr)
        return 1;
    return (numberLeaf(n->left)+numberLeaf(n->right));
}
bool findPath(node n,vector<char> *a,int k)
{
    if(n== nullptr)
        return false;
    if(n->data==k)
        return true;
    if(n->left&&findPath(n->left,a,k))
    {
        a->push_back('L');
        return true;
    }
    if(n->right&&findPath(n->right,a,k))
    {
        a->push_back('R');
        return true;
    }
    return false;

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
void mirror(node n)
{
    if(n)
    {
        //subtrees
        mirror(n->left);
        mirror(n->right);
        //swap
        node temp=n->right;
        n->right=n->left;
        n->left=temp;
    }
    return;
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
    //root->right = newNode();
    root->left->right = newNode(3);
   // root->right->right = newNode(5);
    //root->right->left->left = newNode(6);
    cout<<minDepth(root)<<endl;
    cout<<minDepth2(root);

}
