/*
0 ms
6.2 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

class Solution {
private:
    int solve(string &s, int i, int* dp){
        if(i >= s.size()){
            return 1;
        }
        // IF dp[i] is already calculated then retun it no need to calculate again
        if(dp[i] != -1){
            return dp[i];
        }
        // else calculate answer
        int ans = 0;
        int path_1 = s[i] - '0'; // taking out 1 from "11106" to solve
        int path_2 =0;
        if( i < s.length() - 1){
            path_2 = path_1 *10 + s[i+1] - '0' ;//taking out 11 from "11106 " to solve
        }
        if(path_1 > 0){
            ans = ans + solve(s, i+1,dp);
        }
        if(path_1 != 0 && path_2 > 0 && path_2 <= 26){
            ans = ans + solve(s,i+2,dp);
        }
        // store answer in dp
        dp[i] = ans;
        return ans;    
    }
public:
    int numDecodings(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        // TO STORE INTERMIDIATE ANSWERS WE WILL CREATE AN DP
        int dp[101];
        memset(dp,-1,sizeof(dp));
        
        int ans = solve(s,0, dp);
        return ans;
    }
};
