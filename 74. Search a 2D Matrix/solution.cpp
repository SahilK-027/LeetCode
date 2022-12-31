/*
7 ms
9.3 MB

TC : O(N * log N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Binary search
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int s = 0 ;
        int e = (row*col) -1 ;
        int m = s + (e-s)/2;
        while(s<=e)
        {
            if(matrix[m/col][m%col]==target)
                return true;
            else if (matrix[m/col][m%col]<target)
                s = m + 1;
            else
                e = m - 1;
            m = s + (e-s) /2;
        }
       return false; 
    }
};
