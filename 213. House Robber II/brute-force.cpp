/*
TLE

TC : O(2^N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursion
*/

/*
⚠️ This solution will require optimization else it will give TLE but its added here to understand how solution looked before optimization.
*/

// Recursive solution
class Solution {
private:
    int solve(vector<int>& nums, int s, int e){
        // Base case
        if(s > e){
            return 0;
        }
        // Include current house
        int include = nums[s] + solve(nums, s + 2, e);
        // Exclude current house
        int exclude = 0 + solve(nums, s + 1, e);
        // Return whichever answer will be maximum
        return max(include, exclude);
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int s = 0;
        int e = nums.size()-1;
        // Ans 1 will be for house 1 to second last house as last house will be adjacent house to house 1 in circle
        int ans_1 = solve(nums, s, e-1);
        // Ans 2 will be for house 2 to the last house.
        int ans_2 = solve(nums, s+1, e);
        // Finally return maximum of answers
        return max(ans_1, ans_2);
    }
};