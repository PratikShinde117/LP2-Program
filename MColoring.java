import java.util.*;

class Solution {

    boolean isPossible(ArrayList<Integer>[] adj, int ind, int colour, int[] colours) {

        for (int i = 0; i < adj[ind].size(); i++) {

            int adjNode = adj[ind].get(i);

            if (colours[adjNode] == colour) {
                return false;
            }
        }

        return true;
    }

    boolean recursion(ArrayList<Integer>[] adj, int m, int n,
                      int ind, int[] colours) {

        if (ind == n) {
            return true;
        }

        for (int i = 1; i <= m; i++) {

            if (isPossible(adj, ind, i, colours)) {

                colours[ind] = i;

                boolean val = recursion(adj, m, n, ind + 1, colours);

                if (val) {
                    return true;
                }

                colours[ind] = -1;
            }
        }

        return false;
    }

    public boolean MColoring(int[][] edges, int m, int n) {

        ArrayList<Integer>[] adj = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        int[] colours = new int[n];

        Arrays.fill(colours, -1);

        for (int[] edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].add(v);
            adj[v].add(u);
        }

        return recursion(adj, m, n, 0, colours);
    }
}

public class Main {

    public static void main(String[] args) {

        Solution sol = new Solution();

        int[][] edges = {
                {0, 1},
                {0, 2},
                {1, 2},
                {1, 3}
        };

        int m = 3;
        int n = 4;

        if (sol.MColoring(edges, m, n)) {
            System.out.println("The graph can be colored with " + m + " colors.");
        } else {
            System.out.println("The graph cannot be colored with " + m + " colors.");
        }
    }
}
