/*
307 ms
56.6 MB
*/
/**
 * TC: O(N log N)
 * SC: O(1)
*/
/**
 * @author : SahilK-027
 * @brief : Binary Search
 */

/*
TOFIND: lower <= nums[i] + nums[j] <= upper

LOGIC: 
let nums[i] = KNOWN
and nums[j] = UNKNOWN 
so, we have to found nums[j] in array such that 
lower - nums[i] <= nums[j] <= upper - nums[i] 
*/

// To find How many numbers can fit in range of array that will give us lower - nums[i] <= nums[j] <= upper - nums[i] 
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int l = lower - nums[i];
            int u = upper - nums[i];
            // As we have to find non repeated answers we will only check from next index i+1 
            // as prev indexes had been traversed already
            auto ans_lb = lower_bound(nums.begin() + (i+1), nums.end(), l);
            auto ans_ub = upper_bound(nums.begin() + (i+1), nums.end(), u);
            
            ans += ans_ub - ans_lb; 
        }
        return ans;
    }
};