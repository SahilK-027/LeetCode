// Runtime: 19 ms
// Memory Usage: 22.3 MB

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
    pair <bool , int> bal_n_height(TreeNode* root){
        // Base Case
        if(root == NULL){
            pair<bool , int> p = make_pair(true,0);
            return p;
        }
        // Check if left subtree is balanced or not
        pair<int, int> left_subtree = bal_n_height(root -> left);
        
        // Check if right subtree is balanced or not
        pair<int, int> right_subtree = bal_n_height(root -> right);
        
        bool left = left_subtree.first;
        bool right = right_subtree.first;
        bool diff = abs(left_subtree.second - right_subtree.second) <= 1;
        
        pair<bool, int> ans;
        ans.second = max(left_subtree.second, right_subtree.second) + 1;
        
        if(left && right && diff ){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        pair<bool, int> ans;
        ans = bal_n_height(root);
        return ans.first;
    }
};
/*
TC = O(N)
*/
