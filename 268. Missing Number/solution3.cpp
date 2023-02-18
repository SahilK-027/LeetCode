/*
Runtime: 26ms
Memory: 18 MB
TC : O(logN)
SC: O(1)
*/

/**
 * @author: nirupamarajeevan
 * 
 * @brief: Using Binary Search
 * 
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = 0;
        int end = n - 1;
    
        // checking the first element of the array
        if(nums[0] == 1)
            return 0;
        // checking the last element of the array
        if(nums[n-1] == n-1)
            return n;

        while(start <= end){
            int mid = start + (end - start) / 2;
            // main code 
            if(mid-1 >= 0 && nums[mid-1] + 1 != nums[mid])
                return nums[mid-1] + 1;
            if(mid == nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return 0;
    }
};
