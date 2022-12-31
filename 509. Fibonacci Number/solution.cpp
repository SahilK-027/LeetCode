/*
16 ms
5.9 MB

TC : O(2^N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/


//Recursiom
class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int partial_ans = fib(n-1)+fib(n-2);
        return partial_ans;
    }
};