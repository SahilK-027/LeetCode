/*
8 ms
6.3 MB
*/

/**
 * TC: O(n)
 * SC: O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Math
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            if( n / pow(5, i) > 0){
                ans += n / pow(5, i);
            }
            else{
                break;
            }
        }
        return ans;
    }
};