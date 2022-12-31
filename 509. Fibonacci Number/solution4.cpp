/*
0 ms
5.8 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Tabularization + space optimization
*/ 

class Solution {
public:
    int solve(int n){
        int prev2 = 0;
        int prev1 = 1;
        int curr;
        for(int i = 2 ; i <= n ; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    int fib(int n) {
        if(n < 2){
            return n;
        }
        return solve(n);
    }
};
