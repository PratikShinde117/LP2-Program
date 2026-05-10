import java.util.*;

public class BFSIterative {

    static void BFS(int start,
                    ArrayList<Integer>[] adj,
                    boolean[] visited) {

        Queue<Integer> q = new LinkedList<>();

        visited[start] = true;

        q.add(start);

        while(!q.isEmpty()) {

            int node = q.poll();

            System.out.print(node + " ");

            for(int neighbor : adj[node]) {

                if(!visited[neighbor]) {

                    visited[neighbor] = true;

                    q.add(neighbor);
                }
            }
        }
    }

    public static void main(String[] args) {

        int V = 5;

        ArrayList<Integer>[] adj = new ArrayList[V];

        for(int i=0; i<V; i++) {
            adj[i] = new ArrayList<>();
        }

        // Undirected Graph
        adj[0].add(1);
        adj[1].add(0);

        adj[0].add(2);
        adj[2].add(0);

        adj[1].add(3);
        adj[3].add(1);

        adj[1].add(4);
        adj[4].add(1);

        boolean[] visited = new boolean[V];

        System.out.println("BFS Traversal:");

        BFS(0, adj, visited);
    }
}
