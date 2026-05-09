import java.util.*;

public class Main {

    public static void main(String[] args) {

        int V = 5;

        int[][] graph = {
                {0, 2, 0, 6, 0},
                {2, 0, 3, 8, 5},
                {0, 3, 0, 0, 7},
                {6, 8, 0, 0, 9},
                {0, 5, 7, 9, 0}
        };

        int[] key = new int[V];
        int[] parent = new int[V];
        boolean[] mst = new boolean[V];

        Arrays.fill(key, Integer.MAX_VALUE);
        Arrays.fill(parent, -1);

        key[0] = 0;

        for (int count = 0; count < V - 1; count++) {

            int u = -1;
            int mini = Integer.MAX_VALUE;

            // Find minimum key vertex not in MST
            for (int i = 0; i < V; i++) {

                if (!mst[i] && key[i] < mini) {

                    mini = key[i];
                    u = i;
                }
            }

            // Include vertex in MST
            mst[u] = true;

            // Update adjacent vertices
            for (int v = 0; v < V; v++) {

                if (!mst[v] &&
                        graph[u][v] != 0 &&
                        graph[u][v] < key[v]) {

                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }

        System.out.println("Edges in MST:");

        for (int i = 1; i < V; i++) {

            System.out.println(
                    parent[i] + " - " + i + " : " + graph[parent[i]][i]
            );
        }
    }
}
