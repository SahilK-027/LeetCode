class Solution {
private:
    void solve(int used_open, int used_close, int rem_open, int rem_close, vector<string>& ans, string temp){
        if(rem_close == 0 && rem_open == 0){
            ans.push_back(temp);
            return;
        }
        // Open Parentheses
        if(rem_open > 0){
            temp.push_back('(');
            solve(used_open+1,used_close,rem_open-1,rem_close,ans, temp);
            temp.pop_back();
        }
        
        // Close Parentheses
        // We can add close bracet only preceding to open bracket
        if(rem_close > 0 && used_open > used_close){
            temp.push_back(')');
            solve(used_open,used_close + 1,rem_open ,rem_close -1,ans, temp);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int used_open = 1;
        int used_close = 0;
        int rem_open = n-1;
        int rem_close = n;
        vector<string> ans;
        string temp = "(";
        solve(used_open,used_close, rem_open,rem_close ,ans, temp);
        return ans;
    }
};