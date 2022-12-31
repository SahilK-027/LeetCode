/*
15 ms
17.2 MB

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
private:
    void levelOrderLeft(TreeNode* root, vector<int>&v){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            v.push_back(temp->val);
            q.pop();
            if (temp->left)
                q.push(temp->left);
            else{
                v.push_back(-1);
            }
            if (temp->right)
                q.push(temp->right);
            else{
                v.push_back(INT_MIN);
            }
        }
    }
    void levelOrderRight(TreeNode* root, vector<int>&v){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            v.push_back(temp->val);
            q.pop();
            if (temp->right)
                q.push(temp->right);
            else{
                v.push_back(-1);
            }
            
            if (temp->left)
                q.push(temp->left);
            else{
                v.push_back(INT_MIN);
            }
        }
    }
public:
    bool isSymmetric(TreeNode* root){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        // If root is only node in binary tree
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        if(root->left == NULL && root->right != NULL){
            return false;
        }
        if(root->left != NULL && root->right == NULL){
            return false;
        }
        //Level order traverse left subtree and store ans in vector
        vector<int> left_tree;
        levelOrderLeft(root->left, left_tree);
        
        //Level order traverse right subtree and store ans in vector
        vector<int> right_tree;
        levelOrderRight(root->right,right_tree);
        
        // If both vectors have different size means tree cannot be similar
        if(left_tree.size() != right_tree.size()){
            return false;
        }
        
        // Otherwise check if both vector are equal or not
        for(int i=0; i<left_tree.size();i++){
            if(left_tree[i] != right_tree[i]){
                return false;
            }
        }
        return true;
    }
};
