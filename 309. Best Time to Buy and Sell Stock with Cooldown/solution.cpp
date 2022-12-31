/*
3 ms
12.1 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution + Memoization
*/

class Solution {
private:
    int solve(int i, bool buy, vector<int>& prices, vector<vector<int>>& dp){
        // base case
        if(i >= prices.size()){
            return 0;
        }

        // Step 3:  if ans already calculated return dp
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        // Buy
        if(buy == 1){
            // Step 3: Store ans in DP
            int buy_stock = -prices[i] + solve(i + 1, 0, prices, dp);
            int dont_buy_stock = 0 + solve(i + 1, 1, prices, dp);
            return dp[i][buy] = max(buy_stock, dont_buy_stock);
        }
        // Sell
        else{
            // Once you sell you cannot buy the immediate next so buy i + 2
            int sell_stock = prices[i] + solve(i + 2, 1, prices, dp);
            int not_sell_stock = 0 + solve(i + 1, 0, prices, dp);
            return dp[i][buy] = max(sell_stock, not_sell_stock);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        // We cannot sell first stock so initially buy will be true
        bool buy = true;

        // Step 1: Create DP
        vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        return solve(i, buy, prices, dp);
    }
};