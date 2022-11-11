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
/*
in this solution insted of finding diameter and height semparately we will find both in one function and store it in pair <diameter, height>
TC: O(n) ....n -> no. of nodes in tree
*/
class Solution {
private:
    pair<int,int> dia_n_Hieght(TreeNode* root){
        // Make pair of diameter as well as height
        
        if(root == NULL){
            // If root is null diameter and height both are 0
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        // recursion will find diameter and height of left and right subtree
        pair<int,int> left_tree = dia_n_Hieght(root->left);
        pair<int,int> right_tree = dia_n_Hieght(root->right);
        
        // op1 is diamter of left subtree
        int op1= left_tree.first;
        
        // op2 is diamter of right subtree
        int op2= right_tree.first;
        
        // op3 is combination of max_height of left and right subtree.
        int op3 = left_tree.second + right_tree.second;
        
        // So our ans pair will have diameter as max(op1,op2,op3)
        // and height as max(left_tree_height, right_tree_height) + 1 (root_node)
        pair<int,int>ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left_tree.second,right_tree.second) + 1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans = dia_n_Hieght(root);
        // We have to return max diameter so it will be stored in ans.second
        return ans.first;
    }
};