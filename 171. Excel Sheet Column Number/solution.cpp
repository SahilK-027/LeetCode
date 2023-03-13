/*
7 ms
6.1 MB
*/

/**
 * TC: O(n)
 * SC: O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Iterative + ASCII
*/ 

class Solution {
public:
    int titleToNumber(string s) {
        int cnt = 0;
        int ans = 0;
        for(int i = s.length()-1; i >= 0 ; i--){
            ans += pow(26, cnt) * (s[i] - 'A' + 1);
            cnt++;
        }
        return ans;
    }
};