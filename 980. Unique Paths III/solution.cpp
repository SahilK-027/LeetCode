/*
6 ms
7.2 MB

TC: O(2^(n^2))
SC: O(n^2)
*/

/**
 * @author : Sahilk-027
 * @brief : Using recursion + backtracking
*/

class Solution {
private:
    // isInbound
    bool isInbound(int x, int y, int m, int n){
        if((x >= 0 && x < m && y >= 0 && y <n)) return true;
            return false;
    }
    // isVisited
    bool isVisited(int x, int y, vector<vector<bool>>& visited){
        return (visited[x][y] == true);
    }
    // isOpenPath
    bool isOpenPath(int x, int y, vector<vector<int>>& grid){
        if(grid[x][y] != -1) return true;
        return false;
    }
    // IsSafe function
    bool is_safe(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited, int m, int n){
        if(isInbound(x,y,m,n) && !isVisited(x, y, visited) && isOpenPath(x,y,grid)){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& ans, int srcx, int srcy, int desx, int desy, int m, int n, int empty_cell_cnt, int cnt = 0){
        // If sorce of robot = destination we have found one valid path
        if(srcx == desx && srcy == desy){
            // increment ans if all empty cells are covered
            if(cnt == empty_cell_cnt){
                ans++;
            }
            cnt = 0;
            return;
        }
        // Recursive calls to solve maze
        // Down call
        if(is_safe(srcx+1,srcy, grid, visited, m, n)){
            // Visit the location
            visited[srcx+1][srcy] = true;
            cnt += 1;
            // Next call
            solve(grid, visited, ans, srcx+1, srcy, desx, desy, m, n, empty_cell_cnt, cnt);
            //Backtrack
            visited[srcx+1][srcy] = false;
            cnt -= 1;
        }

        // Right call
        if(is_safe(srcx,srcy+1, grid, visited, m, n)){
            // Visit the location
            visited[srcx][srcy+1] = true;
            cnt += 1;
            solve(grid, visited, ans, srcx, srcy+1, desx, desy, m, n, empty_cell_cnt, cnt);
            //Backtrack
            visited[srcx][srcy+1] = false;
            cnt -= 1;
        }

        // Up call
        if(is_safe(srcx-1,srcy, grid, visited, m, n)){
            // Visit the location
            visited[srcx-1][srcy] = true;
            cnt += 1;
            // Next call
            solve(grid, visited, ans, srcx-1, srcy, desx, desy, m, n, empty_cell_cnt, cnt);
            //Backtrack
            visited[srcx-1][srcy] = false;
            cnt -= 1;
        }

        // Left call
        if(is_safe(srcx,srcy-1, grid, visited, m, n)){
            // Visit the location
            visited[srcx][srcy-1] = true;
            cnt += 1;
            solve(grid, visited, ans, srcx, srcy-1, desx, desy, m, n, empty_cell_cnt, cnt);
            //Backtrack
            visited[srcx][srcy-1] = false;
            cnt -= 1;
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        // Fast i/o
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        // Storing row and column numbers
        int m = grid.size();
        int n = grid[0].size();

        // Defining starting and ending position
        int srcx = -1;
        int srcy = -1;
        int desx = -1;
        int desy = -1;

        // We have to return the number of walks which cover all the non-obstacle square exactly once. so we are initially counting empty_cell_cnt
        int empty_cell_cnt = 1;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ;j++){
                if(grid[i][j] == 1){
                    srcx = i;
                    srcy = j;
                }
                else if(grid[i][j] == 2){
                    desx = i;
                    desy = j;
                }
                else if(grid[i][j] == 0){
                    empty_cell_cnt++;
                }
            }
        }
        // Created visited matrix to keep track of visited path
        vector<vector<bool>> visited(m, vector<bool>(n,false));

        // robot initially located at the top-left corner (i.e., grid[0][0])
        visited[srcx][srcy] = true;

        // answer var to store ans
        int ans = 0;
        solve(grid, visited, ans, srcx, srcy, desx, desy, m, n, empty_cell_cnt);
        return ans;
    }
};
