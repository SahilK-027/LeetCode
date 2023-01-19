/*
70 ms
31.7 MB
*/

/*
TC: O(n)
SC: O(n)
*/

/**
 * @author : SahilK-027
 * @brief :  Prfix sum and map
*/

// Prefix sum and mapping
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // map to store prfix and its count
        unordered_map<int, int>mp;
        mp[0] = 1;
        int cnt = 0;
        int currSum = 0;
        // Traverse array
        for(auto i: nums){
            // calculate curr sum
            currSum += i;
            // calculate prefixdiff
            int diff = (currSum % k + k) % k;
            // if prefixdiff exists then add no of prefixes to ans
            if(mp[diff]){
                cnt += mp[diff];
            } 
            mp[diff]++;
        }
        return cnt + mp[k];
    }
};