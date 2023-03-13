/*
26 ms
23.2 MB
*/

/**
 * TC: O(n)
 * SC: O(n*n)
*/

/**
 * @author : SahilK-027
 * @brief : Dyanmic Proigramming
*/

class Solution {
private:
    int solve(vector<int>& slices, int s, int e, int n, vector<vector<int>>&dp){
        // Base case if slices_we_can_eat == 0 or s > e
        if(n == 0 || s > e)
            return 0;
        if(dp[s][n] != -1) return dp[s][n];
        int include = slices[s] + solve(slices, s +2,e, n-1, dp);
        int exclude = solve(slices, s+1, e , n, dp);
        return dp[s][n] =  max(include, exclude);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int size = slices.size();
        // Finding out the total number of slices
        int total_slices = size ;
        // As there are 3 friends each will get total/3 slices
        int slices_we_can_eat = total_slices / 3;
        vector<vector<int>>dp1(size+1, vector<int>(size+1, -1));
        vector<vector<int>>dp2(size+1, vector<int>(size+1, -1));

        int option1 = solve(slices, 0, size-2, slices_we_can_eat, dp1);
        int option2 = solve(slices, 1, size-1, slices_we_can_eat, dp2);

        return max(option1, option2);
    }
};