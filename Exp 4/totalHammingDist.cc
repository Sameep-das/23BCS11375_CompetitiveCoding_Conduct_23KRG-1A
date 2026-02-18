#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int totalHammingDistance(vector<int> &nums)
  {
    int sum = 0;
    for (int i = 0; i < 32; ++i)
    {
      int ones = 0;
      int zeroes = 0;
      for (int j = 0; j < nums.size(); ++j)
      {
        if ((nums[j] >> i) & 1)
          ones++;
        else
          zeroes++;
      }
      sum += ones * zeroes;
    }
    return sum;
  }
};