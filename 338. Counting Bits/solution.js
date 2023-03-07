/*
86 ms
54.1MB
*/

/**
 * TC: O(n log n)
 * SC: O(1)
*/

/**
 * @author : SahilK-027
 * @brief : iterative
*/
/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function(n) {
    ans = [];
    for(let i = 0 ;i <= n; i++){
        let curr_num = i;
        let cnt =0;
        while(curr_num){
            let remender = curr_num % 2;
            if(remender == 1) cnt++;
            curr_num = parseInt(curr_num /2);
        }
        ans.push(cnt);
    }
    return ans;
};