/*
8 ms
12.6 MB

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
    void findLeaf(TreeNode* root, vector<int> &v){
        // Empty tree
        if(root == NULL){
            return;
        }
        // Leaf node
        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
            return;
        }
        // Recursive call
        findLeaf(root->left,v);
        findLeaf(root->right,v);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // Find all leaf nodes and store in vectors and then check if vectors are same
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int> tree1;
        vector<int> tree2;
        findLeaf(root1, tree1);
        findLeaf(root2, tree2);
        if(tree1.size() != tree2.size()){
            return false;
        }
        for(int i = 0 ; i<tree1.size() ;i++){
            if(tree1[i] != tree2[i]){
                return false;
            }
        }
        return true;
    }
};