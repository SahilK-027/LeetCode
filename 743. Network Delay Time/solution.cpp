/*
138 ms
46 MB
*/

/**
 * TC: O(E log V)
 * SC: O(E + V)
 */

/**
 * @author : SahilK-027
 * @brief :  Dijkstra's Algo
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Fast i/o
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // Creating adj list
        unordered_map<int, list<pair<int, int>>>adj_list;
        for(auto i: times){
            adj_list[i[0]].push_back(make_pair(i[1], i[2]));
        }
        // Create distance array
        vector<int>distance(n+1, INT_MAX);
        // As k is the source mark it's distance as 0
        distance[k] = 0;
        // We'll use set to store distance and node
        set<pair<int, int>>st;
        st.emplace(make_pair(0, k));

        // Start the algorithm
        while(!st.empty()){
            auto top = *(st.begin());
            int node_dist =  top.first;
            int node_val = top.second;
            // Delete the top node
            st.erase(st.begin());
            // Traverse the neighbour of top
            for(auto neighbour: adj_list[node_val])
            {
                if(node_dist + neighbour.second < distance[neighbour.first])
                {
                    distance[neighbour.first] = node_dist + neighbour.second;
                    st.emplace(distance[neighbour.first], neighbour.first);
                }
            }
        }
        // Finding answer
        int cnt = 0;
        int ans = INT_MIN;
        for(auto i: distance){
            if(i == INT_MAX){
                cnt++;
            }
            if(i > ans && i != INT_MAX){
                ans = i;
            }
        }
        // If there are more than 1 node with infinity distance from source 
        // Means we cannot reach to all nodes starting from the source so return -1
        if(cnt > 1) return -1;
        else return ans;
    }
};