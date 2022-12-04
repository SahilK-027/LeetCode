class Solution {
public:
    bool isCircularSentence(string s) {
        // If there is only one wrod ans will be true
        if(s.length() == 1) return true;
        int n = s.length();
        char first = s[0];
        char last = s[n-1];
        // if first and last character doesn't match then return false
        if(first != last) return false;
        // Two pointer approach
        int i = 1;
        int j = 2;
        while(j < n){
            if(s[j] == ' '){
                // if we found space take j on next char
                j++;
                // if next chracter (i.e first char of next word) does not matches with previous return false
                if(s[i] != s[j]) return false;
                // else take i on j and j++
                i = j;
                j++;
            }
            else{
                // no space simple i++ and j++ till we reach end of word for space charcter 
                i++;
                j++;
            }
        }
        return true;
    }
};