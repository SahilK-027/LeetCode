/*
86 ms
49.1 MB
*/

/**
 * TC: O(2^n)
 * SC: O(N)
 */

/**
 * @author : SahilK-027
 * @brief :  Recursion
*/

class Solution {
private:
   // Function to check palindrome
    bool isPal(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void solve(int index, string& s, vector<string>& temp, vector<vector<string> >& ans) {
        if(index == s.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < s.size(); i++) {
            if(isPal(s, index, i)) {
                temp.push_back(s.substr(index, i - index + 1));
                solve(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int curr = 0;
        solve(curr, s, temp, ans);
        return ans;
    }
};