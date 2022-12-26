/*
361 ms
105.4 MB

TC : O(n)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Simple undirected graph
*/

// The node with outdegree == indegree == n-1 will be the center of Star Graph
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = INT_MIN;
        // Keep track of out and in degree of each vertex
        unordered_map<int, int>out_deg;
        unordered_map<int, int>in_deg;
        // LOOP to set degree of each vertex
        for(auto i: edges){
            out_deg[i[0]]++;
            in_deg[i[1]]++;
            // Given graph is undirected
            out_deg[i[1]]++;
            in_deg[i[0]]++;
            // Finding number of vertices in graph
            n = max(n, max(i[1], i[0]));
        }
        for(int i = 1; i<=n; i++){
            // if for a node outdegree == indegree == n-1 then its center
            if(out_deg[i] == in_deg[i] && out_deg[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};