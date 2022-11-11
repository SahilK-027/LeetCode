class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i = 0 ; i < s.length();i++){
            // At least one Element is there in stack
            if(st.size() && abs(int(st.top()-s[i])) == 32){
                // we know The difference between ASCII value of lower-case letter & upper-case letter is 32
                // If top of stack and element are same then pop from stack then pop element from stack
                st.pop();
            }
            // Stack is empty or top is not same as current element
            else{
                // Store element in stack
                st.push(s[i]);
            }
        }
        // Ans string
        string ans;
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans.push_back(ch);
        }
        // As stack gives reverse order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};