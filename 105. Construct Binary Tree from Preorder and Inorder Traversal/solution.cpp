// Runtime: 99 ms
// Memory Usage: 270.1 MB

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
    // This function is always taking o(n) complexity, so we can optimize it by using map
    int find_Position(vector<int> in, int element){
        int n = in.size();
        for(int i = 0 ; i< n ;i++){
            if(in[i] == element){
                return i;
            }
        }
        return -1;
    }
TreeNode* solve(vector<int> pre, vector<int> in, int& root_index , int start, int end, int size){
    // Base case
    if(root_index >= size || start > end){
        return NULL;
    }
    // Find root element from preorder traversal
    int element = pre[root_index++];
    TreeNode* root = new TreeNode(element);
    
    // Find root element's position from inorder traversal
    int position = find_Position(in, element);
    
    // Call for left subtree and right subtree
    root->left = solve(pre, in, root_index, start, position-1,size);
    root->right = solve(pre, in, root_index, position+1, end, size);
    
    return root;
}
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int pre_size = pre.size();
        int in_size = in.size();
        int root_index = 0;
        int in_start = 0;
        int in_end = in_size-1;
        TreeNode* root = solve(pre, in, root_index, in_start, in_end, pre_size);
        return root;
    }
};
