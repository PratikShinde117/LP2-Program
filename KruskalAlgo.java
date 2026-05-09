import java.util.*;

class Edge {
    int u, v, wt;

    Edge(int u, int v, int wt) {
        this.u = u;
        this.v = v;
        this.wt = wt;
    }
}

public class Main {

    static int[] parent = new int[100];

    // Find ultimate parent
    static int findParent(int node) {

        if (parent[node] == node) {
            return node;
        }

        return findParent(parent[node]);
    }

    // Merge two sets
    static void unionSet(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        parent[pu] = pv;
    }

    public static void main(String[] args) {

        int V = 5;

        ArrayList<Edge> edges = new ArrayList<>();

        edges.add(new Edge(0, 1, 2));
        edges.add(new Edge(1, 2, 3));
        edges.add(new Edge(0, 3, 6));
        edges.add(new Edge(1, 4, 5));
        edges.add(new Edge(2, 4, 7));
        edges.add(new Edge(1, 3, 8));
        edges.add(new Edge(3, 4, 9));

        // Sort edges according to weight
        Collections.sort(edges, (a, b) -> a.wt - b.wt);

        // Initialize parent array
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int totalWeight = 0;

        System.out.println("Edges in MST:");

        for (Edge edge : edges) {

            int u = edge.u;
            int v = edge.v;
            int wt = edge.wt;

            // Check cycle
            if (findParent(u) != findParent(v)) {

                System.out.println(u + " - " + v + " : " + wt);

                totalWeight += wt;

                unionSet(u, v);
            }
        }

        System.out.println("Total Weight = " + totalWeight);
    }
}
