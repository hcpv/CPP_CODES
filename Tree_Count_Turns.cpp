
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
void countUtil(node n,vector<pair<int,int>>&v,int c,bool turn)
{

	if(n->left==nullptr&&n->right==nullptr)
	{
	    if(v.empty())
		{
		    v.push_back(make_pair(n->data,c));
		}
		else
		{
		if(c>v.begin()->second)
		{
		    v.clear();
		    v.push_back(make_pair(n->data,c));
		}
		else if(c==v.begin()->second)
		{
		    v.push_back(make_pair(n->data,c));
		}
		}
		return;
	}
	
	if(turn)
		{
			if(n->left!=nullptr)
			countUtil(n->left,v,c,turn);
			if(n->right!=nullptr)
			{
			countUtil(n->right,v,c+1,!turn);
		}
		return;
		}
	if(!turn)
		{
			if(n->right)
			countUtil(n->right,v,c,turn);
			if(n->left)
			{
		    countUtil(n->left,v,c+1,!turn);
        }
        return;
	}
	
	return ;
}
void count(node n)
{
	if(n==nullptr)
	return;
	vector<pair<int,int>>v;
	int count=0;
	if(n->left)
	{
		countUtil(n->left,v,0,true);
	}
	if(n->right)
	{
		countUtil(n->right,v,0,false);
	}
	
	for(int i=0;i<v.size();i++)
	cout<<v[i].first<<" "<<v[i].second<<endl;
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
    root->right->left->right = newNode(11);
    root->right->right->right=newNode(10);
    count(root);
}
