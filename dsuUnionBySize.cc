#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
  vector<int> parent;
  vector<int> size;

public:
  DSU(int n)
  {
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }

  int find(int x)
  {
    if (parent[x] != x)
    {
      parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
  }

  void unionBySize(int x, int y)
  {
    x = find(x);
    y = find(y);

    if (x == y)
      return;
    if (size[x] < size[y])
    {
      parent[x] = y;
      size[y] += size[x];
    }
    else
    {
      parent[y] = x;
      size[x] += size[y];
    }
  }

  int getSize(int x)
  {
    return size[find(x)];
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;

  DSU dsu(n);

  for (int i = 0; i < q; i++)
  {
    int type, x, y;
    cin >> type >> x >> y;

    if (type == 1)
    {
      dsu.unionBySize(x, y);
    }
    else
    {
      if (dsu.find(x) == dsu.find(y))
      {
        cout << "Yes\n";
      }
      else
      {
        cout << "No\n";
      }
    }
  }

  return 0;
}