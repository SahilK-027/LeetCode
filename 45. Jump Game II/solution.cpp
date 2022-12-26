/*
582 ms
18.2 MB

TC : O(n^2)
SC : O(n)
*/

/**
 * @author : SahilK-027
 * @brief : Recursion + DP
*/

class Solution {
private:
    long long solve(vector<int>& arr, int i, int n, long long ans,vector<int>& dp){
        // If reached last index 
        if(i >= n-1){
            return 0;
        } 
        // Find out what is max rechable index from given index
        int reachable = i + arr[i];
        // If answer is there in dp return ans
        if(dp[i] != -1 ){
            return dp[i];
        } 
        // Otherwise go to all the rechable states and findout min answer
        for(int j = i+1; j <= reachable ; j++){
            ans = min(1 + solve(arr, j, n, ans, dp), ans); 
        }
        // Store answer in DP
        dp[i] = ans;
        return ans;
    }
public:
    int jump(vector<int>& arr) {
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        int n = arr.size();
        long long ans = INT_MAX;
        vector<int>dp(n, -1);
        // Solve is going to return long long but we want to return int so divide by 1ll
        return solve(arr, 0, n, ans,dp) / 1ll;
    }
};