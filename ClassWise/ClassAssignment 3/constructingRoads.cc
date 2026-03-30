#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
  vector<int> parent, size;
  int components;

  DSU(int n)
  {
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    components = n;
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  int find(int x)
  {
    if (parent[x] != x)
    {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unite(int x, int y)
  {
    x = find(x);
    y = find(y);

    if (x == y)
      return;

    if (size[x] < size[y])
      swap(x, y);

    parent[y] = x;
    size[x] += size[y];
    components--;
  }

  int getMaxSize()
  {
    int maxSize = 0;
    for (int i = 1; i < size.size(); i++)
    {
      if (find(i) == i)
      {
        maxSize = max(maxSize, size[i]);
      }
    }
    return maxSize;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;

  DSU dsu(n);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    dsu.unite(a, b);
    cout << dsu.components << " " << dsu.getMaxSize() << "\n";
  }

  return 0;
}