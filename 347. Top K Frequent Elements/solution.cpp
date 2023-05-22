/*
20 ms
13.7 MB

TC : O(N log N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Heap + Map
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int>mp;
        for(auto i: nums){
            mp[i]++;
        }
        priority_queue<pair<int, int>>pq;
        for(auto i: mp){
            pq.push({i.second, i.first});
        }
        while(k--){
            int num = pq.top().second;
            pq.pop();
            ans.push_back(num);
        }
        return ans;
    }
};