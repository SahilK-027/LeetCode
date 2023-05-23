/*
19 ms
24.9 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Dynamic Programming
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
    int solve(TreeNode* root, unordered_map<TreeNode*,int>& dp){
        if(!root) return 0;
        if(dp.count(root)) return dp[root];
        
        int sum1 = root->val;
        
        if(root->left != NULL){
          sum1 +=  solve(root->left->left, dp);
          sum1 += solve(root->left->right, dp);
        }
        
        if(root->right != NULL){
            sum1 += solve(root->right->left, dp);
            sum1 += solve(root->right->right, dp);
        }
        int sum2 = solve(root->left, dp) + solve(root->right, dp);

        return dp[root] =  max(sum1, sum2);
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return solve(root, dp);
    }
};