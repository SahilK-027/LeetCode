/*
141 ms
24.3 MB
*/

/**
 * TC: O(E log V)
 * SC: O(E + V)
 */

/**
 * @author : SahilK-027
 * @brief :  Dijkstra's algorithm 
*/


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // Create adj_list
        unordered_map<int, list<pair<int, int>>>adj_list;
        for(auto i: edges){
            adj_list[i[0]].push_back(make_pair(i[1], i[2]));
            adj_list[i[1]].push_back(make_pair(i[0], i[2]));
        }

        // Create distance array for all nodes and initial mark 
        // All the shortest distances to INT_MAX
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        
        // Djkstra's Algo
        for(int i = 0; i < n ; i++){
            int src = i;
            // Distance of starting node from itself 
            distance[src][src] = 0;
            set<pair<int, int>> st;
            st.emplace(make_pair(0, src));
            while(!st.empty()){
                auto top = *(st.begin());
                st.erase(st.begin());
                int node_dist = top.first;
                int node_val = top.second;
                for(auto neighbour: adj_list[node_val]){
                    if(node_dist + neighbour.second < distance[src][neighbour.first]){
                        distance[src][neighbour.first] = node_dist + neighbour.second;
                        st.emplace(make_pair(distance[src][neighbour.first] , neighbour.first));
                    }
                }
            }
        }
        // Finding answer from all possible answers
        int cnt = INT_MAX;
        vector<int>possible_ans;
        for(int i = 0 ; i < n ; i++){
            int curr_cnt = 0;
            for(int j = 0 ; j < n; j++){
                if(distance[i][j] <= distanceThreshold){
                    curr_cnt++;
                }
            }
            if(curr_cnt <= cnt){
                cnt = curr_cnt;
                possible_ans.push_back(i);
            }
        }
        return possible_ans[possible_ans.size() - 1];
    }
};