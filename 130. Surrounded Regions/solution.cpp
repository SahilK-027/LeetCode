/*
40 ms
17.1 MB

TC : O(N * N)
SC : O(N * N)
*/

/**
 * @author : SahilK-027
 * @brief : BFS
*/

// Start with the boundary 'O's and mark all the connected nodes as true as they cannot be converted 
// Converst rest as X 
class Solution {
private:
    void DFS(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, vector<vector<int>>dist){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] == 'X') return;

        visited[i][j] = true;

        // DFS
        for(auto d: dist){
            DFS(board, visited, i+d[0], j + d[1], dist);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool>>visited(r, vector<bool>(c, false));
        vector<vector<int>>dist = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        // DFS Boundary check
        // Top row
        for(int j = 0; j < c; j++){
            if(board[0][j] == 'O' && !visited[0][j]){
                DFS(board, visited, 0, j, dist);
            }
        }
        // Bottom row
        for(int j = 0; j < c; j++){
            if(board[r-1][j] == 'O' && !visited[r-1][j]){
                DFS(board, visited, r-1, j, dist);
            }
        }
        // Left col
        for(int i = 0; i < r; i++){
            if(board[i][0] == 'O' && !visited[i][0]){
                DFS(board, visited, i, 0, dist);
            }
        }
        // Bottom col
        for(int i = 0; i < r; i++){
            if(board[i][c-1] == 'O' && !visited[i][c-1]){
                DFS(board, visited, i, c-1, dist);
            }
        }

        // Convert the rest to X
        for(int i = 0 ; i < r ;i++){
            for(int j = 0 ; j < c; j++){
                if(!visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};