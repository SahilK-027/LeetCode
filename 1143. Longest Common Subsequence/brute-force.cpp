/**
 * TLE
 */


/**
 * @author : Sahilk-027
 * @brief : Recursion 
*/

/*
⚠️ This solution will require optimization else it will give TLE but its added here to understand how solution looked before optimization.
*/

class Solution {
private:
    int solve(string s1, string s2, int ans, int i = 0, int j = 0){
    if(i == s1.length() || j == s2.length()){
        return ans;
    }
    // Match case
    if(s1[i] == s2[j]){
        ans = 1 + solve(s1, s2,ans,i + 1, j+1);
    }

    // Not match
    else{
        ans = max(solve(s1, s2,ans,i, j+1), solve(s1, s2,ans,i + 1, j));
    }
    return ans;
}
public:
    int longestCommonSubsequence(string s1, string s2) {
        return solve(s1, s2, 0);
    }
};