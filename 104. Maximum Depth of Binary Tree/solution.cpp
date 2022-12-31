/*
15 ms
18.9 MB

TC : O(N)
SC : O(height)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

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
class Solution {    
public:
    int maxDepth(TreeNode* root) {
        // Base Case
        if(root == NULL){
            // If no node in tree return 0 as height
            return 0;
        }
        // Recursion will find max depth of left subtree
        int max_depth_left = maxDepth(root->left);
        
        // Recursion will find max depth of right subtree
        int max_depth_right = maxDepth(root->right);
        
        // Our job is to add root to max height
        int max_depth = max(max_depth_left, max_depth_right);
        int ans = max_depth + 1; 
        
        return ans;
    }
};
