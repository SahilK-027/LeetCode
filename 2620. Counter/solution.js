/*
Runtime : 55 ms
Memory : 41.5 MB

TC : O(1)
SC : O(1)
*/

/**
 * @author : Sahilk-027
 * @brief : Looping
*/

/**
 * @param {number} n
 * @return {Function} counter
 */

var createCounter = function(n) {
    let counter  = -1;
    return function() {
        counter++;
        return counter + n;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */