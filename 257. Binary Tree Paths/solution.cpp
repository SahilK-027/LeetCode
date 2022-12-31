/*
8 ms
13.3 MB

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

 // My approach
class Solution {
private:
    void solve(TreeNode* root, vector<string> &ans, string t){
        // Base case
        if(root == NULL){
            return;
        }
        // If root is leaf then store answer
        if(root->left == NULL && root->right == NULL){
            t += to_string(root->val);
            ans.push_back(t);
            t.clear();
            return;
        }
        // Build answer
        t += to_string(root->val);
        t += "->";
        // Recursion will solve left and right subtree
        solve(root->left, ans, t);
        solve(root->right, ans, t);
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