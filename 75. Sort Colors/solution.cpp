/*
Runtime: 0 ms
Memory: 8.2 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : nirupamarajeevan
 * @brief : 3 pointer approach
*/

/*
NOTE: We consider three variables 'l', 'm', 'h'. 
'l' -> low, 'm' -> medium, 'h' -> high. 'l' and 'm' are at 0th index of the vector initially and 'h' is at the last index of the vector. 
Since the elements in the vector are only confined to [0, 1, 2], we consider nums[l] indicates 0, nums[m] indicates 1 and nums[h] indicates 2. 
If nums[m] is 0 then we swap it with nums[l] and increment both 'l' and 'm', similarly if nums[m] is 2 then we swap it with nums[h] and decrement the value of h.
If the nums[m] is 1 then we just increment the value of m by 1. This goes on until m < h.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l, m, h;
        l = m = 0;
        h = nums.size() - 1;

        while(m <= h){
            if(nums[m] == 0){
                swap(nums[l], nums[m]);
                l++, m++;
            }
            else if(nums[m] == 1)
                m++;
            else{
                swap(nums[h], nums[m]);
                h--;
            }
        }
    }
};
