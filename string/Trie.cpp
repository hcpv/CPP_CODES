#include "bits/stdc++.h"
using namespace std;
#define Trie struct TrieNode*
struct TrieNode {
  TrieNode* children[26];
  bool isEndOfWord;
};
Trie newNode()
{
  Trie temp=new TrieNode;
  temp->isEndOfWord=false;
  for(int i=0;i<26;i++)
  {
    temp->children[i]=NULL;
  }
  return temp;
}
void insert(Trie* root,string k)
{
  Trie temp=*root;
  int p;
  for(int i=0;i<k.length();i++)
  {
    p=(int)k[i]-(int)'a';
    if(!temp->children[p])
    {
      temp->children[p]=newNode();
    }
    temp=temp->children[p];
  }
  temp->isEndOfWord=true;
}
bool search(Trie root,string k)
{
  Trie temp=root;
  int p;
  for(int i=0;i<k.length();i++)
  {
    p=k[i]-'a';
    if(!temp->children[p])
    {
      return false;
    }
    temp=temp->children[p];
  }
  return temp!=NULL&temp->isEndOfWord;
}
bool isEmpty(Trie root)
{
  for(int i=0;i<26;i++)
  {
    if(root->children[i])
    return false;
  }
  return true;
}
Trie del(Trie root,string k,int i)
{
  if(!root)
  return NULL;
  if(i==k.size())
  {
    if(root->isEndOfWord)
    root->isEndOfWord=false;
    if(isEmpty(root))
    {
      free(root);
      return NULL;
    }
    return root;
  }
  int p=k[i]-'a';
  root->children[p]=del(root->children[p],k,i+1);
  if (isEmpty(root)&&root->isEndOfWord==false) {
    free(root);
    return NULL;
  }
  return root;
}
int main()
{
  string A[]={"abcd","abc","efg","fgh","the","there"};
  Trie root=newNode();
  int n=sizeof(A)/sizeof(A[0]);
  for(int i=0;i<n;i++)
  {
    insert(&root,A[i]);
  }
  root=del(root,"abc",0);
  cout<<search(root,"abcd")<<endl;
}
