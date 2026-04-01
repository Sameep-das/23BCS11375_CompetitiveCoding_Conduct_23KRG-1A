int triangularSum(vector<int> &nums)
{
  int n = nums.size();
  vector<int> row(n, 1);

  for (int i = 1; i < n; i++)
  {
    row[i] = (row[i - 1] * (n - i)) / i;
  }

  int res = 0;
  for (int i = 0; i < n; i++)
  {
    res = (res + nums[i] * row[i]) % 10;
  }

  return res;
}