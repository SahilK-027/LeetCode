/*
71 ms
44.8 MB
*/
/**
 * TC: O(n)
 * SC: O(1)
*/
/**
 * @author : SahilK-027
 * @brief : XOR
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNonDuplicate = function(nums) {
    let ans = 0;
    nums.forEach((i, idx)=>{
        ans ^= i;
    })
    return ans;
};;