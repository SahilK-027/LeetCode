/*
141 ms
46 MB
*/

/**
 * TC: O(log n)
 * SC: O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Binary search
*/

/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */
var minEatingSpeed = function(piles, h) {
    let sum = 0;
    piles.forEach((ele, idx)=>{
        sum += ele;
    });
    let s = 0;
    let e = sum;
    let m = parseInt(s + (e-s)/2);
    let ans = 0;
    while(s <= e){
        let curr_time = 0;
        piles.forEach((ele, idx)=>
        {
            curr_time += Math.ceil(ele / m);
        });
        if(curr_time <= h){
            ans = m;
            e = m-1;
        }
        else{
            s = m+1;
        }
        m = parseInt(s + (e-s)/2);
    }
    return ans;
};