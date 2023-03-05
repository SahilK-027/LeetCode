/*
95 ms
49.4 MB
*/

/**
 * TC: O(n)
 * SC: O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Iterative
*/

/**
 * @param {number[]} nums
 * @param {number} minK
 * @param {number} maxK
 * @return {number}
 */
var countSubarrays = function(nums, minK, maxK) {
    let ans = 0 ;
    let startOfWindow = 0 ;
    let curr_Min_Pos = -1 ;
    let curr_Max_Pos = -1
    let foundMin = false
    let foundMax = false
    
    for(let i = 0; i < nums.length; i++) {
        const curr = nums[i] ;
        if(curr === minK) {
            foundMin = true ;
            curr_Min_Pos = i ;
        }
        
        if(curr === maxK) {
            foundMax = true ;
            curr_Max_Pos = i ;
        }
        
        if(curr < minK || curr > maxK) {
            foundMin = false ;
            foundMax= false ;
            startOfWindow = i+1 ;
        }
        
        if(foundMin && foundMax) {
            ans += (Math.min(curr_Min_Pos, curr_Max_Pos) - startOfWindow + 1) ;
        }
    }
    
    return ans ;
};