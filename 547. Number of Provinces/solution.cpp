/*
49 ms
14.1 MB

TC : O(N*N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief :  BFS
*/

class Solution {
private:
    // Simple BFS logic
    void BFS(int node, vector<vector<int>>& adj_mtrx, vector<bool>& visited, int n){
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int col = 0; col < n; col++){
                if(adj_mtrx[front][col] == 1 && !visited[col]){
                    visited[col] = true;
                    q.push(col);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& adj_mtrx) {
        // Initial answer
        int ans = 0;
        int n = adj_mtrx.size();
        // BFS
        vector<bool>visited(n,false);
        // Traverse for each connected or unconnected component in graph
        for(int i = 0; i < n ;i++){
            // If a separate component found ans++
            if(!visited[i]){
                BFS(i, adj_mtrx, visited, n);
                ans++;
            } 
        }
        return ans;
    }
};