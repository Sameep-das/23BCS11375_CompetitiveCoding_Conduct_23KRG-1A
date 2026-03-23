#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<string> names(n);

  for (int i = 0; i < n; i++)
  {
    cin >> names[i];
  }

  // Build constraint graph
  vector<set<int>> adj(26);
  vector<int> indegree(26, 0);
  set<int> used;

  // Extract constraints from consecutive names
  for (int i = 0; i < n - 1; i++)
  {
    string &s = names[i];
    string &t = names[i + 1];
    int len = min(s.length(), t.length());

    int j = 0;
    while (j < len && s[j] == t[j])
    {
      j++;
    }

    // If s is longer than t and they match up to len, impossible
    if (j == len && s.length() > t.length())
    {
      cout << "Impossible\n";
      return 0;
    }

    // Add constraint: s[j] comes before t[j]
    if (j < len)
    {
      int u = s[j] - 'a';
      int v = t[j] - 'a';
      if (adj[u].find(v) == adj[u].end())
      {
        adj[u].insert(v);
        indegree[v]++;
      }
    }
  }

  // Collect all characters that appear
  for (const auto &name : names)
  {
    for (char c : name)
    {
      used.insert(c - 'a');
    }
  }

  // Topological sort using Kahn's algorithm
  queue<int> q;
  for (int i = 0; i < 26; i++)
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
  }

  string result = "";
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    result += (char)('a' + u);

    for (int v : adj[u])
    {
      indegree[v]--;
      if (indegree[v] == 0)
      {
        q.push(v);
      }
    }
  }

  // Check if all characters with constraints are processed (no cycle)
  int count = 0;
  for (int i = 0; i < 26; i++)
  {
    if (indegree[i] == 0)
      count++;
  }

  if (count != 26)
  {
    cout << "Impossible\n";
    return 0;
  }

  cout << result << "\n";
  return 0;
}