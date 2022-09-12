/*
Runtime: 3 ms
Memory Usage: 5.7 MB
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
        if(ans >= -2147483648 && ans <= 2147483647){
            return ans; 
        }
        return 0;
    }
};
