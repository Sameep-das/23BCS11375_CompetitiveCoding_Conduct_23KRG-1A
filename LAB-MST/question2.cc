#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maxProduct(vector<string> &words)
  {
    int n = words.size();
    vector<int> mask(n);
    for (int i = 0; i < n; i++)
    {
      int bitmask = 0;
      for (char c : words[i])
      {
        bitmask |= 1 << (c - 'a');
      }
      mask[i] = bitmask;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if ((mask[i] & mask[j]) == 0)
        {
          int product = words[i].size() * words[j].size();
          res = max(res, product);
        }
      }
    }
    return res;
  }
};

int main()
{
  Solution obj;
  vector<string> words = {"abs", "abs"};
  cout << obj.maxProduct(words);
  return 0;
}