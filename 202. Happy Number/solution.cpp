class Solution {
    bool solve(int& n, unordered_map<int, int>& mp){
        // If number gets reduced to 1 return true
        if(n == 1){
            return true;
        }
        // FOR 2 - 6 ans is false
        if(n <= 6){
            return false;
        }
        // If current number is already solved return flase
        if(mp[n] > 1){
            return false;
        }
        // Find next number
        int num2 = 0;
        while(n){
            int l_digit = n % 10;
            int l_square = l_digit * l_digit;
            num2 = num2 + l_square;
            n /= 10;
        }
        // Mark that this number has occured one times
        mp[num2]++;
        // Next call
        return solve(num2, mp);
    }
public:
    bool isHappy(int n) {
        unordered_map<int, int>mp;
        return solve(n,mp);
    }
};