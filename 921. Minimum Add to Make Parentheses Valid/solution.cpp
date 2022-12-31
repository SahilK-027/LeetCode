/*
0 ms
6.3 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Stack
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;
        for(int i = 0; i< s.length(); i++)
        {
            if(s[i]=='('){
                // For open brace push it on stack
                st.push(s[i]);
            } 
            else
            {
                // Else close brace has found
                if(!st.empty())
                {
                    // If stack is not empty means this close brace has an open brace previously
                    st.pop();
                }
                else{
                    // this close brace does not have an open brace previously
                    cnt++;
                }
            }
        }
        if(st.empty()){
            //string is balaced 
            return cnt;
        }
        else{
            return cnt + st.size();
        }
    }
};