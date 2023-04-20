/*
Runtime : 11 ms
Memory : 9 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : Sahilk-027
 * @brief : Hashing
*/

/*
Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // Emoty tree
        if(!root) return 0;
        int max_ans = INT_MIN;
        // We'll push node and it's index in queue
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            int size = q.size();
            // Fetch the current index
            int curr_index = q.front().second;
            int first, last;
            for(int i=0; i<size; i++){
                // Update the index to avoid integer overflow
                int updated_index = q.front().second-curr_index;
                TreeNode * node = q.front().first;
                q.pop();
                // We are standing at first node
                if(i==0){
                    first = updated_index;
                } 
                // We are standing at last index
                if(i==size-1){
                    last = updated_index;
                } 
                // BFS
                if(node->left){
                    q.push(make_pair(node->left, updated_index * 1ll * 2 + 1));
                }
                    
                if(node->right){
                    q.push(make_pair(node->right, updated_index *1ll * 2 + 2));
                }  
            }
            max_ans = max(max_ans, last - first +1);
        }
        return max_ans;
    }
};