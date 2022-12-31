/*
68 ms
23.1 MB

TC : O(N)
SC : O(height)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
        if(root == NULL){
            return NULL;
        }
        if(root->val < a->val && root->val < b->val){
            return lowestCommonAncestor(root->right, a,b);
        }
        if(root->val > a->val && root->val > b->val){
            return lowestCommonAncestor(root->left, a,b);
        }
        return root;
    }
};