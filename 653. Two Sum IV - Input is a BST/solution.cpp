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
    void inorder(TreeNode* root, vector<int>& v){
        if(root == NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
public:
    bool findTarget(TreeNode* root, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int> v;
        inorder(root,v);
        int i = 0;
        int j = v.size()-1;
        while(i<j)
        {
            // IF FOUND ELEMENTS WITH TARGET SUM RETURN TRUE
            if(v[i]+v[j] == target){
                return true;
            }
            // IF SUM IS LESS MOVE TO RIGHT
            else if(v[i]+v[j] < target){
                i++;
            }
            // IF SUM IS MORE MOVE TO LEFT
            else if(v[i]+v[j] > target){
                j--;
            }
        }
        // WE'RE OUT OF LOOP MEANS NO VALUES FOUND
        return false;
    }
};