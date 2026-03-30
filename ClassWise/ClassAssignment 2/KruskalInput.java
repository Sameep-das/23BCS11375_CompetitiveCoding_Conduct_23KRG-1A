import java.util.*;

class Edge {
    int u, v, weight;

    public Edge(int u, int v, int weight) {
        this.u = u;
        this.v = v;
        this.weight = weight;
    }
}

class DSU {
    int[] parent, size;

    public DSU(int n) {
        parent = new int[n];
        size = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    public boolean union(int u, int v) {
        int ru = find(u);
        int rv = find(v);

        if (ru == rv) return false;

        if (size[ru] < size[rv]) {
            parent[ru] = rv;
            size[rv] += size[ru];
        } else {
            parent[rv] = ru;
            size[ru] += size[rv];
        }
        return true;
    }
}

public class KruskalInput {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        List<Edge> edges = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            edges.add(new Edge(u, v, w));
        }
        Collections.sort(edges, (a, b) -> a.weight - b.weight);
        DSU dsu = new DSU(n);
        int mstWeight = 0;
        System.out.println("Edges in MST:");
        for (Edge e : edges) {
            if (dsu.union(e.u, e.v)) {
                System.out.println(e.u + " - " + e.v + " : " + e.weight);
                mstWeight += e.weight;
            }
        }
        System.out.println("Total MST weight: " + mstWeight);
        sc.close();
    }
}