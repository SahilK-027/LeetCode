/*
4 ms
9.7 MB
*/

/**
 * TC: O(n)
 * SC: O(n)
*/

/**
 * @author : SahilK-027
 * @brief : Dyanmic Proigramming
*/
class Solution {
private:
    int solveMemoization(int i, int n, vector<int>& days, vector<int>& costs, vector<int>& dp){
        // Base case
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        // Option 1: Buy 1 day pass
        int option1 = costs[0] + solveMemoization(i+1, n, days, costs, dp);
        // Option 2: Buy 7 day pass
        // Go seven day ahead
        int x;
        for(x = i; x < n && days[x] < days[i] + 7; x++);
        int option2 = costs[1] + solveMemoization(x, n, days, costs, dp);
        // Option 3: Buy 30 day pass
        for(x = i; x < n && days[x] < days[i] + 30; x++);
        int option3 = costs[2] + solveMemoization(x, n, days, costs, dp);

        return dp[i] =  min(option1, min(option2, option3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int i = 0;
        vector<int> dp(n+1, -1);
        return solveMemoization(i, n, days, costs, dp);
    }
};