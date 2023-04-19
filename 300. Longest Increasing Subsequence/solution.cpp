/*
Runtime : 4 ms
Memory : 10.5 MB

TC : O(N log N)
SC : O(N)
*/

/**
 * @author : Sahilk-027
 * @brief : DP with BS
*/

class Solution {
private:
    int DP_with_BS(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> ans;

        ans.push_back(nums[0]);

        for(int i = 1; i < n; i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                // Find index of just greater element
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }

        return ans.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        return DP_with_BS(nums);
    }
};