/*
0 ms
6.3 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

class Solution {
private:
    int getlen(int n){
        int length = 0;
        while(n){
            n /= 10;
            length++;
        }
        return length;
    }
    int solve(int n){
        // Number of 1 in 0 are 0
        if(n <= 0) return 0;
        //  Number of 1 in  10 - 0 are 1
        if(n < 10) return 1;
        int length = getlen(n);
        int base = pow(10,length-1);
        int first_digit = n / base;
        int rem = n % base;
        int oneInBase = 0;
        if(first_digit == 1)
            oneInBase = n - base + 1;
        else
            oneInBase = base;
        return solve(rem) + first_digit * solve(base -1) + oneInBase;
    }
public:
    int countDigitOne(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        return solve(n);
    }
};