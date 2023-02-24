/*
67 ms
46.9 MB
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
 * @return {number}
 */
function solve(root, tilt){
    if(!root){
        return 0;
    }
    let leftAns = solve(root.left, tilt);
    let rightAns = solve(root.right, tilt);

    tilt.val += Math.abs(leftAns - rightAns);

    return leftAns + rightAns + root.val;
}
var findTilt = function(root) {
    const tilt = { val: 0 };
    solve(root, tilt);
    return tilt.val;
};