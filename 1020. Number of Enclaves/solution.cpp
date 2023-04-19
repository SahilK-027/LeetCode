/*
Runtime : 69 ms
Memory : 31.2 MB

TC : O(N * N)
SC : O(N * N)
*/

/**
 * @author : Sahilk-027
 * @brief : DFS
*/

class Solution {
private:
    void dfs(vector<vector<int>>&grid, int i, int j){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != 1){
            return ;
        }

        grid[i][j] = 0;
    
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i == 0 || j == 0 || i == rows-1 || j == cols-1)
                {
                    if(grid[i][j] == 1)
                    {
                        dfs(grid, i, j);
                    }
                }
            }
        }

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};