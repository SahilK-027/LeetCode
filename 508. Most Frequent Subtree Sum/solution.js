/*
85 ms
47.1 MB
*/
/**
 * TC: O(n)
 * SC: O(height)
*/
/**
 * @author : SahilK-027
 * @brief : DFS
 */ 

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */

function solve(root, mp){
    if(!root){
        return 0;
    }

    let left_ans = solve(root.left, mp);
    let right_ans = solve(root.right, mp);

    let sum = root.val + left_ans+ right_ans;

    mp[sum] = (mp[sum] || 0) + 1;
    return sum;
}
var findFrequentTreeSum = function(root) {
    // Declaring map
    let mp = {};
    let max = -Infinity;
    let ans = [];

    // Recursive call
    solve(root, mp);

    // Finding Most Frequent from map
    for(let key in mp){
        if(mp[key] > max){
            max = mp[key];
        }
    }

    // Storing Most Frequent elem in ans
    for(let key in mp){
        if(mp[key] === max){
            ans.push(parseInt(key));
        }
    }
    return ans;
};