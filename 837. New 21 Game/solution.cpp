/*
7 ms
9.3 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursion + Tabulation
*/

class Solution {
private:
    double solveMem(int n, int k, int maxPts, int curr_total, vector<double>& dp){
        if(curr_total >= k){
            if(curr_total <= n){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[curr_total] != -1) return dp[curr_total];
        double prob = 0;
        for(int i = 1 ; i <= maxPts; i++){
            prob += solveMem(n, k, maxPts, curr_total+i, dp);
        }
        return dp[curr_total] =  prob / maxPts;
    }
    double solveTab(int N, int K, int W, int curr_total){
        if (K == 0 || N >= K + W) return 1.0;
        vector<double> dp(N + 1);
        dp[0] = 1.0;
        double Wsum = 1.0, res = 0.0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = Wsum / W;
            if (i < K) Wsum += dp[i]; else res += dp[i];
            if (i - W >= 0) Wsum -= dp[i - W];
        }
        return res;
    }
public:
    double new21Game(int n, int k, int maxPts) {
        int curr_total = 0;
        return solveTab(n, k, maxPts, curr_total);
    }
};