/*
4 ms
9.3 MB

TC : O(N * N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Dynamic programming
*/


class Solution {
private:
    int solveRec(int i, int j, vector<vector<int>>& triangle){
        if(i == triangle.size()-1) return triangle[i][j];

        int down = triangle[i][j] +  solveRec(i+1, j, triangle);
        int down_right = triangle[i][j] +  solveRec(i+1, j+1, triangle);

        return  min(down, down_right);
    }
    int solveMem(int i, int j, vector<vector<int>>& triangle,vector<vector<int>>&dp){
        if(i == triangle.size() - 1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] +  solveMem(i+1, j, triangle, dp);
        int down_right = triangle[i][j] +  solveMem(i+1, j+1, triangle, dp);

        return dp[i][j] = min(down, down_right);
    }
    int solveTab(vector<vector<int>>& triangle){
        // Step 1: create DP
        vector<vector<int>>dp(triangle.size()+1, vector<int>(triangle.size()+1, -1));
        // Step 2: Fill the DP
        for(int j = 0; j < triangle.size(); j++){
            dp[triangle.size()-1][j] = triangle[triangle.size()-1][j];
        }
        // Step 3: According to recurrence fill the DP
        for(int i = triangle.size() - 2; i >= 0; i--){
            for(int j = triangle[i].size()- 1; j >= 0; j--){
                int down = triangle[i][j] +  dp[i+1][j];
                int down_right = triangle[i][j] +  dp[i+1][j+1];

                dp[i][j] = min(down, down_right);
            }
        }
        return dp[0][0];

    }
    int SO(vector<vector<int>>& triangle){
        vector<int>forward(triangle.size()+1, 10001);
        for(int j = 0; j < triangle.size(); j++){
            forward[j] = triangle[triangle.size()-1][j];
        }
        for(int i = triangle.size() - 2; i >= 0; i--){
            vector<int>curr(triangle.size()+1, 10001);
            for(int j = triangle[i].size()- 1; j >= 0; j--){
                int down = triangle[i][j] +  forward[j];
                int down_right = triangle[i][j] +  forward[j+1];

                curr[j] = min(down, down_right);
            }
            forward = curr;
        }
        return forward[0];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size()+1, vector<int>(triangle.size()+1, -1));
        return SO(triangle);
        return solveTab(triangle);
        return solveMem(0, 0, triangle, dp);
        return solveRec(0, 0, triangle);
    }
};