/*
0 ms
6 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

class Solution {
private:
    int solve(int n , int k){
        if(n == 1) return 0;
        return (solve (n-1,k) + k ) % n;
    }
public:
    int findTheWinner(int n, int k) {
        return solve(n,k) + 1;
    }
};