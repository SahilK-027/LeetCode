/*
3 ms
7.9 MB
*/

/**
 * TC: O(n)
 * SC: O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Dynamic Programming
*/

class Solution {
public:
    vector<int> countBits(int n) {
        // Build dp
        vector<int> dp(n+1, 0);
        // Initial round will be 1 
        // We will be changing round at [1,2,4,8,16,32,64...]
        int curr_round = 1;
        for(int i = 1 ; i <= n ; i++){
            if(curr_round * 2 == i){
                curr_round = i;
            }
            dp[i] = dp[i - curr_round] + 1;
        }
        return dp;
    }
};