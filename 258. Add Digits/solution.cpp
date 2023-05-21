/*
0 ms
5.9 MB

TC : O(N*N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

class Solution {
private:
    int solve(int n){
        if(n / 10 <= 0){
            return n;
        }
        int sum = 0;
        while(n > 0){
            sum += n % 10;
            n /= 10;
        }
        return solve(sum);
    }
public:
    int addDigits(int num) {
        return solve(num);
    }
};