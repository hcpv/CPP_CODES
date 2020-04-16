#include<bits/stdc++.h>
using namespace std;
#define Trie struct TrieNode*
struct TrieNode
{
  TrieNode *child[26];
  int freq;
  int end;
  TrieNode()
  {
    for(int i=0;i<26;i++)
    {
      child[i]=NULL;
    }
    freq=0;
    end=0;
  }
};
void insert(Trie root,string s)
{
  int n=s.length();
  for(int i=0;i<n;i++)
  {
    int t=s[i]-'a';
    if(root->child[t]==NULL)
    root->child[t]=new TrieNode;
    root->child[t]->freq++;
    root=root->child[t];
  }
  root->end++;
}
int find(Trie root,string s)
{
  int sol=0;
  int n=s.length();
  for(int i=0;i<n;i++)
  {
    int t=s[i]-'a';
    if(root->child[t]==NULL)
    return 0;
    root=root->child[t];
  }
  return root->freq-root->end;
}
int main()
{
  string arr[] = { "abba", "abba", "abbc", "abbd", "abaa", "abca" };
  int n=6;
  Trie root=new TrieNode;
  for(int i=0;i<n;i++)
  insert(root,arr[i]);
  string k="abb";
  cout<<root->freq<<endl;
  cout<<find(root,k);
}
