/*
Runtime : 7 ms
Memory : 15.3 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : Sahilk-027
 * @brief : Stack
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> st;
        int st1 = 0;
        int st2 = 0;
        while(st1 != n){
            while(st1 != n && pushed[st1] != popped[st2]){
                st.push(pushed[st1]);
                st1++;
            } 
            while(st2 != n && st1 != n && pushed[st1] == popped[st2]){
                st.push(pushed[st1]);
                st.pop();
                st2++;
                st1++;
                while(st2 != n &&  !st.empty() && st.top() == popped[st2]){
                    st.pop();
                    st2++;
                }
            }
        }
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if( top == popped[st2]){
                st2++;
            }
            else{
                break;
            }
        }
        return st.size() == 0;
    }
};