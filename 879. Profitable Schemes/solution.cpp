/*
309 ms
53.9 MB

TC : O(N^3)
SC : O(N^3)
*/

/**
 * @author : SahilK-027
 * @brief : Dynamic Programming
*/

#define M 1000000007
class Solution {
public:
  int MOD = 1000000007;
  vector<vector<vector<int>>>dp;
  int solve(vector<int>&group, vector<int>&profit, int minProfit, int maxPeople, int index, 
  vector<vector<vector<int>>>& dp)
  {
      if (maxPeople < 0) return 0; 
      if (index == group.size())
      {

          if (minProfit > 0) return 0; 
          else return 1; 
      }
      
      if (minProfit < 0) minProfit = 0;
      if (dp[minProfit][maxPeople][index] != -1) return dp[minProfit][maxPeople][index];
      int include = solve(group, profit, minProfit - profit[index], maxPeople - group[index], index + 1, dp);
      int exclude = solve(group, profit, minProfit, maxPeople, index + 1, dp);
      return dp[minProfit][maxPeople][index] = (include % M + exclude % M) % M;
  }
  int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
  {
      int sz = group.size();
    vector<vector<vector<int>>>dp(minProfit + 1, vector<vector<int>>(n + 1, vector<int>(sz, -1)));
      int ans = solve(group, profit, minProfit, n, 0, dp);
      return ans;
  }
};
