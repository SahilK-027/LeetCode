// Runtime: 371 ms
// Memory Usage: 81.3 MB

/*
// To get element and
Finding next smaller element's index (Using stack)
Step 1: 1. For every element find the next smaller element.
        2. If no next smaller element found assume it as -1.
        3. Construct an array which has index of next smaller number for each element in heights array. If next smaller is -1 store n+1th index in array.
        
Finding previous smaller element's index (using stack)
Step 2: 1. For every element find the previous smaller element.
        2. If no next smaller element found assume it as -1.
        3. Construct an array which has index of previous smaller number for each element in heights array. If previous smaller is -1 store -1 index in array.
        
Now max breadth for each length will be (next_smaller_index - prev_smaller_index - 1)
Return max of length * breadth.
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = heights.size()-1;

        // Finding next smaller element's index (Using stack)  -O(N) time
        vector<int> n_smaller(n+1);
        stack<int> st1;
        st1.push(-1);
        for(int i = n ; i >= 0 ; i--){
            while(st1.top() != -1 && heights[st1.top()] >= heights[i]){
               st1.pop();
            }
            n_smaller[i] = st1.top();
            st1.push(i);
        }
        
        // Finding previous smaller element's index (Using stack)   -O(N) time
        vector<int> p_smaller(n+1);
        stack<int> st2;
        st2.push(-1);
        for(int i = 0 ; i < heights.size() ; i++){
            while(st2.top() != -1 && heights[st2.top()] >= heights[i]){
               st2.pop();
            }
            p_smaller[i] = st2.top();
            st2.push(i);
        }
        
        // Finding the max area     -O(N) time
        int maxArea = 0;
        int area = 0;
        for(int i = 0 ; i < heights.size();i++){
            int length = heights[i];
            if(n_smaller[i] == -1)
            {
                n_smaller[i] = n+1;
            }
            int breadth = n_smaller[i]- p_smaller[i] - 1;
            area = length * breadth;
            if(area > maxArea)
            {
                maxArea = area;
            }
        }
        return maxArea;
    }
};
