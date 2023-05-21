/*
39 ms
15.1 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Two Pointer
*/

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int len = s.length();
        int m = (len)/2;
        int r = 0, l = 0;
        // odd length
        if(len & 1){
            l = m - 1;
            r = m + 1;
        }
        else{
            l = m - 1;
            r = m;
        }
        while(l >= 0 && r < len){
            if(s[l] != s[r]){
                if(int(s[l]) < int(s[r])){
                    s[r] = s[l];
                }
                else{
                    s[l] = s[r];
                }
            }
            r++;
            l--;
        }
        return s;
    }
};