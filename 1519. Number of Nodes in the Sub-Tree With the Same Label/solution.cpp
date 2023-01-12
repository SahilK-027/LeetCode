/*
705 ms
231 MB

TC : O(N + m)
SC : O(N + m)
*/

/**
 * @author : SahilK-027
 * @brief :  Recursive DFS
*/

class Solution {
private:
    void dfs(int i, string &labels,  unordered_map<int, set<int>>& adj_list, int* cnt, vector<int> &ans) 
    {
        if (ans[i] == 0) 
        {
            ans[i] = 1;
            for (auto node : adj_list[i]) {
                int cnt1[26]= {};
                dfs(node, labels, adj_list, cnt1, ans);
                for (auto k = 0; k < 26; ++k){
                    cnt[k] += cnt1[k];
                }
                    
            }
            ans[i] = ++cnt[labels[i] - 'a'];
        }
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        // Creating Adjacency matrix
        unordered_map<int, set<int>> adj_list;
        for(auto i: edges){
            adj_list[i[0]].emplace(i[1]);
            adj_list[i[1]].emplace(i[0]);
        }
        // DFS
        vector<int> ans(n, 0);
        int cnt[26] = {};
        dfs(0, labels, adj_list, cnt, ans);
        return ans;
    }
};