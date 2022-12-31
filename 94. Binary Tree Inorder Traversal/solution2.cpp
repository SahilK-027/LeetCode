/*
0 ms
10.4 MB

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
    vector<int> solve(TreeNode* root , vector<int> &ans){
        if(root == NULL){
            return ans;
        }
        /*Inorder-> left - root - ans*/
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
        return ans;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        return solve(root, ans);
    }
};
