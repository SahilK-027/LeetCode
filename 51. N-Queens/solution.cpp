class Solution {
private:
    bool isSafe(vector<string>& chessBoard, int& row, int& col, int& n){
        // Check if there exists queen 
        //check straight movement
        int x = row;
        int y = col;
        while(y >= 0) {
            if(chessBoard[x][y] == 'Q') return false;
            y--;
        }
        
        //check upper diagnol
        x = row;
        y = col;
        while(x >=0 && y >= 0) {
            if(chessBoard[x][y] == 'Q') return false;
            x--;
            y--;
        }

        //cheeck lower diagnol
        x = row;
        y = col;
        while(x <n && y >= 0) {
            if(chessBoard[x][y] == 'Q') return false;
            x++;
            y--;
        }

        // Not returned false yet means the place is safe
        return true;
    }
    void solve(vector<vector<string>>& ans, vector<string>& chessBoard, int col, int& n){
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
            if(isSafe(chessBoard, row, col, n)){
                // Place queen
                chessBoard[row][col] = 'Q';
                // Recursion will solve remaining board
                solve(ans, chessBoard, col+1, n);
                // Backtrack
                chessBoard[row][col] = '.';
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
        solve(ans, chessBoard, col, n);
        return ans;
    }
};