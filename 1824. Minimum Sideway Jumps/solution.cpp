/*
Runtime : 308 ms
Memory : 258.2 MB

TC: O(N * N)
SC: O(N * N)
*/

/**
 * @author : Sahilk-027
 * @brief : Dynamic Programming
*/

class Solution {
private:
    int solveMemoization(vector<int>& obs, int n, int currLane, int currPos, vector<vector<int>>& dp){
        // Base case
        if(currPos == n) return 0;

        if(dp[currLane][currPos] != -1) return dp[currLane][currPos];

        // check next position in same lane
        if(obs[currPos + 1] != currLane) return solveMemoization(obs, n, currLane, currPos+1, dp);

        // Side ways jump
        else{
            int minJumps =INT_MAX;
            for(int i = 1; i <= 3; i++){
                // Jump in lane only if it is not curr lane
                if(currLane != i){
                    // Jump in lane only it does not has obstacle
                    if(obs[currPos] != i){
                        minJumps = min(minJumps, 1+ solveMemoization(obs, n, i, currPos, dp));
                    }
                }
            }
            return dp[currLane][currPos] =  minJumps;
        }
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        vector<vector<int>> dp(3+1, vector<int>(obstacles.size()+1, -1));
        return solveMemoization(obstacles,n,  2, 0, dp);
    }
};