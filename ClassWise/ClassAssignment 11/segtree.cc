#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class SegmentTree
{
  int n;
  vector<long long> tree;

  void build(int node, int l, int r, const vector<long long> &a)
  {
    if (l == r)
    {
      tree[node] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(node << 1, l, mid, a);
    build(node << 1 | 1, mid + 1, r, a);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
  }

  long long queryRec(int node, int l, int r, int ql, int qr)
  {
    if (qr < l || r < ql)
      return 0;
    if (ql <= l && r <= qr)
      return tree[node];
    int mid = (l + r) >> 1;
    return queryRec(node << 1, l, mid, ql, qr) + queryRec(node << 1 | 1, mid + 1, r, ql, qr);
  }

  void updateRec(int node, int l, int r, int idx, long long val)
  {
    if (l == r)
    {
      tree[node] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if (idx <= mid)
      updateRec(node << 1, l, mid, idx, val);
    else
      updateRec(node << 1 | 1, mid + 1, r, idx, val);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
  }

public:
  SegmentTree() : n(0) {}
  SegmentTree(const vector<long long> &a) { init(a); }

  void init(const vector<long long> &a)
  {
    n = (int)a.size();
    tree.assign(4 * max(1, n), 0);
    if (n)
      build(1, 0, n - 1, a);
  }

  // range sum query on [l, r] (0-indexed)
  long long query(int l, int r)
  {
    if (n == 0)
      return 0;
    l = max(l, 0);
    r = min(r, n - 1);
    if (l > r)
      return 0;
    return queryRec(1, 0, n - 1, l, r);
  }

  // point update: set index idx to val (0-indexed)
  void update(int idx, long long val)
  {
    if (n == 0)
      return;
    if (idx < 0 || idx >= n)
      return;
    updateRec(1, 0, n - 1, idx, val);
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  if (!(cin >> N))
    return 0;
  vector<long long> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  SegmentTree st(a);
  int Q;
  if (!(cin >> Q))
    return 0;
  for (int i = 0; i < Q; ++i)
  {
    char type;
    cin >> type;
    if (type == 'q' || type == 'Q')
    {
      int l, r;
      cin >> l >> r;
      --l;
      --r;
      cout << st.query(l, r) << '\n';
    }
    else if (type == 'u' || type == 'U')
    {
      int idx;
      long long val;
      cin >> idx >> val;
      --idx;
      st.update(idx, val);
    }
    else
    {
      string rest;
      getline(cin, rest);
    }
  }

  return 0;
}