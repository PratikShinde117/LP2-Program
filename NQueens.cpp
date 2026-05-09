// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
    
    bool isSafe(int row, int col, vector<string>&board){
        int r = row;
        int c = col;
        
        //upper
        while(r >= 0){
            if(board[r][c] == 'Q') return false;
            r--;
        }
        
         r = row;
         c = col;
        
        //upper-left
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }
        
         r = row;
         c = col;
        
        while(r >= 0 && c < board.size()){
            if(board[r][c] == 'Q') return false;
            r--;
            c++;
        }
        
        return true;
    }
    
    void recursion(int row, vector<vector<string>>&ans, vector<string>&board, int n){
        
        if(row == board.size()){
            ans.push_back(board);
            return;
        }
        
        for(int col = 0; col < n; col++){
            if(isSafe(row, col, board)){
                board[row][col] = 'Q';
                recursion(row+1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }
    
    public:
    vector<vector<string>> NQueens(int n){
        vector<string>board(n, string(n, '.'));
        vector<vector<string>> ans;
        
        recursion(0, ans, board, n);
        
        return ans;
        
        
    }
};

int main() {
    
    Solution solution;
    int n = 4; 
    vector<vector<string>> solutions = solution.NQueens(n);

    
    for (const auto& sol : solutions) {
        for (const auto& row : sol) {
            cout << row << endl;
        }
        cout << endl;
    }

    
    return 0;
}
