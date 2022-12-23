// Recursive solution
// TC : O(2^n)
class Solution {
private:
    int solve(int i, bool buy, vector<int>& prices){
        // base case
        if(i >= prices.size()){
            return 0;
        }
        // Buy
        if(buy == 1){
            int buy_stock = -prices[i] + solve(i + 1, 0, prices);
            int dont_buy_stock = 0 + solve(i + 1, 1, prices);
            return max(buy_stock, dont_buy_stock);
        }
        // Sell
        else{
            // Once you sell you cannot buy the immediate next so buy i + 2
            int sell_stock = prices[i] + solve(i + 2, 1, prices);
            int not_sell_stock = 0 + solve(i + 1, 0, prices);
            return max(sell_stock, not_sell_stock);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        // We cannot sell first stock so initially buy will be true
        bool buy = true;
        return solve(i, buy, prices);
    }
};