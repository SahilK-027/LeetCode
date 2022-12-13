/*
407 ms
52.5 mb
*/

/**
 * @author : Sahilk-027
 * @brief : Recursion
*/


/*
First we'll find out number of removals required to make given string valid 
Oce we'll get the cound we will recursivly delete thosew many strings and store valid anss
*/
class Solution {
private:
    bool isValid(string s){
        stack<char>st;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '(') st.push('(');
            else if(s[i] == ')'){
                // Close bracket
                if(!st.empty() && st.top() == '(') st.pop();
                else st.push(')');
            }
        }   
        return (st.size() == 0);
    }
    int removalCnt(string s){
        stack<char>st;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '(') st.push('(');
            else if(s[i] == ')'){
                // Close bracket
                if(!st.empty() && st.top() == '(') st.pop();
                else st.push(')');
            }
        }
        cout<<st.size();
        return (st.size());
    }
    
    void solve(string s, vector<string>& ans,  unordered_map<string, bool>& mp, int removalcnt){
        // Using map as dp if string is already processed return
        if(mp[s]){
            return;
        }
        else{
            mp[s] = true;
        }

        // Base case
        if(removalcnt == 0){
            // means we have removed all the invalid brackets 
            // So we need to check if our answer is valid or not
            if(isValid(s)){
                ans.push_back(s);
            }
            return;
        }

        // For every index we are going to remove and check validity
        for(int i = 0 ; i < s.length() ;i ++){
            // Fter removing a particular index element the thing which will left is leftsubstr and right substr
            string leftsubstr = s.substr(0, i);
            string rightsubstr = s.substr(i+1, s.length());

            string remainingStr = leftsubstr + rightsubstr;
            // Solve remaining string recursively
            solve(remainingStr, ans, mp, removalcnt-1);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        // Fast i/o
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // Get removal cnt
        int no_removals = removalCnt(s);
        vector<string> ans;
        unordered_map<string, bool>mp;
        solve(s, ans, mp, no_removals);
        return ans;
    }
};