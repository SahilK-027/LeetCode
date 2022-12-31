/*
12 ms
14.1 MB

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL){
            return root;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* leftTreeAns = solve(root->left, p,q);
        TreeNode* rightTreeAns = solve(root->right, p,q);
        
        if(leftTreeAns == NULL && rightTreeAns == NULL){
            return NULL;
        }
        else if(leftTreeAns != NULL && rightTreeAns == NULL){
            return leftTreeAns;
        }
        else if(leftTreeAns == NULL && rightTreeAns != NULL){
            return rightTreeAns;
        }
        else{
            return root;
        }    
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        TreeNode* ans = solve(root, p, q);
        return ans;
    }
};