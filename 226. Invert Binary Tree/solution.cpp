/*
4 ms
9.8 MB

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
private:
    void solve(TreeNode*& root){
        if(root == NULL){
            return;
        }
        TreeNode* temp = root->left;
        root -> left = root->right;
        root -> right = temp;
        solve(root->right);
        solve(root->left);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};