#include "bits/stdc++.h"
using namespace std;
#define Trie struct TrieNode*
struct TrieNode {
  TrieNode* children[26];
  int weight;
};
Trie newNode()
{
  Trie temp=new TrieNode;
  temp->weight=0;
  for(int i=0;i<26;i++)
  {
    temp->children[i]=NULL;
  }
  return temp;
}
int insert(Trie* root,string k,int i,int w)
{
  if(i==k.length())
	{
		(*root)->weight=w;
		return w;
	}
	int temp=(*root)->weight;
	int p=k[i]-'a';
	if(!(*root)->children[p])
	(*root)->children[p]=newNode();
	int m=insert(&(*root)->children[p],k,i+1,w);
	if(m>temp)
	{
		(*root)->weight=m;
	}
	return (*root)->weight;
}
int search(Trie root,string k)
{
  Trie temp=root;
  int p;
  for(int i=0;i<k.length();i++)
  {
    p=k[i]-'a';
    if(!temp->children[p])
    {
      return -1;
    }
    temp=temp->children[p];
  }
  if(temp==NULL)
  return -1;
  int max=temp->weight;
  return max;
}

int main()
{
  cout<<sizeof(struct TrieNode)<<endl;
  int n,q,w;
  cin>>n>>q;
  Trie root=newNode();
  string k;
  for(int i=0;i<n;i++)
  {
      cin>>k>>w;
      max(insert(&root,k,0,w),root->weight);
  }
  for(int i=0;i<q;i++)
  {
      cin>>k;
      cout<<search(root,k)<<endl;
  }
}
