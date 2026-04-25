#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode
{
public:
  TrieNode *children[26];
  bool isEndOfWord;
  TrieNode()
  {
    for (int i = 0; i < 26; i++)
      children[i] = nullptr;
    isEndOfWord = false;
  }
};

class Trie
{
private:
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }
  void insert(string word)
  {
    TrieNode *curr = root;
    for (char c : word)
    {
      int i = c - 'a';
      if (!curr->children[i])
        curr->children[i] = new TrieNode();
      curr = curr->children[i];
    }
    curr->isEndOfWord = true;
  }
  bool search(string word)
  {
    TrieNode *curr = root;
    for (char c : word)
    {
      int i = c - 'a';
      if (!curr->children[i])
        return false;
      curr = curr->children[i];
    }
    return curr->isEndOfWord;
  }
  bool startsWith(string p)
  {
    TrieNode *curr = root;
    for (char c : p)
    {
      int i = c - 'a';
      if (!curr->children[i])
        return false;
      curr = curr->children[i];
    }
    return true;
  }
};
