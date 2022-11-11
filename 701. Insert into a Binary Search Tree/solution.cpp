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
        TreeNode* solve(TreeNode*& root, int val){
        if(root == NULL){
            TreeNode* node = new TreeNode(val);
            root = node;
            return root;
        }
        // Data greater than root
        if (val > root->val)
        {   
            root->right = insertIntoBST(root->right, val);
        }
        else
        {
            // Data smaller than root
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        return solve(root,val);
   }
};