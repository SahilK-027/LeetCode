/*
267 ms
80.5 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Hashing
*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int>mp1;
        unordered_map<int , int>mp2;
        int mini = INT_MAX;
        for(auto i: nums1){
            mp1[i]++;
        }
        for(auto i: nums2){
            mp2[i]++;
        }
        for(auto i: mp1){
            if(mp2.find(i.first) != mp2.end()){
                if(i.first < mini){
                    mini = i.first ;
                }
            }
        }
        for(auto i: mp2){
            if(mp1.find(i.first) != mp1.end()){
                if(i.first < mini){
                    mini = i.first ;
                }
            }
        }
        return mini != INT_MAX? mini : -1;
    }
};