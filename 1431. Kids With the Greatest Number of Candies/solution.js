/*
Runtime : 71 ms
Memory : 42 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : Sahilk-027
 * @brief : Iteration
*/

/**
 * @param {number[]} candies
 * @param {number} extraCandies
 * @return {boolean[]}
 */
var kidsWithCandies = function(candies, extraCandies) {
    let maxi = candies[0];
    let ans = [];
    candies.forEach((ele, i)=>{
        if(ele > maxi){
            maxi = ele;
        }
    });
    candies.forEach((ele, i)=>{
        if(ele + extraCandies >= maxi){
           ans.push(true);
        }
        else{
            ans.push(false);
        }
    });
    return ans;
};
