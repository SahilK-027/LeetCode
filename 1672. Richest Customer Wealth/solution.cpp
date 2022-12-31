/*
4 ms
7.9 MB

TC : O(N^2)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int row = accounts.size();
        int col = accounts[0].size();
        int maximum  = INT_MIN;
        for(int i = 0;i<row;i++){
             int total = 0;
            for(int j = 0; j<col ; j++){
                total = total + accounts[i][j];
            }
            maximum = max(total , maximum);
        }
        return maximum;
    }
};