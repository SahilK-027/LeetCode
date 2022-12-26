/*
1690 ms
51.3 MB

TC : O(n^2)
SC : O(n)
*/

/**
 * @author : SahilK-027
 * @brief : Recursion + DP
*/

// Recursion + DP
class Solution {
private:
    bool solve(vector<int>& arr, int i, int n, vector<int>& dp){
        // If we reach last index return true
        if(i == n-1) return true;
        // Find all reachable plaves from current index
        int reachable = i+arr[i];
        // If already computed return 
        if(dp[i]  != -1 ) return dp[i];
        // Go to all rechable positions  
        for(int j = i+1; j <= reachable ; j++){
                bool ans = solve(arr, j, n, dp);
                dp[j] = ans;
                // If answer is true for a particular state return true
                if(ans == true){
                return ans;
            }      
        }
        // Still not true return false
        return false;
    }
public:
    bool canJump(vector<int>& arr) {
        // Size of aray is 1 so we are already at last index 
        if(arr.size()==1) return true;
        // If first element of array is 0 so we canot make any jump
        if(arr[0] == 0) return false;
        int n = arr.size();
        vector<int>dp(n, -1);
        return solve(arr, 0, n, dp);
    }
};