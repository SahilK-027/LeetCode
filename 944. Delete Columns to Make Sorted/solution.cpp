/*
168 ms
12.1 MB

TC : O(row * col)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Brute-Force
*/


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // Row longth
        int n = strs.size();
        // Column length
        int m = strs[0].size();
        int ans = 0;
        // Traverse each element 
        for(int col = 0; col < m; col++){
            int prev =  -1;
            int curr =  0;
            for(int row = 1; row < n; row++){
                // If ASCII of prev is greater than ASCII of current means not sorted
                prev = int(strs[row-1][col]);
                curr = int(strs[row][col]);
                if(prev > curr){
                    // Increment answer and break
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};