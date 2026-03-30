import java.util.*;
class FordFulkerson{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int v = sc.nextInt();
        int e = sc.nextInt();
        int graph[][] = new int[v][v];
        for(int i=0;i<e;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int w = sc.nextInt();
            graph[a][b] = w;
        }
        int source = sc.nextInt();
        int sink = sc.nextInt();
        System.out.println(maxFlow(graph,source,sink));
    }
    public static boolean bfs(int graph[][],int source,int sink,int parent[]){
        boolean visited[] = new boolean[graph.length];
        Queue<Integer> q = new LinkedList<>();
        q.add(source);
        visited[source] = true;
        while(!q.isEmpty()){
            int u = q.poll();
            for(int v=0;v<graph.length;v++){
                if(!visited[v] && graph[u][v]>0){
                    q.add(v);
                    visited[v] = true;
                    parent[v] = u;
                }
            }
        }
        return visited[sink];
    }
    public static int maxFlow(int graph[][],int source,int sink){
        int parent[] = new int[graph.length];
        int maxFlow = 0;
        while(bfs(graph,source,sink,parent)){
            int pathFlow = Integer.MAX_VALUE;
            for(int v=sink;v!=source;v=parent[v]){
                int u = parent[v];
                pathFlow = Math.min(pathFlow,graph[u][v]);
            }
            for(int v=sink;v!=source;v=parent[v]){
                int u = parent[v];
                graph[u][v] -= pathFlow;
                graph[v][u] += pathFlow;
            }
            maxFlow += pathFlow;
        }
        return maxFlow;
    }
}