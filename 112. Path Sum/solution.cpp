/*
24 ms
21.2 MB

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
    bool solve(TreeNode* root, int targetSum){
        // Base case
        if(root == NULL){
            return false;
        }
        //  Processing
        targetSum = targetSum - root->val;
        
        // If we reached the leaf node and our target sum becomes 0
        if(targetSum == 0 && root->left == NULL && root->right == NULL){
            return true;
        }
        
        // Recursive call
        bool leftAns = solve(root->left,targetSum);
        bool rightAns = solve(root->right,targetSum);
        
        // Answer either exists in left subtree or right subtree
        return (leftAns || rightAns);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        bool ans = solve(root, targetSum);
        return ans;
    }
};