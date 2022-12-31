/*
287 ms
85.1 MB

TC : O(N^2)
SC : O(N^2)
*/

/**
 * @author : SahilK-027
 * @brief : Depth First Search
*/

class Solution {
private:
    void dfs1(vector<int> adj[], vector<int>& child, int length, int root, vector<int>& visited,vector<int> &ans){
        visited[root] = 1;
        ans[0] += length;
        length++;
        for(auto& x: adj[root]){
            if(visited[x]) continue;
            dfs1(adj, child, length, x, visited, ans);
            child[root] += child[x];
        }
        child[root] += 1;
    }
    
    void dfs2(vector<int> adj[], vector<int>& child, int root, vector<int>& visited, int n, vector<int>& ans){
        visited[root] = 1;
        for(auto& x: adj[root]){
            if(visited[x]) continue;
            ans[x] = ans[root] - child[x] + n - child[x];
            dfs2(adj , child, x, visited, n, ans);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // Array of vector : Craeting n vector
        vector<int> adj[n];
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // Needed declaration
        vector<int> ans(n);
        vector<int> child(n);
        vector<int> visited(n);
        dfs1(adj , child, 0, 0, visited, ans);
        // Reset visited vector
        for(int i=0;i<n;i++){
            visited[i]=0;
        }
        dfs2(adj , child, 0, visited, n, ans);
        return ans;
    }
    
};