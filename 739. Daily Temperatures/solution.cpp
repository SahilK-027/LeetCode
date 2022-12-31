/*
314 ms
103.1 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Monotonically decreasing stack
            Stack will contain index of the elements
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        st.push(0);
        for(int i = 1 ; i < n ; i++){
            // If ith element is greater than stack top()
            if(arr[i] > arr[st.top()]){
                while(!st.empty() && arr[i] > arr[st.top()]){
                    ans[st.top()] = i - st.top();
                    st.pop();
                }
            }
            st.push(i);
        }
        return ans;
    }
};