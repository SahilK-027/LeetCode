/*
351 ms
105.2 MB

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
class Node{
public:
    bool isBST;           //to check if tree is bst
    int maxLeft;          //max value in a tree
    int minRight;         //min value in an tree
    int sum;              //current maximum sum
    Node(){
        isBST=true;
        maxLeft=INT_MIN;
        minRight=INT_MAX;
        sum=0;
    }
};
class Solution {
public:
    Node solve(TreeNode* root, int& ans){
        if (root == NULL){
            return Node();
        }
        Node current;
        Node left = solve(root->left,ans);                        //recursive call for left sub-tree
        Node right = solve(root->right,ans);                       //recursive call for right sub-tree
		
		//if sub-tree including this node is bst
        if ( left.isBST && right.isBST && root->val> left.maxLeft && root->val<right.minRight){
            //current tree is a bst
            current.isBST = true;                                                      
            current.sum = left.sum + right.sum + root->val;          
            current.minRight  = min(root->val, left.minRight);
            current.maxLeft = max(root->val, right.maxLeft);
        }
		//if current tree is not a bst
        else {
            current.isBST=false;
            current.sum=max(left.sum, right.sum);
        }
		
        ans=max(ans, current.sum);
        return current;
    }
    int maxSumBST(TreeNode* root){
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};