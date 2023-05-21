/*
76 ms
43.6 MB

TC : O(1)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Math
*/

/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    if(num==0) return 0;
    else if(num%9==0) return 9;
    else return num%9;
};