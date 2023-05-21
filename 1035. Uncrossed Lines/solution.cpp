/*
47 ms
13.6 MB

TC : O(N * N)
SC : O(N * N)
*/

/**
 * @author : SahilK-027
 * @brief : Dynamic Programming
*/

class Solution {
private:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& dp){
        if(i >= nums1.size()){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int include = 0;
        for(int x = j ; x < nums2.size(); x++){
            if(nums1[i] == nums2[x]){
                include = 1 + solve(nums1, nums2, i+1, x+1, dp);
                break;
            }
        }
        int exclude = solve(nums1, nums2, i+1, j, dp);

        return dp[i][j] =  max(include, exclude);
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = max(nums1.size(), nums2.size()) + 1;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(nums1, nums2, 0, 0, dp);
    }
};