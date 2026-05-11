#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int prims(int V, vector<pair<int,int>> adj[]) {

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<bool> visited(V, false);

    // {weight, node}
    pq.push({0, 0});

    int sum = 0;

    while(!pq.empty()) {

        auto it = pq.top();
        pq.pop();

        int weight = it.first;
        int node = it.second;

        // Skip if already visited
        if(visited[node])
            continue;

        visited[node] = true;

        sum += weight;

        // Traverse neighbours
        for(auto neighbour : adj[node]) {

            int adjNode = neighbour.first;
            int edgeWeight = neighbour.second;

            if(!visited[adjNode]) {

                pq.push({edgeWeight, adjNode});
            }
        }
    }

    return sum;
}

int main() {

    int V = 5;

    vector<pair<int,int>> adj[V];

    // Undirected Graph

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    int mstWeight = prims(V, adj);

    cout << "Minimum Spanning Tree Weight = "
         << mstWeight << endl;

    return 0;
}
