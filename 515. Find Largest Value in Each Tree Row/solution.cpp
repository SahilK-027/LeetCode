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
public:
    vector<int> largestValues(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int> ans;
        if(root == NULL ){
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int max = INT_MIN;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp != NULL)
            {
               if(temp->val > max){
                   max = temp->val;
               }
               if (temp->left){
                   q.push(temp->left);
               }
               if (temp->right){
                   q.push(temp->right);
               }
            }
            else
            {
                // 1 level has completely traversed
                ans.push_back(max);
                max = INT_MIN;
                if (!q.empty()){
                    // Queue still has elements in next level
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};