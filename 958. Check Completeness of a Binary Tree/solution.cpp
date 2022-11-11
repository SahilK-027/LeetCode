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
    int countNodes(TreeNode* root){
        // Base case
        if(root == NULL){
            return 0;
        }
        // Root + Left + Right
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }
    bool solve(TreeNode* root, int index, int nodeCount){
        // Base case
        if(root == NULL){
            return true;
        }

        // If index exceeds total count
        if(index >= nodeCount){
            return false;
        }

        // Else solve left and right subtree
        else{
            bool leftAns= solve(root->left, 2*index+1 ,nodeCount);
            bool rightAns= solve(root->right, 2*index+2 ,nodeCount);
            return leftAns && rightAns;
        }
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int nodeCount = countNodes(root);
        int index = 0;
        return solve(root, index, nodeCount);
    }
};