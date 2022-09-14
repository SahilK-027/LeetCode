/*
Runtime: 107 ms
Memory Usage: 59 MB
*/

// Two pointer approach
class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0;
        int e = height.size()-1;
        int ans=0;
        int minimum;
        while(s<e){
            int dist = e-s;
            minimum = min(height[e],height[s]);
            if(minimum * dist > ans)
            {
                ans = minimum * dist;
            }
            if( height[s]<=height[e]){
                s++;
            }
            else if(height[s]>height[e]){
                e--;
            }
        }
        return ans;
    }
};
