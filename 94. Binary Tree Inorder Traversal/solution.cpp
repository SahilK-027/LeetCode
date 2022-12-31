/*
0 ms
8.4 MB

TC : O(N)
SC : O(1)  (Benefit of using Morris traversal)
*/

/**
 * @author : SahilK-027
 * @brief : Iteration
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

//Using Morris Traversal
class Solution {
private:
    TreeNode* findPredecessor(TreeNode* curr){
        TreeNode* temp = curr->left;
        while(temp->right != NULL && temp->right != curr){
            temp = temp->right;
        }
        return temp;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }
        // Start Traversal
        TreeNode* curr = root;
        while(curr != NULL){
            if(!curr->left){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* predecessor = findPredecessor(curr);
                if(predecessor->right == NULL){
                    // Create link
                    predecessor->right = curr;
                    curr = curr->left;
                }
                else{
                    // Destroy link
                    predecessor->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
