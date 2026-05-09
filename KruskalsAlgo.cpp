#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, wt;
};

bool compare(Edge a, Edge b) {
    return a.wt < b.wt;
}

int parent[100];

int findParent(int node) {

    if(parent[node] == node)
        return node;

    return findParent(parent[node]);
}

void unionSet(int u, int v) {

    int pu = findParent(u);
    int pv = findParent(v);

    parent[pu] = pv;
}

int main() {

    int V = 5;

    vector<Edge> edges = {
        {0,1,2},
        {1,2,3},
        {0,3,6},
        {1,4,5},
        {2,4,7},
        {1,3,8},
        {3,4,9}
    };

    sort(edges.begin(), edges.end(), compare);

    for(int i=0; i<V; i++) {
        parent[i] = i;
    }

    cout<<"Edges in MST:\n";

    int totalWeight = 0;

    for(auto edge : edges) {

        int u = edge.u;
        int v = edge.v;
        int wt = edge.wt;

        if(findParent(u) != findParent(v)) {

            cout<<u<<" - "<<v<<" : "<<wt<<endl;

            totalWeight += wt;

            unionSet(u, v);
        }
    }

    cout<<"Total Weight = "<<totalWeight;

    return 0;
}
