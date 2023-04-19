/*
Runtime : 76 ms
Memory : 52.3 MB

TC: O(N)
SC: O(1)
*/

/**
 * @author : Sahilk-027
 * @brief : Iteration 
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var minimizeArrayValue = function(nums) {
    let ans = nums[0];
    let curr_total = nums[0];
    for(let i = 1; i < nums.length; i++){
        curr_total += nums[i];
        let curr_ans = Math.ceil(curr_total / (i +1));
        ans = Math.max(ans, curr_ans);
    }
    return ans;
};