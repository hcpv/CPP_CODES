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
node search(node n,int k)
{
    if(n== nullptr||n->data==k)
        return n;
    if(n->data>k)
        return search(n->left,k);
    if(n->data<k)
        return search(n->right,k);
}
node insert(node n,int k)
{
    if(n== nullptr)
        return newNode(k);
    if(k>n->data)
        n->right=insert(n->right,k);
    else if(k<n->data)
        n->left=insert(n->left,k);
    return n;

}
//from preorder method 1
node constructTree(int pre[],int *preIndex,int low,int high,int size)
{
    // Base case
    if (*preIndex >= size || low > high)
        return NULL;

    // The first node in preorder traversal is root. So take the node at
    // preIndex from pre[] and make it root, and increment preIndex
    node root = newNode ( pre[*preIndex] );
    *preIndex = *preIndex + 1;

    // If the current subarry has only one element, no need to recur
    if (low == high)
        return root;

    // Search for the first element greater than root
    int i;
    for ( i = low; i <= high; ++i )
        if ( pre[ i ] > root->data )
            break;

    // Use the index of element found in preorder to divide preorder array in
    // two parts. Left subtree and right subtree
    root->left = constructTree( pre, preIndex, *preIndex, i - 1, size );
    root->right = constructTree ( pre, preIndex, i, high, size );

    return root;
}
//from preorder method 2
node constructTree2(int pre[],int *preIndex,int min,int max,int size)
{
    // Base case
    if (*preIndex >= size )
        return NULL;

    // The first node in preorder traversal is root. So take the node at
    // preIndex from pre[] and make it root, and increment preIndex
    node root = nullptr;
    if(pre[*preIndex]>min&&pre[*preIndex]<max)
    {
        root=newNode(pre[*preIndex]);
        *preIndex = *preIndex + 1;
        if(*preIndex<size)
        {
            root->left = constructTree2 ( pre, preIndex, min, root->data, size );
            root->right = constructTree2 ( pre, preIndex, root->data, max, size );

        }
    }


    return root;
}
//from binary tree to BST
void storeInOrder(node n,vector<int>*a)
{
    if(n==nullptr)
        return;
    storeInOrder(n->left,a);
    (*a).push_back(n->data);
    storeInOrder(n->right,a);
}
//binary tree to BST method 1-using vector
void vectorToBst(node n,vector<int>*a,int *i)
{
    if(n== nullptr)
        return;
    vectorToBst(n->left,a,i);
    n->data=(*a)[*i];
    (*i)++;
    vectorToBst(n->right,a,i);
    return;
}
void binaryTreeToBST1(node n)
{
    if(n== nullptr)
        return;
    vector<int>a;
    storeInOrder(n,&a);
    int l=0;
    sort(a.begin(),a.end());
    vectorToBst(n,&a,&l);
}
//binary to BST using set
void storeInOrderInSet(node n,set<int>&a)
{
    if(n==nullptr)
        return;
    storeInOrderInSet(n->left,a);
    a.insert(n->data);
    storeInOrderInSet(n->right,a);
}
void setToBST(node n,set<int>&s)
{
    if(n== nullptr)
        return;
    setToBST(n->left,s);
    set<int> :: iterator i;
    i=s.begin();
    n->data=*i;
    s.erase(i);
    setToBST(n->right,s);
    return;
}
void binaryTreeToBST2(node n)
{
    set<int>s;
    storeInOrderInSet(n,s);
    setToBST(n,s);
    return;
}
//sorted Array to BST
node sortedArrayToBST(int a[],int s,int e)
{
    if(s>e)
        return nullptr;
    int mid=(s+e)/2;
    node root=newNode(a[mid]);
    root->left=sortedArrayToBST(a,s,mid-1);
    root->right=sortedArrayToBST(a,mid+1,e);
    return root;
}
//transform a BST to greater sum Tree
void transformTree(node n,int *sum)
{
    if(n== nullptr)
        return;
    transformTree(n->right,sum);
    *sum=*sum+n->data;
    //store old sum in current node
    n->data=*sum-n->data;
    transformTree(n->left,sum);
    return;
}
void printInOrder(node n)
{
    if(n==nullptr)
        return;
    printInOrder(n->left);
    cout<<n->data<<" ";
    printInOrder(n->right);
}
void printPreOrder(node n)
{
    if(n==nullptr)
        return;
    cout<<n->data<<" ";
    printPreOrder(n->left);

    printPreOrder(n->right);
}
int main() {
    node root = newNode(5);
    root->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(11);
    binaryTreeToBST2(root);
    printInOrder(root);
    return 0;
}
