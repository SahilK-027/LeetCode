/*
74 ms
43.3 MB
*/
/**
 * TC: O(n)
 * SC: O(n)
*/
/**
 * @author : SahilK-027
 * @brief : Hashing
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

var twoSum = function(nums, target) {
    // Create Hash Map
    let mp = new Map();
    // Length of array
    let n = nums.length;
    // Answer array
    const ans = [];
    // Traverse array
    for(let i = 0 ; i < n ; i++){
        // Find key
        let key = target - nums[i];
        // If key is found mp.get(key) wiull return non null value
        if(mp.get(key) != null){
            // Push answer
            ans.push(mp.get(key));
            ans.push(i);
            break;
        }
        // Store in map
        else{
            mp.set(nums[i],i);
        }
    }
    // Return ans
    return ans;
};
