/*
15 ms
25.6 MBq

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : InOrder Traversal
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
 // Inorder of BST is sorted
class Solution {
private:    
    void traverse(vector<int>&inorder, TreeNode* root){
        if(!root) return;
        traverse(inorder, root->left);
        inorder.push_back(root->val);
        traverse(inorder, root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int>inorder;
        traverse(inorder, root);
        int mini = INT_MAX;
        for(int i =1 ; i < inorder.size(); i++){
            if(abs(inorder[i]-inorder[i-1]) < mini){
                mini = abs(inorder[i]-inorder[i-1]);
            }
        }
        return mini;
    }
};