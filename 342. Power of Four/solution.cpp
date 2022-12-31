/*
0 ms
5.7 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

class Solution {
private:
    bool solve(int n,long long ans = 1){
        //Base case
        if(ans == n){
            return true;
        }
        //Recursion
        if(ans>n){
            return false;
        }
        return solve(n, 4 * ans);
    }
public:
    bool isPowerOfFour(int n) {
        return solve(n);
    }
};