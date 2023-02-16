/*
11 ms
10.2 MB
*/
/**
 * TC: O(n)
 * SC: O(n)
*/
/**
 * @author : SahilK-027
 * @brief : Hashing
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>mp;
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