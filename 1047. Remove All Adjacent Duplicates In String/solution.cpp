/*
35 ms
11.6 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Stack
*/

class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char> st;
        string answer;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty()||st.top()!=s[i]){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        while(!st.empty()){
            answer.push_back(st.top());
            st.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};