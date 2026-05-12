#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(queue<int>& q,
         vector<int> adj[],
         vector<bool>& visited,
         vector<int>& ans) {

    // Base Case
    if(q.empty())
        return;

    int node = q.front();

    q.pop();

    ans.push_back(node);

    // Traverse neighbours
    for(auto neighbour : adj[node]) {

        if(!visited[neighbour]) {

            visited[neighbour] = true;

            q.push(neighbour);
        }
    }

    // Recursive Call
    BFS(q, adj, visited, ans);
}

int main() {

    int n = 4;

    vector<int> adj[n];

    vector<bool> visited(n, false);

    vector<int> ans;

    // Undirected Graph

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    queue<int> q;

    int start = 0;

    q.push(start);

    visited[start] = true;

    BFS(q, adj, visited, ans);

    cout << "Recursive BFS Traversal: ";

    for(int node : ans) {

        cout << node << " ";
    }

    return 0;
}
