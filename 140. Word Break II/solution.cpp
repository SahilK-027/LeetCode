/*
0 ms
7.8 MB
*/

/**
 * @author : Sahilk-027
 * @brief : Using backtracking + Hashmap
*/

class Solution {
private:
    void solve(int index,string s, unordered_map<string, int>dict, vector<string>& ans, string& temp){
        // Base case
        if(index == s.length()){
            // We are adding pace but last word should not have space so we'll pop back space
            temp.pop_back();
            ans.push_back(temp);
            return ;
        }
        string substring = "";
        for(int i = index ; i < s.length() ;i++){
            substring += s[i];
            // Check if substring is present in set or not
            if(dict[substring] != 0){
                string oldTemp = temp;
                temp += substring;
                temp += " ";
                solve(i + 1, s, dict, ans, temp);
                // Backtrack
                temp = oldTemp;
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // We want unique elements in wordDict
        // so we will use hashmap to store wordDict element and their count
        unordered_map<string, int>dict;
        // Copy wordDict to dict
        for(auto i: wordDict){
            dict[i]++;
        }
        // Helper function
        vector<string> ans;
        // To build ans
        string temp;
        int index = 0;
        solve(index,s, dict, ans, temp);
        // Return 
        return ans;
    }
};