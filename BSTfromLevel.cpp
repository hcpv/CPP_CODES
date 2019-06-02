#include <bits/stdc++.h>
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
struct NodeDetails{
    node ptr;
    int min,max;
};
node construct(int arr[],int n)
{
    if(n==0)
        return nullptr;
    queue<NodeDetails>q;
    NodeDetails ne;
    int i=0;
    ne.ptr=newNode(arr[i++]);
    ne.max=INT_MAX;
    ne.min=INT_MIN;
    q.push(ne);
    node root=ne.ptr;
    while(i!=n)
    {
        NodeDetails temp=q.front();
        q.pop();
        if(i<n&&(arr[i]<temp.ptr->data&&arr[i]>temp.min))
        {
            ne.ptr=newNode(arr[i++]);
            ne.min=temp.min;
            ne.max=temp.ptr->data;
            q.push(ne);
            temp.ptr->left=ne.ptr;
        }
        if(i<n&&(arr[i]>temp.ptr->data&&arr[i]<temp.max))
        {
            ne.ptr=newNode(arr[i++]);
            ne.max=temp.max;
            ne.min=temp.ptr->data;
            q.push(ne);
            temp.ptr->right=ne.ptr;
        }

    }
    return root;
}
void inorderTraversal(node root)
{
    if (!root)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Driver program to test above
int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    node root = construct(arr, n);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    return 0;
}