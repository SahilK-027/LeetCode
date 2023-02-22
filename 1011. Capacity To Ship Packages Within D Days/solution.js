/*
84 ms
44.9 MB
*/
/**
 * TC: O(n)
 * SC: O(1)
*/
/**
 * @author : SahilK-027
 * @brief : Binary search
 */

/**
 * @param {number[]} weights
 * @param {number} days
 * @return {number}
 */
const isPossible = (mid, weights, days)=>{
    let curr_day_cnt = 1;
    let curr_weight_sum = 0;

    for(let i = 0 ; i < weights.length; i++){
        // If it is possible to allocate the weight on current day
        if(curr_weight_sum + weights[i] <= mid){
            curr_weight_sum += weights[i];
        }
        // It is not possible to allocate the weight on current day
        else{
            // Shift on next dat
            curr_day_cnt++;
            if(curr_day_cnt > days || weights[i] > mid){
                return false;
            }
            curr_weight_sum = weights[i];
        }
    }
    return true;
}
var shipWithinDays = function(weights, days) {
    let sum = 0;
    weights.forEach((ele, i)=>{
        sum += ele;
    })
    let s = 0;
    let e = sum;
    let ans = Infinity;
    while(s <= e){
        let mid = parseInt(s + (e - s )/ 2);
        if(isPossible(mid, weights, days)){
            ans = Math.min(ans, mid);
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
};