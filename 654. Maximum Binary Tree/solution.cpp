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

 // Approach similar to quicksort
class Solution {
private:
    TreeNode* solve(vector<int>& arr, int s, int e, TreeNode*& root ){
        // Base case
        if(s > e){
            return NULL;
        }
        // Find max element and its index in array from array
        int maxi = INT_MIN;
        int maxi_index = -1;
        for(int i = s ; i <= e ; i++){
            if(arr[i] > maxi){
                maxi = arr[i];
                maxi_index = i;
            }
        }
        // Attach that to tree
        root = new TreeNode(maxi);

        // Recursion will solve  subarray prefix to the left 
        root->left = solve(arr, s, maxi_index-1, root->left);

        // Recursion will solve  subarray prefix to the right
        root->right = solve(arr, maxi_index+1, e, root->right);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        TreeNode* root = NULL;
        solve(arr, s,e, root);
        return root;
    }
};