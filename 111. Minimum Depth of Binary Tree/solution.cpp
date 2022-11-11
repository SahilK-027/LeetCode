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
    int minDepth(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        if(root == NULL){
            return 0;
        }
        // If tree has no left child return height of right sub tree +1
        if(root->left == NULL)
        {
            return minDepth(root->right)+1;
        }
        // If tree has no right child return height of left sub tree +1
        if(root->right == NULL)
        {
            return minDepth(root->left)+1;
        }
        // Recursion will give you minimum height of left subtree
        int left_min = minDepth(root->left);
        
        // Recursion will give you minimum height of right subtree
        int right_min = minDepth(root->right);
        
        // find minimum from right_min and left_min
        int min_depth = min(left_min, right_min);
        
        // Add height of root to min height
        int ans = min_depth+1;
        return ans;
    }
};