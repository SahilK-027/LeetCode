/*
1461 ms
138 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief :  Brute force + Sort + Stack
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // EX. [[10,16],[2,8],[1,6],[7,12]]
        // Sort points
        sort(points.begin(), points.end());
        // [[1,6],[2,8],[7,12],[10,16]]


        // Create a stack and push vectors onto it
        stack<vector<int>>st;
        for(auto i: points){
            st.push(i);
        }


        // Given 1 <= points.length so there is guarantee to have one answer
        int ans = 1;
        // Curr will be top of stack 
        // For given example currr = [10,16]
        vector<int> curr_top = st.top();
        st.pop();
        while(!st.empty()){
            // Next will be [7,12]
            vector<int> next_top = st.top();
            // if(curr_top[0] <= next_top[1]) means lower limit of curr is less than upper limit of next
            // Means these two balloons can be burst in one shot no need to change answer

            // if(curr_top[0] > next_top[1]) means these two ballons cannot be burst in one arrow so update answer and now your curr will be next
            if(curr_top[0] > next_top[1]){
                ans++;
                curr_top = next_top;
            } 
            st.pop();
        }
        return ans;
    }
};