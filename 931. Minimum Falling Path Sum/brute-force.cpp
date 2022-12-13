/*
TLE
*/

/**
 * @author : Sahilk-027
 * @brief : Recursion + Backtracking
*/

/*
⚠️ This solution will require optimization else it will give TLE but its added here to understand how solution looked before optimization.
*/

class Solution {
private:
    bool isSafe(int x, int y, vector<vector<int>>& matrix, int n){
        return (x>=0 && y >=0 && x <n && y<n);
    }
private:
    void solve(vector<vector<int>>& matrix, int n, int col, int& minSum, int& currAns, int row = 0){
        if(row >= n-1){
            // In each recursive call we will keep storing minimum path sum
            minSum = min(minSum, currAns);
            return;
        }

        // Down Cell
        if(isSafe(row + 1, col, matrix, n)){
            // Add the cell value to currAns
            currAns += matrix[row + 1][col];
            // Recursive call
            solve(matrix, n, col, minSum, currAns , row+1);
            // Backtrack
            currAns -= matrix[row + 1][col];
        }
        // Diagonal right cell
        if(isSafe(row + 1, col + 1, matrix, n)){
            // Add the cell value to currAns
            currAns += matrix[row + 1][col+1];
            // Recursive call
            solve(matrix, n, col + 1, minSum, currAns , row+1);
            // Backtrack
            currAns -= matrix[row + 1][col + 1];
        }
        // Diagonal left cell
        if(isSafe(row + 1, col-1, matrix, n)){
            // Add the cell value to currAns
            currAns += matrix[row + 1][col-1];
             // Recursive call
            solve(matrix, n, col-1, minSum, currAns, row+1);
            // Backtrack
            currAns -= matrix[row + 1][col-1];
        }
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minPathSum = INT_MAX;

        // First we will send recursive calls for first element of each column
        for(int col = 0 ; col < n ; col++){
            int minSum = INT_MAX;
            int currAns = matrix[0][col];
            solve(matrix, n, col, minSum, currAns);
            // Finally we will return minimum of all 
            minPathSum = min(minPathSum, minSum);
        }
        return minPathSum;
    }
};
