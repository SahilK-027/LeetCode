/*
37 ms
6.6 MB

TC : O(9^(N*N))
SC : O(N*N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursion + BACKTRACKING 
*/

class Solution {
private:
    bool isSafe(int k , int row, int col,vector<vector<char>>& board){
        for(int i = 0 ; i < 9 ; i++){
            // Row check
            if(board[row][i] == char(k)) return false;
            // Col check
            if(board[i][col] == char(k)) return false;
            // 3x3 Matrix
            if(board[3 * (row/3) + (i /3)][3 * (col /3) + i %3] == char(k)) return false;
        }
        return true;

    }
    bool solve(vector<vector<char>>& board){
        // The code will terminate automatically whe. the for loops end so there is no need of base case
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9 ; col++){
                // We are currently standing on a cell
                // If cell is already solved no need to solve
                if(board[row][col] == '.')
                {                    
                    // Try placing all the numbers from 1 - 9 
                    for(int k = 49 ; k <= 57 ;k++){
                        // Check is safe placing num at current index
                        if(isSafe(k, row, col, board)){
                            // Place char at location
                            board[row][col] = char(k);
                            // Recursive call
                            bool recAns = solve(board);
                            if(recAns == true){
                                return true;
                            }
                            else{
                                // The recursion answer is false so our previous placement might be wrong hece backtrack
                                 board[row][col] = '.';
                            }
                        }
                    }
                    return false;  
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        solve(board);
    }
};