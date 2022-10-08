// Runtime: 56 ms
// Memory Usage: 16 MB

class Solution {
private:
    int largestRectangleArea(int *heights , int cols) {
        int n = cols-1;

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
        for(int i = 0 ; i < cols ; i++){
            while(st2.top() != -1 && heights[st2.top()] >= heights[i]){
               st2.pop();
            }
            p_smaller[i] = st2.top();
            st2.push(i);
        }
        
        // Finding the max area     -O(N) time
        int maxArea = 0;
        int area = 0;
        for(int i = 0 ; i < cols;i++){
            int length = heights[i] ;
            if(n_smaller[i] == -1)
            {
                n_smaller[i] = n+1;
            }
            int breadth = n_smaller[i] - p_smaller[i] - 1;
            area = length * breadth;
            if(area > maxArea)
            {
                maxArea = area;
            }
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int rows = matrix.size();
        int cols = matrix[0].size();
        int arr[rows][cols];
        for(int i= 0 ;i<rows;i++){
            for(int j = 0 ;j<cols ; j++){
                arr[i][j] = matrix[i][j] - '0';
            }
        }
        //Find area for row 1;
        int area = largestRectangleArea(arr[0],cols);
        
        //For remaining rows
        for(int i = 1 ; i<rows ;i++)
        {
            //Row update
            for(int j = 0 ; j<cols ;j++)
            {
                if(arr[i][j] != 0)
                {
                    arr[i][j] += arr[i-1][j];
                }
                else{
                    // else keep it zero
                    arr[i][j] = arr[i][j];
                }
            }
            // Now row has been updated send it to calculate area
            int newArea = largestRectangleArea(arr[i],cols);
            area = max(area, newArea);
        }
        return area;
    }
};
