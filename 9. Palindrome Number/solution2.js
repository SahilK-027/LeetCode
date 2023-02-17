/*
200 ms
50.4 MB

TC: O(n)
sc: O(1)

@author: SahilK-027
@brief: Iterative
*/


/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x < 0) return false;
    let reverse_x = 0;
    let num = x;
    while(num){
        let last_digit = num % 10;
        reverse_x = reverse_x * 10  + last_digit;
        num = parseInt(num / 10);
    }
    return (reverse_x === x);
};
