/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Using morris traversal
// TC : O(N)
// SC : O(1)
class Solution {
private:
    TreeNode* findPredecessor(TreeNode* curr){
        TreeNode* predecessor = curr->left;
        while(predecessor->right != NULL){
            predecessor = predecessor->right;
        }
        return predecessor;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left != NULL){
                // left part exists
                TreeNode* predecessor = findPredecessor(curr);
                // Make link of predecessor with right part of tree
                predecessor->right = curr->right;    
                // Attach root->right to left
                curr->right = curr->left;
                // Make root left NULL
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};