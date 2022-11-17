// O(n^2) logic
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans;
        // For traversing all the characters of string 1
        for(int i = 0 ; i < s[0].size() ;i++){
            char ch = s[0][i];
            bool match = true;

            // Checking if the character exists in remaining strings 
            for(int j = 1; j<s.size();j++){
                if( s[j].size() < i || ch != s[j][i]){
                    // Not match
                    match = false;
                    break;
                }
            }
            if(!match){
                break;
            }
            else{
                ans += ch;
            }
        }
        return ans;
    }
};



// o(n) logic