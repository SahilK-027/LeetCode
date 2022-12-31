/*
0 ms
6 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution + Tabularization
*/ 

class Solution {
public:
    int solve(int n){
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        if(n >= 1){
            dp[1] = 1;
        }
        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int fib(int n) {
        return solve(n);
    }
};
