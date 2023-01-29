/*
44 ms
16.6 MB
*/

/**
 * TC: O(N)
 * SC: O(N)
 */

/**
 * @author : SahilK-027
 * @brief :  BFS
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        // Build adj matrix
        vector<vector<int>>adj[n];
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        // Run BFS
        vector<int>v(n, INT_MAX);
        v[src]=0;
        // Queue will store position, weight, and count
        queue<pair<int, pair<int, int>>>q;
        q.push({src, {0, 0}});
        while(!q.empty()){
            int pos = q.front().first;
            int wt = q.front().second.first ;
            int cnt = q.front().second.second;
            q.pop();
            for(auto i: adj[pos]){
                if(wt+i[1]<v[i[0]]){
                    // Checking for at most k stops.
                    if(cnt <= k){
                        v[i[0]]=i[1]+wt;
                        q.push({i[0], {wt+i[1], cnt+1}});
                    }
                }
            }
        }
        // If distance is INFINITE return -1 not possible else return distance
        return (v[dst]==INT_MAX) ? -1 : v[dst];
    }
};