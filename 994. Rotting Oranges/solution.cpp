/*
8 ms
13.2 MB

TC : O(V + E)
SC : O(V + E)
*/

/**
 * @author : SahilK-027
 * @brief : BFS
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //Queue will store {{row, col},time}
        queue<pair<pair<int, int>, int>>q;
        // initialization
        vector<vector<int>> visi(grid.size(), vector<int>(grid[0].size(), false));
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    visi[i][j] = true;
                }
            }
        }
        // BFS
        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int curr_row = q.front().first.first;
            int curr_col = q.front().first.second;
            int curr_time = q.front().second;
            time = max(time, curr_time);
            q.pop();
            for(int i = 0; i < 4;i++){
                int new_row = curr_row + drow[i];
                int new_col = curr_col + dcol[i];
                if(new_row >= 0 && 
                    new_col >= 0 && 
                    new_row <grid.size() && 
                    new_col < grid[0].size() && 
                    !visi[new_row][new_col] &&
                    grid[new_row][new_col] == 1
                    ){
                        q.push({{new_row,new_col}, curr_time+1});
                        visi[new_row][new_col] = true;
                }
            }
        }
        // Final check for all oranges 
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[0].size(); j++){
                if(visi[i][j] != true && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};