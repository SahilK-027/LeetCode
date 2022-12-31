/*
55 ms
28.3 MB

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
    int solve(TreeNode* root, int&maxSum){
        if(root == NULL){
            return 0;
        }
        int leftAns = solve(root->left,maxSum);
        int rightAns = solve(root->right,maxSum);
        
        int maxi1 = max(max(leftAns,rightAns) + root->val, root->val);
        int maxi2 = max(maxi1,leftAns + rightAns + root->val);
        
        maxSum = max(maxi2, maxSum);
        
        return maxi1;
    }
public:
    int maxPathSum(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};