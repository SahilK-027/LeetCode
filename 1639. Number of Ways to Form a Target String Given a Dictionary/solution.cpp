/*
Runtime : 2351 ms
Memory : 52 MB

TC: O(N * M)
SC: o(N * N)
*/

/**
 * @author : Sahilk-027
 * @brief : Dynamic Programming
*/

#define M 1000000007
class Solution {
    int getWords(vector<string>&words,string &target,int i,int j, vector<vector<int>>&dp){
        if(j == target.size())return 1;
        if(i== words[0].size() || words[0].size() - i < target.size() - j)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        long count = 0;
        for(int idx = 0; idx < words.size(); idx++){
            if(words[idx][i] == target[j]){
                count += getWords(words, target, i + 1, j + 1, dp) % M;
            }
        }
        count += getWords(words, target, i + 1, j, dp) % M;
        return dp[i][j] = count % M;
    }
public:
    int numWays(vector<string>& words, string target) {
        vector<vector<int>>dp(words[0].size(), vector<int>(target.size(), -1));
        return getWords(words, target, 0, 0, dp);
    }
};