/*
130 ms
270.1 MB

TC : O(N^2)
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
class Solution {
private:
    int find_Position(vector<int> in, int element){
        int n = in.size();
        for(int i = 0 ; i< n ;i++){
            if(in[i] == element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>post , vector<int> in, int& root_index , int start, int end, int size){
    // Base case
    if(root_index < 0 || start > end){
        return NULL;
    }
    // Find root element from preorder traversal
    int element = post[root_index--];
    TreeNode* root = new TreeNode(element);
    
    // Find root element's position from inorder traversal
    int position = find_Position(in, element);
    
    // Call for left subtree and right subtree
    root->right = solve(post, in, root_index, position+1, end, size);
    root->left = solve(post, in, root_index, start, position-1,size);
    
    return root;
}
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) 
    {
        int post_size = post.size();
        int in_size = in.size();
        int root_index = post_size-1;
        int in_start = 0;
        int in_end = in_size-1;
        TreeNode* root = solve(post, in, root_index, in_start, in_end, post_size);
        return root;
    }
};
