/*
3 ms
5.9 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

class Solution {
private:
    int solve(int n, int ans = 0){
        // If number becomes zero return ans
        if(n == 0) return ans;
        // Solve for even number
        if(!(n & 1)) return solve(n / 2, ans+1);
        // Solve for odd number
        else return solve(n-1, ans+1);
    }
public:
    int numberOfSteps(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        return solve(n);
    }
};