/*
Runtime : 175 ms
Memory : 107.6 MB

TC: O(N)
SC: O(1)
*/

/**
 * @author : Sahilk-027
 * @brief : iterative
 */

#define ll long long
class Solution {
public:
    ll zeroFilledSubarray(vector<int>& nums) {
        ll ans = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) 
        {
            if (nums[i] != 0) j = i + 1;
            ans += i - j + 1;
        }
        return ans;
    }
};