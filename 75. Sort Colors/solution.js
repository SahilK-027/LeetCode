/*
46 ms
42.4 MB

TC: O(N)
SC: O(1)

@author: SahilK-027
@breif: Three pointer
*/
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(arr) {
    let zero_pointer = 0;
    let one_pointer = 0;
    let two_pointer = arr.length - 1;
    while(one_pointer <= two_pointer){
        if(arr[one_pointer] == 0){
            let temp = arr[one_pointer];
            arr[one_pointer] =  arr[zero_pointer];
            arr[zero_pointer] = temp;
            one_pointer++;
            zero_pointer++;
        }
        else if( arr[one_pointer] == 2 ){
            let temp = arr[one_pointer];
            arr[one_pointer] =  arr[two_pointer];
            arr[two_pointer] = temp;
            two_pointer--;
        }
        else{
            one_pointer++;
        }
    }
};
