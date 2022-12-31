/*
18 ms
9.5 MB

TC : O(N^2)
SC : O(1)
*/

/**
 * @author : Sahilk-027
 * @brief : Sorting
*/

// Sort grid logic
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        // Fast I/O
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // Sorting all the dimentions so that max will be at last index
        for(int i = 0 ; i < grid.size();i++){
            sort(grid[i].begin(), grid[i].end());
        }
        // Trversing from last column
        int j = grid[0].size() - 1;
        int maxi_sum = 0;
        while(j >= 0){
            int maxi = INT_MIN;
            for(int i = 0 ; i < grid.size() ;i++){
                if(grid[i][j] > maxi){
                    maxi = grid[i][j];
                }
            }
            maxi_sum += maxi;
            j--;
        }
        return maxi_sum;
    }
};