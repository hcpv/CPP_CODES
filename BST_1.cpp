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
void printInOrder(node n)
{
    if(n==nullptr)
        return;
    printInOrder(n->left);
    cout<<n->data<<" ";
    printInOrder(n->right);
}
node inorderPredecessor(node n,node s)
{
    if(s->left)
    {
        node temp=s->left;
        while(temp->right!= nullptr)
            temp=temp->right;
        return temp;
    }
    else if(s->right)
    {
        node store= nullptr;
        while(n->data!=s->data)
        {
            if(n->data>s->data)
                n=n->left;
            if(n->data<s->data)
            {
                store=n;
                n=n->right;
            }
        }
        return store;
    }
}
node inorderSuccessor(node n,node s)
{
    if(s->right)
    {
        node temp=s->right;
        while(temp->left!=nullptr)
            temp=temp->left;
        return temp;
    }
    else if(s->left)
    {
        node store= nullptr;
        while(n->data!=s->data)
        {
            if(n->data>s->data)
            {
                store=n;
                n=n->left;
            }
            else
                n=n->right;
        }
        return store;
    }
}
int numberOfBST(int n)
{
    vector<int>a;
    a.push_back(1);
    a.push_back(1);
    for(int i=2;i<=n;i++)
    {
        a.push_back(0);
        for(int j=0;j<i;j++)
            a[i]+=a[j]*a[i-j-1];
    }
    return a[n];
}
/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
node minValueNode(node n)
{
    node current = n;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
node deleteNode(node root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

        // if key is same as root's key, then This is the node
        // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            node temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        node temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
bool isBST(node n,int min,int max)
{
    if(n== nullptr)
        return true;
    if(n->data<min||n->data>max)
        return false;
    return (isBST(n->left,min,n->data-1)&&isBST(n->right,n->data+1,max));
}
int main() {

   // node root = constructTree2(pre,&i,INT_MIN,INT_MAX, size);
    //printInOrder(root);

    return 0;
}
