#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<int> adj[], int start, int V) {

    vector<bool> visited(V, false);

    queue<int> q;

    visited[start] = true;

    q.push(start);

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int neighbor : adj[node]) {

            if(!visited[neighbor]) {

                visited[neighbor] = true;

                q.push(neighbor);
            }
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

    cout << "BFS Traversal:\n";

    BFS(adj, 0, V);

    return 0;
}
