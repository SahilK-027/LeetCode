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

 // Back trackiong
class Solution {
private:
    void solve(TreeNode* root, vector<string> &ans, string& t){
        // Base case
        if(root == NULL){
            return;
        }
        // If root is leaf then store answer
        if(root->left == NULL && root->right == NULL){
            string oldTemp = t;
            t += to_string(root->val);
            ans.push_back(t);
            t = oldTemp;
            return;
        }
        // Build answer
        string oldTemp = t;
        t += to_string(root->val);
        t += "->";
        // Recursion will solve left and right subtree
        solve(root->left, ans, t);
        solve(root->right, ans, t);

        // Backtracking as we are passing string by reference this time
        t = oldTemp;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // Container to store ans
        vector<string>ans;
        string temp;
        // Helper function
        solve(root, ans, temp);
        return ans;
    }
};
