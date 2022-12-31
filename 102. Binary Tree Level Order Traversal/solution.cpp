/*
0 ms
12.5 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Iterative + Queue
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL ){
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp != NULL)
            {
                v.push_back(temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            else
            {
                // 1 level has completely traversed
                ans.push_back(v);
                v.clear();
                if (!q.empty())
                {
                    // Queue still has elements in next level
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};
