/*
20 ms
34.1 MB
*/

/**
 * TC: O(n)
 * SC: O(height)
*/

/**
 * @author : SahilK-027
 * @brief : Recursion
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
    // We will build a path as string
    string solve(TreeNode* root, vector<TreeNode*>& ans, unordered_map<string, int>& mp){
        // If we reached at leaf node return empty path with $ to stop storing repeated paths
        if(!root) return "$";
        // Otherwise build path from root->val
        string path = solve( root -> left, ans, mp )+ "$" 
                    + solve( root -> right, ans, mp ) + "$" 
                    + to_string(root -> val);
        // Store that path in map
        mp[path]++;
        // If duplicate path exists store root in array
        if(mp[path] == 2){
            ans.push_back(root);
        }
        return path;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // To store answer
        vector<TreeNode*> ans;
        // To store path and count
        unordered_map<string, int>mp;
        solve(root, ans, mp);
        return ans;
    }
};