#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
  int minimumEffort(vector<pair<int, int>> &tasks)
  {
    sort(tasks.begin(), tasks.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return (a.second - a.first) > (b.second - b.first); });
    int energy = 0;
    int current = 0;
    for (auto &task : tasks)
    {
      int actual = task.first;
      int minimum = task.second;
      if (current < minimum)
      {
        energy += (minimum - current);
        current = minimum;
      }
      current -= actual;
    }
    return energy;
  }
};

int main()
{
  int N;
  cin >> N;
  vector<pair<int, int>> tasks(N);
  while (N--)
  {
    int u, v;
    cin >> u >> v;
    tasks.push_back({u, v});
  }
  Solution s;
  cout << s.minimumEffort(tasks);
  return 0;
}