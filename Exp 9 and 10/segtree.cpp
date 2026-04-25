#include <bits/stdc++.h>
using namespace std;

// Simple templated segment tree for range-sum and point-update.
// 0-indexed. Query is inclusive [l, r].
template <typename T>
struct SegTree
{
  int n;
  vector<T> st;

  SegTree() : n(0) {}
  explicit SegTree(int _n) { init(_n); }
  explicit SegTree(const vector<T> &a)
  {
    init((int)a.size());
    build(1, 0, n - 1, a);
  }

  void init(int _n)
  {
    n = _n;
    st.assign(4 * max(1, n), T());
  }

  void build(int p, int l, int r, const vector<T> &a)
  {
    if (l == r)
    {
      st[p] = a[l];
      return;
    }
    int m = (l + r) >> 1;
    build(p << 1, l, m, a);
    build(p << 1 | 1, m + 1, r, a);
    st[p] = st[p << 1] + st[p << 1 | 1];
  }

  void build(const vector<T> &a)
  {
    init((int)a.size());
    build(1, 0, n - 1, a);
  }

  void point_update(int idx, T val) { point_update(1, 0, n - 1, idx, val); }
  void point_update(int p, int l, int r, int idx, T val)
  {
    if (l == r)
    {
      st[p] = val;
      return;
    }
    int m = (l + r) >> 1;
    if (idx <= m)
      point_update(p << 1, l, m, idx, val);
    else
      point_update(p << 1 | 1, m + 1, r, idx, val);
    st[p] = st[p << 1] + st[p << 1 | 1];
  }

  // query sum on [L, R]
  T range_query(int L, int R) { return range_query(1, 0, n - 1, L, R); }
  T range_query(int p, int l, int r, int L, int R)
  {
    if (R < l || r < L)
      return T();
    if (L <= l && r <= R)
      return st[p];
    int m = (l + r) >> 1;
    return range_query(p << 1, l, m, L, R) + range_query(p << 1 | 1, m + 1, r, L, R);
  }
};

// Usage example
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // example: build from vector, query and update
  vector<long long> a = {1, 3, 5, 7, 9, 11};
  SegTree<long long> st(a);

  // query sum on [1, 4] -> 3+5+7+9 = 24
  cout << "sum[1,4] = " << st.range_query(1, 4) << '\n';

  // point update: a[2] = 10
  st.point_update(2, 10);
  // now sum[1,4] -> 3+10+7+9 = 29
  cout << "after update sum[1,4] = " << st.range_query(1, 4) << '\n';

  return 0;
}
