/*
4 ms
6.3 mb
*/

/**
 * @author : SahilK-027
 * @brief : Recursion + Back tracking
*/

class Solution {
private:
    bool isSafe(int& row, int& col,vector<string>& board, int& n ){
        int x = row;
        int y = col;
        //Horizontal left
        while(y >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
        }
        // Diagonal up
        x = row;
        y = col;
        while(y >= 0 && x >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
            x--;
        }
        // Diagonal down
        x = row;
        y = col;
        while(y >= 0 && x < n){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
            x++;
        }
        // Queen is safe to place
        return true;
    }
    void solve(vector<string>& board, int n, int & ans, int col){
        if (col == n){
            ans = ans + 1;
            return;
        }
        for(int row = 0 ; row < n; row++){
            if(isSafe(row, col, board, n)){
                // Place queen
                board[row][col] = 'Q';
                // Recursive call
                solve(board, n, ans, col+1);
                 // Backtrack
                board[row][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n,string(n,'.'));
        int col = 0;
        solve(board, n, ans, col);
        return ans;
    }
};