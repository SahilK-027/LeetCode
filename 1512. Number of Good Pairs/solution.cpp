/*
0 ms
7.3 MB
*/

/**
 * TC: O(n)
 * SC: O(n)
*/

/**
 * @author : SahilK-027
 * @brief : Hashing
*/


#define combinetrics(i)  (i * (i - 1)) / 2; 
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // Map to store number and it's count
        unordered_map<int, int>mp;
        for(auto i: nums){
            mp[i]++;
        }
        // Final answer
        int ans = 0;
        for(auto i: mp){
            if(i.second != 1){
                // This function will return nc2
                ans += combinetrics(i.second);
            }
        }
        return ans;
    }
};