/*
Runtime: 3 ms
Memory Usage: 6.9 MB
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int st_row = 0;
        int st_col = 0;   
        int en_row = row - 1;
        int en_col = col - 1;
        int i = -1, j = -1;
        while (true)
        {
            //Printing Strating row
            if (st_row <= en_row)
            {
                i = st_row;
                j = st_col;
                while (j <= en_col)
                {
                    ans.push_back(matrix[i][j]);
                    j++;
                }
                st_row++;
            }
            //Printing ending col 
            if (en_col >= st_col)
            {
                i = st_row;
                j = en_col;
                while (i <= en_row)
                {
                    ans.push_back(matrix[i][j]);
                    i++;
                }
                en_col--;
            }
            //Printing ending_row
            if (en_row >= st_row)
            {
                i = en_row;
                j = en_col;
                while (j >= st_col)
                {
                    ans.push_back(matrix[i][j]);
                    j--;
                }
                en_row--;
            }
            
            //Printing Starting col
            if (st_col <= en_col)
            {
                i = en_row;
                j = st_col;
                while (i >= st_row)
                {
                    ans.push_back(matrix[i][j]);
                    i--;
                }
                st_col++;
            }
            else
                break;
        }
        return ans;
    }
};
