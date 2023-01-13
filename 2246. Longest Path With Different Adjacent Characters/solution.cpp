/*
1228 ms
389.9 MB

TC : O(N + m)
SC : O(N + m)
*/

/**
 * @author : SahilK-027
 * @brief :  Recursive DFS
*/

class Solution {
private:
    void DFS(int node, unordered_map<int, set<int>>& adj_list, vector<int>&visited, string& s, vector<int> &distance, int& ans){
        visited[node] = true;
        // Current distance of node will be 1
        distance[node] = 1;
        for(auto child: adj_list[node]){
            if(!visited[child]){  
                visited[child] = true;
                // Go to last node
                DFS(child, adj_list, visited, s, distance, ans);
                // If children not equal to parent
                if(s[node] != s[child]){
                    // answer will get updated by new distance provided new distance is larger
                    ans = max(ans, distance[node]+ distance[child]);
                    // And distance will also get updated
                    distance[node] = max(distance[node], distance[child]+1);
                }
            }
        }
    }
public:
    int longestPath(vector<int>& parent, string s) {
        // Edge case
        if(parent.size() == 1) return 1;
        // Creating adj_list
        unordered_map<int, set<int>>adj_list;
        for(int i = 1; i < parent.size(); i++){
            adj_list[parent[i]].emplace(i);
            adj_list[i].emplace(parent[i]);
        }
        // DFS
        vector<int>distance(s.length()+1);
        vector<int>visited(s.length()+1);
        // Initially answer will be 1 as we are standing on root node
        int ans = 1;
        DFS(0, adj_list, visited, s, distance, ans);
        return ans;
    }
};