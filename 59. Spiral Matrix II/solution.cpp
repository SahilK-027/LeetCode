/*
7 ms
6.7 MB

TC : O(N*N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Matrix traversal
*/
/*
    We create a 2D vector containing "n"
    elements each having the value "vector<int> (m, 0)".
    "vector<int> (m, 0)" means a vector having "m"
    elements each of value "0".
    Here these elements are vectors.
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > mat(n, vector<int>(n, 0));
        int start_row = 0;
        int start_col = 0;
        int end_row = n - 1;
        int end_col = n - 1;
        int count = 1;
        while (count <= n * n && start_row <= end_row && start_col<=end_col )
        {
            //Updating start row
            for (int i = start_row; i <= end_col ; i++)
            {
                mat[start_row][i] = count;
                count++;
            }
            start_row++;

            //Updating end col
            for (int i = start_row; i <= end_row ; i++)
            {
                mat[i][end_col] = count;
                count++;
            }
            end_col--;

            //Updating end row
            for (int i = end_col; i >= start_col; i--)
            {
                mat[end_row][i] = count;
                count++;
            }
            end_row--;

            //Updating end col
            for (int i = end_row; i >= start_row ; i--)
            {
                mat[i][start_col] = count;
                count++;
            }
            start_col++;
        }
        return mat;
    }
};
