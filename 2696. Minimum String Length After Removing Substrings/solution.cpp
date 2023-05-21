/*
4 ms
8.1 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Stack
*/

class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i = 1 ; i < s.length(); i++){
            st.push(s[i]);
            if(!st.empty() && st.top() == 'B'){
                st.pop();
                if(!st.empty() && st.top() == 'A'){
                    st.pop();
                }
                else{
                    st.push('B');
                }
            }
            if(!st.empty() && st.top() == 'D'){
                st.pop();
                if(!st.empty() && st.top() == 'C'){
                    st.pop();
                }
                else{
                    st.push('D');
                }
            }
        }
        return st.size();
    }
};