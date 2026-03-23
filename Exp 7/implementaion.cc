#include <iostream>
#include <vector>
#include <algorithm>

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

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

vector<Edge> kruskalMST(int V, vector<Edge>& edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end());
    
    // Initialize DSU
    DSU dsu(V);
    
    vector<Edge> mst;
    int mstWeight = 0;
    
    for (auto& edge : edges) {
        if (!dsu.connected(edge.u, edge.v)) {
            dsu.unite(edge.u, edge.v);
            mst.push_back(edge);
            mstWeight += edge.weight;
            
            // If we have V-1 edges, we can stop
            if (mst.size() == V - 1) break;
        }
    }
    
    cout << "Total weight of MST: " << mstWeight << endl;
    return mst;
}

int main() {
    // Example usage
    int V = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    
    vector<Edge> mst = kruskalMST(V, edges);
    
    cout << "Edges in MST:" << endl;
    for (auto& edge : mst) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }
    
    return 0;
}
