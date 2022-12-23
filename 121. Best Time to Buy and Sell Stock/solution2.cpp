/*
208 ms
97.5 MB
*/

/**
 * @author : SahilK-027
 * @brief : DP
*/

/*
Approach:
arr         = 7   1   5   3   6   4
next_max    = 0   6   6   6   0   0
diff        = -7  5   1   3   -6  -4

Ans = max(-7, 5, 1, 3, -6, -4) = 5
*/
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        // Fast i/o
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = arr.size();

        // Traverse the array from back and then store max from back
        int curr_max = INT_MIN;
        vector<int> next_max(n);

        // Build next max array DP
        for(int i = n-1 ; i >= 0 ; i--){
            if(arr[i] > curr_max){
                curr_max = arr[i];
                next_max[i] = 0;
            }
            else{
                next_max[i] = curr_max;
            }
        }

        int ans = INT_MIN; 
        int profit = 0;
        
        // Find max diff
        for(int i = 0 ; i < n; i++){
            profit = next_max[i] - arr[i];
            if(profit > ans){
                ans = profit;
            }
        }
        // If max profit is positive return 
        if(ans > 0){
            return ans;
        }
        // If max profit is 0 or negative return 0
        return 0;
    }
};
