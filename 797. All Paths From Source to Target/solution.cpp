/*
15 ms
10.7 MB

TC : O(N + E)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive DFS + BACKTRACKING 
*/

class Solution {
private:
    void DFS(int i, vector<int> & temp, vector<vector<int>>& ans, map<int, vector<int>>& adj_list, vector<int>& visited, int n){
        // If reached destination node store answer
        if(i == n-1){
            temp.push_back(i);
            ans.push_back(temp);
            temp.pop_back();
        }
        // Mark visited of current node true
        visited[i] = true;
        // Store current node in temp
        temp.push_back(i);
        for(auto node: adj_list[i]){
            if(!visited[node]){
                // Action
                visited[node] = true;
                // Recursive call
                DFS(node, temp, ans, adj_list, visited, n);
                // Backtrack
                temp.pop_back();
                visited[node] = false;
            }
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        // Memory to store all the possible answers
        vector<vector<int>> ans;
        vector<int> temp;

        // Adjacency list
        map<int, vector<int>>adj_list;
        for(int i = 0 ; i < graph.size(); i++){
            for(int j = 0 ;j < graph[i].size(); j++){
                adj_list[i].push_back(graph[i][j]);
            }
        }
        
        // DFS traversal
        vector<int>visited(n+1, false);
        DFS(0, temp, ans, adj_list, visited, n);
        return ans;
    }
};