/*
Runtime: 24 ms
Memory Usage: 13.3 MB
1. Record all the positions where there is 0.
2. Update in matrix.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        pair<int,int> p;
        vector<pair<int,int>>v1;
        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j<cols ; j++ )
            {
                if(matrix[i][j]==0)
                {
                    p.first = i;
                    p.second = j;
                    v1.push_back(p);
                }
            }
        }
        for(int i = 0 ; i< v1.size();i++){
            for(int c = 0 ; c<cols ;c++){
                //Row update
                int r = v1[i].first;
                matrix[r][c] = 0;
            }
            for(int r = 0 ; r < rows ;r++){
                //Col update
                int c = v1[i].second;
                matrix[r][c] = 0;
            }
        }
    }
};
