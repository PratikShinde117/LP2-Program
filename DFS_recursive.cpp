#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(int start,
         vector<int> adj[],
         vector<bool>& visited,
         vector<int>& ans) {

    stack<int> st;

    st.push(start);

    while(!st.empty()) {

        int node = st.top();

        st.pop();

        // Skip if already visited
        if(visited[node])
            continue;

        visited[node] = true;

        ans.push_back(node);

        // Push neighbours
        // Reverse order for natural traversal
        for(int i = adj[node].size() - 1; i >= 0; i--) {

            int neighbour = adj[node][i];

            if(!visited[neighbour]) {

                st.push(neighbour);
            }
        }
    }
}

int main() {

    int n = 5;

    vector<int> adj[n];

    vector<bool> visited(n, false);

    vector<int> ans;

    // Undirected Graph

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(4);
    adj[4].push_back(2);

    DFS(0, adj, visited, ans);

    cout << "DFS Traversal: ";

    for(int node : ans) {

        cout << node << " ";
    }

    return 0;
}
