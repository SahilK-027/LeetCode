class Solution {
private:
    bool isSafe(vector<int>& Leftrow,  vector<int>& upper_diagonal,  vector<int>& lower_diagonal, int row, int col, int n){
        return(Leftrow[row] == 0 && upper_diagonal[n-1 + col - row] == 0 && lower_diagonal[row+col] == 0);
    }
    void solve(vector<vector<string>>& ans, vector<string>& chessBoard, int col, int& n,  vector<int>& Leftrow,  vector<int>& upper_diagonal,  vector<int>& lower_diagonal){
        // Base case
        // If we are able to place all queens in all cols then store current board config. in answer and return
        if(col == n){
            // Store answer
            ans.push_back(chessBoard);
            // Return
            return;
        }

        // Otherwise for all rows in same column check where you can place queen
        for(int row = 0; row < n ; row++){
            if(isSafe(Leftrow, upper_diagonal, lower_diagonal, row, col, n)){
                Leftrow[row] = 1;
                upper_diagonal[n-1 + col - row] = 1;
                lower_diagonal[row+col] = 1;
                // Place queen
                chessBoard[row][col] = 'Q';
                // Recursion will solve remaining board
                solve(ans, chessBoard, col+1, n, Leftrow, upper_diagonal,lower_diagonal);
                // Backtrack
                chessBoard[row][col] = '.';
                Leftrow[row] = 0;
                upper_diagonal[n-1 + col - row] = 0;
                lower_diagonal[row+col] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int& n) {
        // Fast i/o
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // Answer
        vector<vector<string>> ans;
        // Creating chess board of size n
        vector<string> chessBoard(n, string(n,'.'));
        // We will place queen column wise;
        int col = 0;


        // Array to keep track of plced queen
        vector<int> Leftrow(2*n - 1, 0);
        vector<int> upper_diagnol(2*n - 1, 0);
        vector<int> lower_diagnol(2*n - 1, 0);

        solve(ans, chessBoard, col, n, Leftrow, upper_diagnol, lower_diagnol);
        return ans;
    }
};
