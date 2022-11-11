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

// CONSTRUCT INORDERED SORTED ARRAY
// USE  108. Convert Sorted Array to Binary Search Tree  LOGIC TO SOLVE
class Solution {
private:
    void inorder(TreeNode* root, vector<int>& v){
        if(root == NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    // Q. 108 LOGIC
    TreeNode* solve(int s, int e, vector<int>& v){
        if(s > e){
            return NULL;
        }
        int m = (s + e)/2;
        TreeNode* root = new TreeNode(v[m]);
        root -> left = solve(s,m-1,v);
        root-> right = solve(m+1,e,v);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int> v;
        inorder(root,v);
        
        // Q. 108 LOGIC
        int s = 0;
        int e = v.size()-1;
        TreeNode* ans = solve(s,e,v);
        return ans;
    }
};