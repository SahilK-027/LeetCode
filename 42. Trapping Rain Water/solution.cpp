/*
Runtime: 17 ms
Memory Usage: 19.8 MB
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int r = n - 1;
        int l = 0;
        int l_max = height[l];
        int r_max = height[r];
        int water_content = 0;
        while(l < r){
            if(l_max <= r_max){
                l++;
                int trapped_water = l_max - height[l];
                if(trapped_water<0){
                    trapped_water = 0;
                }
                water_content += trapped_water;
                if(height[l]>l_max){
                    l_max = height[l];
                }
            }
            else{
                //l_max > r_max
                r--;
                int trapped_water = r_max - height[r];
                if(trapped_water<0){
                    trapped_water = 0;
                }
                water_content += trapped_water;
                if(height[r]>r_max){
                    r_max = height[r];
                }
            }
        }
        return water_content;
    }
};
