/*
Runtime : 643 ms
Memory : 162.5 MB

TC: O(V + E)
SC: O(V + E)
*/

/**
 * @author : Sahilk-027
 * @brief : Dynamic Programming
*/

class Solution {
private:
    typedef array<int, 26> T;
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // Adj lisr
        unordered_map<int, vector<int>> adj_list;
        vector<int> indegree(colors.size());
        for (auto &e : edges) {
            adj_list[e[0]].push_back(e[1]); 
            indegree[e[1]]++;
        }

        // cnt[i][j] is the maximum count of j-th color from the ancester nodes to node i.
        vector<T> cnt(colors.size(), T{}); 
        // Perform BFS
        queue<int> q;
        for (int i = 0; i < colors.size(); ++i) {
            // if this node has 0 indegree, we can use it as a source node
            if (indegree[i] == 0) { 
                q.push(i);
                // the count of the current color should be 1
                cnt[i][colors[i] - 'a'] = 1; 
            }
        }
        int ans = 0, seen = 0;
        while (q.size()) {
            auto u = q.front();
            q.pop();
             // we use the maximum of all the maximum color counts as the color value.
            int val = *max_element(begin(cnt[u]), end(cnt[u]));
            ans = max(ans, val);
            ++seen;
            for (int v : adj_list[u]) {
                for (int i = 0; i < 26; ++i) {
                    // try to use node `u` to update all the color counts of node `v`.
                    cnt[v][i] = max(cnt[v][i], cnt[u][i] + (i == colors[v] - 'a')); 
                }
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return seen < colors.size() ? -1 : ans;
    }
};