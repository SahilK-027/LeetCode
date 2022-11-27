class Solution {
private:
    int solve(string s, string t, int cnt, int i=0,int j = 0){
        // Initially count will be wqual to length of t 
        while(i < s.length() && j < t.length()){
            while(s[i] == t[j] && i < s.length() && j < t.length()){
                i++;
                j++;
            }
            while(s[i] != t[j] && i < s.length() && j < t.length()){
                i++;
            }
        }
        // We will return number of left charatcters in t
        return (cnt - j);
    }
public:
    int appendCharacters(string s, string t) {
        int cnt = t.length();
        return solve(s,t,cnt);
    }
};