/*
32 ms
21.9 MB

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
    TreeNode* solve(TreeNode* root, int t){
        if(root == NULL){
            return NULL;
        }
        // GO TO LEFT
        root -> left = solve(root->left,t);
        // GO TO RIGHT
        root ->right = solve(root->right,t);
        
        // IF FOUND LEAF AND VALUE MATCHES DELETE
        if(root->left == NULL && root->right == NULL && root->val ==t){
            return NULL;
        }
        
        return root;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        return solve(root, target);
    }
};