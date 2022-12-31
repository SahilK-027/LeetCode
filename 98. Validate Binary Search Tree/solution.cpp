/*
21 ms
21.8 MB

TC : O(N)
SC : O(Heoght)
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
    void inorder(TreeNode* root,vector<int>& v){
        if(root == NULL){
            return ;
        }
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right ,v);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        if(v.size() == 1){
            return true;
        }
        int prev = 0;
        for(int curr = 1; curr<v.size();curr++){
            if(v[curr] <= v[prev]){
                return false;
            }
            prev++;
        }
        return true;
    }
};
