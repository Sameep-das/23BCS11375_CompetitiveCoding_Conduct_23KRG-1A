#include <vector>
using namespace std;

class DSU
{
private:
  vector<int> parent;
  vector<int> rank;

public:
  DSU(int n)
  {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++)
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

    int px = find(x);
    int py = find(y);

    if (px == py)
      return;

    if (rank[px] < rank[py])
    {
      parent[px] = py;
    }
    else if (rank[px] > rank[py])
    {
      parent[py] = px;
    }
    else
    {
      parent[py] = px;
      rank[px]++;
    }
  }

  bool connected(int x, int y)
  {
    return find(x) == find(y);
  }
};
