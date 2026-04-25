#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  if (!(cin >> n))
    return 0;
  vector<int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
    sum += a[i];
  }
  int target;
  cin >> target;

  if (abs(target) > sum)
  {
    cout << 0 << '\n';
    return 0;
  }
  long long t = sum + target;
  if (t % 2 != 0)
  {
    cout << 0 << '\n';
    return 0;
  }
  int P = (int)(t / 2);

  int zeros = 0;
  for (int x : a)
    if (x == 0)
      ++zeros;

  vector<long long> dp(P + 1, 0);
  dp[0] = 1;
  for (int x : a)
  {
    if (x == 0)
      continue;
    for (int j = P; j >= x; --j)
      dp[j] += dp[j - x];
  }

  long long ways = dp[P];
  for (int i = 0; i < zeros; ++i)
    ways *= 2;

  cout << ways << '\n';
  return 0;
}