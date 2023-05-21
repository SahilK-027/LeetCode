/*
46 ms
12.2 MB

TC : O(N * M)
SC : O(M * M)
*/

/**
 * @author : SahilK-027
 * @brief : DFS
*/

class Solution {
private:
    void DFS(int row, int col, vector<vector<char>>& grid){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0'){
            return;
        }
        grid[row][col] = '0';
        // DFS CALL
        DFS(row + 1, col, grid);
        DFS(row - 1, col, grid);
        DFS(row, col + 1, grid);
        DFS(row, col - 1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    DFS(i, j, grid);
                }
            }
        }
        return ans;
    }
};