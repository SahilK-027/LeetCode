/*
14 ms
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
    int solve(TreeNode* root, int mini, int maxi){
        // Root is empty
        if(root == NULL){
            return maxi - mini;
        }
        // Update mini
        mini = min(root->val, mini);
        // Update maxi
        maxi = max(root->val, maxi);

        return max(solve(root->left, mini, maxi), solve(root->right, mini, maxi));
        
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int min = INT_MAX;
        int max = 0;
        return solve(root, min, max);
    }
};