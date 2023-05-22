/*
337 ms
73.7 MB

TC : O(N * N)
SC : O(N * N)
*/

/**
 * @author : SahilK-027
 * @brief : BFS
*/

// How long did we take to reach each cell starting from a particular 0
class Solution {
private:
    void BFS(vector<vector<int>>& mat, vector<vector<bool>>& visited, queue<pair<pair<int, int>, int>>& q, vector<vector<int>>& directions, int r, int c, vector<vector<int>>& ans){
        while(!q.empty()){
            pair<pair<int, int>, int> curr_node = q.front();
            int i = curr_node.first.first;
            int j = curr_node.first.second;
            int time = curr_node.second;
            ans[i][j] = time;
            q.pop();

            for(auto d: directions){
                int new_i = curr_node.first.first + d[0];
                int new_j = curr_node.first.second + d[1];

                if(new_i >= 0 && new_j >= 0 && new_i < r && new_j < c && !visited[new_i][new_j]){
                    visited[new_i][new_j] = true;
                    q.push({{new_i, new_j}, time + 1});
                }
            }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> ans(r, vector<int>(c, 0));
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        // {{r,c},time}
        queue<pair<pair<int, int>, int>>q;
        vector<vector<int>>directions = {{1, 0}, {-1, 0}, {0, 1}, {0,-1}};
        for(int i = 0 ; i < r; i++){
            for(int j = 0 ; j < c; j++){
                if(mat[i][j] == 0){
                    visited[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }
        }
        BFS(mat, visited, q, directions, r, c, ans);
        return ans;
    }
};