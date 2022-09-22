/*
Runtime: 5 ms
Memory Usage: 7.2 MB
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        //Finding transpose of matrix
        int n = matrix.size();
        for(int i = 0 ;i<n;i++)
        {
            for(int j = i ;j<n ;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //Swapping columns using two pointer approach
        int st_row = 0;
        while(st_row<n)
        {
            int s = 0;
            int e = n-1;
            while(s<e)
            {
                swap(matrix[st_row][s],matrix[st_row][e]);
                s++;
                e--;
            }
            st_row++;
        } 
    }
};
