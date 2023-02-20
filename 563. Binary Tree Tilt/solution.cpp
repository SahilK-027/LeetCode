/*
14 ms
23.7 MB
*/
/**
 * TC: O(n)
 * SC: O(height)
*/
/**
 * @author : SahilK-027
 * @brief : DFS
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
    int solve(TreeNode* root, int &tilt){
        if(!root){
            return 0;
        }
        int leftsum = solve(root->left, tilt);
        int rightsum = solve(root->right, tilt);
        int nodesum = leftsum + rightsum + root->val;
        int tiltAns = abs(leftsum - rightsum);
        tilt += tiltAns;
        return nodesum;
    }
public:
    int findTilt(TreeNode* root) {
        int tilt = 0;
        solve(root, tilt);
        return tilt;
    }
};