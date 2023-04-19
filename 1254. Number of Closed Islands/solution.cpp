/*
Runtime : 16 ms
Memory : 9.8 MB

TC : O(N * N)
SC : O(N * N)
*/

/**
 * @author : Sahilk-027
 * @brief : Dfs
*/

class Solution {
private:
    int dfs(vector<vector<int>>& grid, int rows, int cols, int i , int j, vector<vector<bool>>& visited){
        if(i < 0 || j < 0 || i >= rows || j >= cols){
            // means not a closed Island
            return 0;
        }
        if(grid[i][j] == 1 || visited[i][j] == true){
            return 1;
        }

        visited[i][j] = true;
        int down = dfs(grid, rows, cols, i+1, j, visited);
        int left = dfs(grid, rows, cols, i, j-1, visited);
        int up = dfs(grid, rows, cols, i-1, j, visited);
        int right = dfs(grid, rows, cols, i, j+1, visited);
        //  If everywhere is water means it is Island
        if(down == 1 && left == 1 && up == 1 && right == 1) return 1;
        return 0;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        // Finding the bounds
        int rows = grid.size();
        int cols = grid[0].size();

        // To keep track of visited
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int ans =0;

        // Run DFS for positions where there is no water
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] != 1 && !visited[i][j]){
                    ans += dfs(grid, rows, cols, i, j, visited);
                }
            }
        }

        return ans;
    }
};