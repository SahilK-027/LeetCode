/*
168 ms
12.1 MB

TC : O(row * column)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Brute-Force
*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        for(int col = 0; col < m; col++){
            int prev =  -1;
            int curr =  0;
            for(int row = 1; row < n; row++){
                // Keep track of previous and current element 
                // If ASCII value of prev is greater than curr then column is unsorted
                // So increase answer count
                // And break for that particular column
                prev = int(strs[row-1][col]);
                curr = int(strs[row][col]);
                if(prev > curr){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};