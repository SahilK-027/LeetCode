/*
148 ms
78 MB

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

 // rem_subtree_sum = total_tree_sum - curr_subtree_sum
class Solution {
private:
    // Function to calculate total sum of tree
    void tot_sum(TreeNode*& root, long &total_sum){
        // Base case
        if(root == NULL){
            return;
        }
        // Processing
        total_sum += root->val;
        // Recursive calls
        tot_sum(root->left, total_sum);
        tot_sum(root->right, total_sum);
    }

    int solve(TreeNode* root, long& maxp, long& total_sum){
        // Base case
        if(root == NULL){
            return 0;
        }
        // Find curr_subtree_sum 
        long left_sum = solve(root->left, maxp, total_sum);
        long right_sum = solve(root->right, maxp, total_sum);
        long curr_subtree_sum = root->val + left_sum + right_sum;
        // Find remaining subree sum
        long rem_subtree_sum = total_sum - curr_subtree_sum;
        // Update max
        maxp = max(maxp, curr_subtree_sum * rem_subtree_sum);
        // We are returning curr_subtree_sum
        return curr_subtree_sum;
    }
public:
    int maxProduct(TreeNode* root) {
        // Calculate total sum
        long total_sum = 0;
        tot_sum(root, total_sum);
        // Solve 
        long maxp = 0;
        solve(root, maxp, total_sum);
        // Since the answer may be too large, return it modulo 10^9 + 7.
        return (maxp % 1000000007);
    }
};