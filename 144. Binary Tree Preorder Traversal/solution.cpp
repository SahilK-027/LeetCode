/*
0 ms
8.6 MB

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
    void solve(TreeNode* root,vector<int>& ans){
        // Base case
        if(root == NULL){
            return;
        }
        // Preorder Traversal = ROOT - LEFT - RIGHT
        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};