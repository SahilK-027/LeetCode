/*
70ms
42.2 MB

TC: O(log N)
SC: O(1)

@author: SahilK-027
@breif: Binary search

*/
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(arr, t) {
    let s = 0;
    let e = arr.length-1;
    let m = parseInt(s + (e-s) / 2);
    console.log(m);
    while(s <= e){
        if(arr[m] === t ){
            return m;
        }
        else if(arr[m] < t){
            s = m + 1;
        }
        else{
            e = m - 1;
        }
        m = parseInt(s + (e-s) / 2);
    }
    return s;
};
