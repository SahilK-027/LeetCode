/*
69 ms
33.1 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Hash Map
*/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        map<int, bool> mp1;
        map<int, bool> mp2;
        for(auto i: nums1){
            mp1[i] = true;
        }
        for(auto i: nums2){
            mp2[i] = true;
        }
        vector<int>absent1;
        for(auto i: mp1){
            if(mp2.find(i.first) == mp2.end()){
                absent1.push_back(i.first);
            }
        }
        vector<int>absent2;
        for(auto i: mp2){
            if(mp1.find(i.first) == mp1.end()){
                absent2.push_back(i.first);
            }
        }
        ans.push_back(absent1);
        ans.push_back(absent2);
        return ans;
    }
};