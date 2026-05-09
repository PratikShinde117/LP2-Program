#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){

    int V = 5;

    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    vector<int>key(V, INT_MAX);
    vector<int>parent(V, -1);
    vector<bool>mst(V, false);
    
    key[0] = 0;
    
    for(int count = 0; count < V-1; count++){
        int u = -1;
        int mini = INT_MAX;
        
        
        
        for(int i=0; i<V; i++){
            if(!mst[i] && key[i] < mini){
                mini = key[i];
                u = i;
            }
        }
        
        mst[u] = true;
        
        for(int v=0; v<V; v++){
            if(!mst[v] && graph[u][v] != 0 && graph[u][v] < key[v]){
                key[v] = graph[u][v];
                parent[v] = u;
                
            }
        }
       
    }
    
     cout<<"Edges in MST:\n";

    for(int i=1; i<V; i++){

        cout<<parent[i]
            <<" - "
            <<i
            <<" : "
            <<graph[parent[i]][i]
            <<endl;
    }
    
    return 0;
}
