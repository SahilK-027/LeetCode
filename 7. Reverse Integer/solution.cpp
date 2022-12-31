/*
3 ms
5.7 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Iterative solution
*/
class Solution {
public:
    int reverse(int x) {
        int l_digit;
        long long ans = 0;
        while(x!=0){
            l_digit = x%10;
            ans = ans * 10 + l_digit;
            x = x / 10;
        }
        // Checking bounds
        if(ans >= -2147483648 && ans <= 2147483647){
            return ans; 
        }
        return 0;
    }
};
