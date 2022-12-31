/*
84 ms
33.5 MB

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
    void solve(TreeNode*& root, int &sum){
        // If root is NULL return 
        if(root == NULL){
            return;
        }
        // Go to extream right as this value will be the largest
        solve(root->right, sum);
        // Add root->data to sum
        sum = sum + root->val;
        // Replace root->data with sum
        root->val  =  sum;
        // Go to left
        solve(root->left,sum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        // Initialize sum with 0
        int sum = 0;
        // Call solve
        solve(root, sum);
        return root;
    }
};