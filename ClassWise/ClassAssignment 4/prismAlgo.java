import java.util.*;
class prismAlgo{
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
            graph[b][a] = w;
        }
        boolean visited[] = new boolean[v];
        int parent[] = new int[v];
        parent[0] = -1;
        visited[0] = true;
        for(int i=0;i<v-1;i++){
            int minEdge = Integer.MAX_VALUE;
            int minVertex = -1;
            for(int j=0;j<v;j++){
                if(visited[j]){
                    for(int k=0;k<v;k++){
                        if(!visited[k] && graph[j][k]!=0){
                            if(graph[j][k]<minEdge){
                                minEdge = graph[j][k];
                                minVertex = k;
                                parent[minVertex] = j;
                            }
                        }
                    }
                }
            }
            visited[minVertex] = true;
        }
        for(int i=1;i<v;i++){
            System.out.println(parent[i]+"-"+i);
        }
    }
}