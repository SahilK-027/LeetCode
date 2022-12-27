/*
TLE

TC : O(2^N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursion 
*/

// Reciursive solution
class Solution {
private:
    int solve(int n, vector<int>& cost){
        if(n < 0 ){
            return 0;
        }
        if(n == 0 || n == 1){
            return cost[n];
        }
        return cost[n] + min(solve(n-1, cost), solve(n-2, cost));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(solve(n-1, cost), solve(n-2, cost));
    }
};