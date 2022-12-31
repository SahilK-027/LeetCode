/*
10 ms
13.5 MB

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
    void solve(TreeNode* root,int& sum){
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return;
        }
        if(root->left && (root->left->left == NULL && root->left->right == NULL)){
            sum += root->left->val;
        }
        solve(root->left,sum);
        solve(root->right,sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        solve(root,sum);
        return sum;
    }
};