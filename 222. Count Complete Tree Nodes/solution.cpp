/*
42 ms
30.8 MB

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
    int solve(TreeNode* root, int& ans){
        if(root == NULL){
            return 0;
        }
        ans = ans + 1;
        solve(root->left, ans);
        solve(root->right, ans);
        return ans;
    }
public:
    int countNodes(TreeNode* root) {
        int ans=0;
        return solve(root, ans);
    }
};