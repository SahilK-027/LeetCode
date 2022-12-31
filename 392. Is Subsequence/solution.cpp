/*
136 ms
276.8 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Two pointer approach
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while(j<t.length() && i<s.length()){
            while(s[i]!=t[j] && j<t.length()){
                j++;
            }
            if(s[i]==t[j] && i<s.length() && j<t.length()){
                i++;
                j++;
            }
        }
        if(i==s.length()) 
// i has been traversed completetly means its a subsequence
        {
            return true;
        }
        return false;
    }
};