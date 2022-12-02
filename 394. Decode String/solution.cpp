///0ms solution
class Solution {
private:
    /// Function for checking if encountered character is a digit or not
    bool isDigit(char ch){
        return (int(ch) >= 48 && int(ch) <= 57);
    }
    int stringToint(string s){
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            int element = s[i] - '0';
            ans = ans * 10 + element;
        }
        return ans;
    }
public:
    string decodeString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        stack<char> st;
        string ans;
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] != ']')
            {
                st.push(s[i]);
            }
            else{
                /// We have found ]
                string temp = "";
                string digit = "";
                /// Until we dont get [ we will pop characters from stack and then push to temp strig
                while(!st.empty() && st.top() != '['){
                    temp.push_back(st.top());
                    st.pop();
                }
                /// While poping from stack we get reverse order so again making it original
                reverse(temp.begin(), temp.end());
                /// Pop out the [
                st.pop();
                /// Popping out the digit from stack
                while(!st.empty() && isDigit(st.top())){
                    digit.push_back(st.top());
                    st.pop();
                }
                /// While poping from stack we get reverse order so again making it original
                reverse(digit.begin(), digit.end());
                /// Converting dgit string to integer
                int dig = stringToint(digit);
                while(dig--){
                    for(auto i: temp)
                        st.push(i);
                }
            } 
        } 
        /// Extracting answer from stack
        while(!st.empty()){
            char top = st.top();
            st.pop();
            ans.push_back(top);
        }
        reverse(ans.begin(), ans.end());
        return  ans;
    }
};