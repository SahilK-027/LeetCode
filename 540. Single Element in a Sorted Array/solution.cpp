/*
49 ms
27.5 MB
*/
/**
 * TC: O(n)
 * SC: O(n)
*/
/**
 * @author : SahilK-027
 * @brief : map
 */


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        for(auto i: mp){
            if(i.second == 1){
                return i.first;
            }
        }
        return -1;
    }
};