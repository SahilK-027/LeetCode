/*
75 ms
42.2 MB

TC: O(n)
SC: O(height)

@author: SahilK-027
@brief: Recursion

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
 * @return {TreeNode}
 */
var invertTree = function(root) {
    // Base case
    if(!root){
        return null;
    }
    // Recursion will invert left subtree and right subtree
    let left = invertTree(root.left);
    let right = invertTree(root.right);
    // Our job is to invert root
    root.left = right;
    root.right = left;
    return root;
};
