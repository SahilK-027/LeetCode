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
    void solve(TreeNode* root, vector<int> v, int target, int& count){
        // Base case
        if(root == NULL){
            return ;
        }
        
        // Store current root value in vector
        v.push_back(root->val);
        
        // Solve left subtree and solve right subtree
        solve(root->left, v, target, count);
        solve(root->right, v, target, count);
        
        // Check sum
        long long sum = 0;
        for(int i = v.size()-1 ; i>= 0 ;i--){
            sum += v[i];
            if(sum == target){
                count++;
            }
        }
        
        // While going pack remove the last stored data from vector
        v.pop_back();
    }
public:
    int pathSum(TreeNode* root, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int> v;
        int count = 0;
        solve(root, v, target,count);
        return count;
    }
};