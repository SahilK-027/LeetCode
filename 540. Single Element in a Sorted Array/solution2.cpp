/*
25 ms
22.4 MB
*/
/**
 * TC: O(n)
 * SC: O(1)
*/
/**
 * @author : SahilK-027
 * @brief : XOR
 */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(auto i: nums){
            ans ^= i;
        }
        return ans;
    }
};