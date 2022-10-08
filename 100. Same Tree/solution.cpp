// Runtime: 4 ms
// Memory Usage: 9.9 MB

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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // No nodes in both trees 
        if(p == NULL && q == NULL){
            return true;
        }
        // One tree has node but other doesn't
        if(p == NULL && q != NULL){
            return false;
        }
        if(p != NULL && q == NULL){
            return false;
        }
        
        // Go in left and right subtree
        bool left = isSameTree(p->left , q->left);
        bool right = isSameTree(p->right , q->right);
        
        // Check if data is same
        bool data = p->val==q->val ? true : false;
        
        // if all part are true ans is true;
        if(left == true && right == true && data == true){
            return true;
        }
        else{
            return false;
        }
    }
};
