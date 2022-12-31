/*
36 ms
24.4 MB

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

//APPROACH 1:
/*
INORDER OF BST IS ALWAYS SORTED
*/
class Solution {
private:
    void inorder(TreeNode* root,vector<int>& v){
         if(root == NULL){
              return ;
         }
         inorder(root->left, v);
         v.push_back(root->val);
         inorder(root->right ,v);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);
        return v[k-1];
    }
};