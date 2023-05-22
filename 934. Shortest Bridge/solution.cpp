/*
101 ms
31 MB

TC : O(N * N)
SC : O(N * N)
*/

/**
 * @author : SahilK-027
 * @brief : Multi-source BFS
*/

// As we are given exactly two islands...First we will traverse the entire island-1 and mark all its components as visited
// Then we will perform multisource BFS to expand the entire island 1 and reach to island 2
class Solution {
private:
    void DFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, queue<pair<int, int>>& q){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() 
        || visited[i][j] || grid[i][j] == 0){
            return;
        }
        visited[i][j] = true;
        q.push({i, j});

        // DFS Calls
        DFS(grid, visited, i + 1, j, q);
        DFS(grid, visited, i - 1, j, q);
        DFS(grid, visited, i, j + 1, q);
        DFS(grid, visited, i, j - 1, q);
    }
    int Multisource_BFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q, vector<vector<int>>& directions){
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            // We'll expand the whole island in one step
            while(size-- > 0){
                pair<int, int> curr_node = q.front();
                q.pop();                

                for(auto dir: directions){
                    int i =  curr_node.first + dir[0];
                    int j =  curr_node.second + dir[1];

                    if(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && !visited[i][j]){
                        // If we found 1 on grid and it has not been visited means we have found new island
                        if(grid[i][j] == 1 && !visited[i][j]){
                            return ans;
                        }
                        else{
                            q.push({i, j});
                            visited[i][j] = true;
                        }
                    }
                }
            }
            // Once the step is sone ans++;
            ans++;
        }
        return -1;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        // DFS -> Traverse Island 1
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        queue<pair<int, int>> q;
        int island1_traversed = false;
        for(int i = 0 ; i < r; i++){
            for(int j = 0 ; j < c; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    DFS(grid, visited, i, j, q);
                    island1_traversed = true;
                    break;
                }
            }
            if(island1_traversed) break;
        }
        // MULTISOURCE_BFS
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0,-1}};
        return Multisource_BFS(grid, visited, q, directions);
    }
};