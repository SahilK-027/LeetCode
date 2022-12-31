/*
16 ms
21.9 MB

TC : O(N)
SC : O(height)
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

/*
GO WITH THE LEVEL ORDER AND THEN RETURN THE FIRST VALUE IN LAST LEVEL
*/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int val = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp != NULL){
                val = temp->val;
                // We want the leftmost root so we will push right first then left
                if(temp->right){
                    q.push(temp->right);
                }
                if(temp->left){
                    q.push(temp->left);
                }
            }
            else{
                // One level is complete
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        return val;
    }
};