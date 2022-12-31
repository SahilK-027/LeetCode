/*
Runtime: 15ms
Memory: 18 MB

TC : O(N)
SC: O(1)
*/

/**
 * @author: nirupamarajeevan
 * 
 * @brief: Using Bit Manipulation
 * 
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        // first we perform XOR operation with the numbers in the arrray
        // 0 XOR number returns the same number
        for(int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        // we perform XOR operation 0 to n
        // there would be two occurrences for every number in the array except the missing one
        for(int i = 0; i <= nums.size(); i++) {
            ans ^= i;
        }
        return ans;
    }
};

