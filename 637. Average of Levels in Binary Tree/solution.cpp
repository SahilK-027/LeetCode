/*
20 ms
23.5 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Level order traversal
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
public:
    vector<double> averageOfLevels(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<int>> ans;
        vector<int> v;
        vector<double> res;
        // Level order traversal
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp != NULL){
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            else{
                // One level has completed
                ans.push_back(v);
                v.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        
        // Finding average
        for(auto i: ans){
            double sum = 0;
            double count = 0;
            for(auto j: i){
                sum += j;
                count++;
            }
            res.push_back(sum/count);
        }
        return res;
    }
};