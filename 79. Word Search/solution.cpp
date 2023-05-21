/*
475 ms
8.1 MB

TC : O(N*N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : DFS
*/

class Solution {
private:
    bool DFS(int r, int c, vector<vector<char>>& board, string& word, 
    vector<vector<bool>>&visited, int index){
        if( index == word.length()) return true;
        if(r < 0 || c < 0 || r >= board.size() || c>= board[0].size()
            || word[index] != board[r][c] || visited[r][c]
            )
        return false;

        visited[r][c] = true;
        bool res = (
            DFS(r + 1, c, board, word, visited, index + 1) 
            ||
            DFS(r - 1, c, board, word, visited, index + 1) 
            ||
            DFS(r, c + 1, board, word, visited, index + 1) 
            ||
            DFS(r, c - 1, board, word, visited, index + 1) 
        );
        visited[r][c] = false;

        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>visited(board.size(), vector<bool>(board[0].size(), false));
        // Run DFS for every single position
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board[0].size(); j++){
                if(DFS(i, j, board, word, visited, 0) == true) return true;
            }
        }
        return false;
    }
};