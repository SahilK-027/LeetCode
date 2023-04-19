/*
Runtime : 1157 ms
Memory : 9 MB

TC : O(2 ^ N)
SC : O(N)
*/

/**
 * @author : Sahilk-027
 * @brief : Recursion
*/

class Solution {
private:
    void solve(vector<int>& nums, int& ans, int curr_sum, int target, int i, int n){
        if(i >= n){
            if(curr_sum == target){
                ans++;
            }
            return ;
        } 

        solve(nums, ans, curr_sum + nums[i], target, i+1, n);
        solve(nums, ans, curr_sum - nums[i], target, i+1, n);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        int curr_sum = 0;
        solve(nums, ans, curr_sum, target, 0, nums.size());
        return ans;
    }
};