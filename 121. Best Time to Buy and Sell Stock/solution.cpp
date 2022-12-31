/*
164 ms
93.4 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Two pointer approach
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;  // Pointing to price to buy
        int j = 1;  // Pointing to price to sell
        int max = INT_MIN;
        while(i<prices.size() && j<prices.size())
        {
            //Buy price is greater than sell price
            if(prices[i]>=prices[j]) 
            {
                //So go to next
                i=j;
                j++;
            }
            else{
                //Find current profit
                int current_profit=prices[j]-prices[i];
                if(current_profit>max){
                    max=current_profit;
                }
                j++;
            }
        }
        if(max>0){
            return max;
        }
        return 0;
    }
};