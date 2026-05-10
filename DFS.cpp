#include <iostream>
#include <vector>

using namespace std;

void DFS(int node,
         vector<int> adj[],
         vector<bool>& visited) {

    visited[node] = true;

    cout << node << " ";

    for(int neighbor : adj[node]) {

        if(!visited[neighbor]) {

            DFS(neighbor, adj, visited);
        }
    }
}

int main() {

    int V = 5;

    vector<int> adj[V];

    // Undirected Graph
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    vector<bool> visited(V, false);

    cout << "DFS Traversal:\n";

    DFS(0, adj, visited);

    return 0;
}
