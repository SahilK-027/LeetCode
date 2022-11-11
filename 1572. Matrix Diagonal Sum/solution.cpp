class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row,col;
        row=col= mat.size();
        int sum = 0;
        {
            for(int i = 0 ; i<row ; i++){
                for(int j = 0 ; j<col ; j++){
                    if(i==j || (i+j == col-1)){
                        sum = sum + mat[i][j]; 
                    }
                }
            }
        }
        return sum;
    }
};