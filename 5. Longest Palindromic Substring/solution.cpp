/*
52 ms
19.3 MB
*/

/**
 * TC: O(n^2)
 * SC: O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Iterative
*/

class Solution {
private:
// Considering the current character as middle of possible palindrome expand out two pointers
    void  findpal(string& s, int& l, int& r, string& ans, int& length){
        while( l >= 0 && r < s.length() && s[l] == s[r] )
        {
            if(r-l+1 > length){
                ans = s.substr(l, r-l+1);
                length =  r-l+1;
            }
            l--;
            r++;
        }
    }
public:
    string longestPalindrome(string s) {
        // Fast i/o
        cin.tie(0);
        ios_base::sync_with_stdio(0);

        string ans = "";
        int length = 0;
        // O(n)
        for(int i = 0 ; i < s.length(); i++){
            // Odd length palindrome
            int l = i;
            int r = i;
            findpal(s,l,r,ans,length);
            // Even length palindrome
            l = i;
            r = i+1;
            findpal(s,l,r,ans,length);
        }
        return ans;
    }
};