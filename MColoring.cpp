#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
    
    bool isPossible(vector<int>adj[], int ind, int colour, vector<int>&colours){
        for(int i=0; i<adj[ind].size(); i++){
            int adjNode = adj[ind][i];
            
            if(colours[adjNode] == colour){
                return false;
            }
        }
        
        return true;
    }
    
    bool recursion(vector<int>adj[], int m, int n, int ind, vector<int>&colours){
        
        if(ind == n){
            return true;
        }
        
        for(int i=1; i<=m; i++){
            if(isPossible(adj, ind, i, colours)){
                colours[ind] = i;
                
                bool val = recursion(adj, m, n, ind+1, colours);
                
                if(val) return true;
                
                colours[ind] = -1;
            }
        }
        
        return false;
    }
    
    public:
    
    bool MColoring(vector<vector<int>>& edges, int m, int n){
        vector<int>adj[n];
        vector<int>colours(n,-1);
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return recursion(adj, m, n, 0, colours);
    }
    
};

int main() {
    
    Solution sol;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}
    };
    int m = 3; 
    int n = 4; 

   
    if (sol.MColoring(edges, m, n)) {
        cout << "The graph can be colored with " << m << " colors." << endl;
    } else {
        cout << "The graph cannot be colored with " << m << " colors." << endl;
    }
    
    
    return 0;
}
