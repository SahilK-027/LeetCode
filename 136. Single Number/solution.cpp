/*
29 ms
16.9 MB
*/
/**
 * TC: O(n)
 * SC: O(1)
*/
/**
 * @author : SahilK-027
 * @brief : XOR
 */

// EXOR of any number with itself is 0 so those numbers wich are duplicate will get cancel out ans
// the only single one will left
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};