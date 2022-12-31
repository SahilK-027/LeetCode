/*
1189 ms
175.6 MB

TC : O(N)
SC : O(height)
*/

/**
 * @author : SahilK-027
 * @brief : DFS
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    set<TreeNode*> visited;
    void create_mapping(TreeNode* root, unordered_map < TreeNode* , TreeNode* >&mp){
        if(root == NULL){
            return;
        }
        if(root->left){
            mp[root->left] = root;
            create_mapping(root->left, mp);
        }
        if(root->right){
            mp[root->right] = root;
            create_mapping(root->right, mp);
        }
    }
    void traverseInK(TreeNode* root, int k,  unordered_map < TreeNode* , TreeNode* > nodeToParent,vector<int>& ans){
        // Keeping track of already visited nodes
        if( visited.find(root) != visited.end() )
            return;
        visited.insert(root);

        if(k <= 0 ){
            ans.push_back(root->val);
            return;
        }
        // Traverse in all direction
        if(root->left){
            traverseInK(root->left, k-1, nodeToParent ,ans);
        }
        if(root->right){
            traverseInK(root->right, k-1, nodeToParent ,ans);
        }
        if(nodeToParent[root]){
            traverseInK(nodeToParent[root], k-1, nodeToParent ,ans);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k){
        int val = t->val;
        // Step 1: Create node to parent mapping
        unordered_map < TreeNode* , TreeNode* > nodeToParent;
        nodeToParent[root] = NULL;
        create_mapping(root, nodeToParent);
        vector<int> ans;
        // Step 2: Traverse in k steps and store ans at kth step
        traverseInK(t, k ,nodeToParent, ans);
        return ans;
    }
};