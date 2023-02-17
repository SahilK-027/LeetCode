/*
0 ms
9.6 MB
*/
/**
 * TC: O(n)
 * SC: O(n)
*/
/**
 * @author : SahilK-027
 * @brief : Inorder Traversal
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
    void inorder_traverse(TreeNode* root, vector<int>& inorder){
        if(!root){
            return;
        }
        inorder_traverse(root->left, inorder);
        inorder.emplace_back(root->val);
        inorder_traverse(root->right, inorder);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> inorder;
         // Traverse tree
        inorder_traverse(root, inorder);
        int n = inorder.size();
        int mini = INT_MAX;
        // Traverse array and find minimum
        for(int i = 1 ; i < n; i++){
            int diff = inorder[i] - inorder[i-1];
            if(diff < mini) {
                mini = diff;      
            }
        }
        return mini;
    }
};