/*
19 ms
24.6 MB
*/
/**
 * TC: O(n)
 * SC: O(height)
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:    
    int solve(TreeNode* root,unordered_map<int, int>& mp){
        // Base case
        if(!root){
            return 0;
        }

        // Solve left and right subtree recursively
        int left_ans = solve(root->left, mp);
        int right_ans = solve(root->right, mp);

        // Find sum at root
        int sum = left_ans + right_ans + root->val;

        // Mark entry in map ans return sum
        mp[sum]++;
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        // We will use map to store sum and its count
        unordered_map<int, int>mp;
        vector<int> ans;
        solve(root, mp);

        // Finding the max sum from map
        int max_cnt = INT_MIN;
        for(auto i: mp){
            if(i.second > max_cnt){
                max_cnt = i.second;
            }
        }

        // Adding nodes whose sum is max sum to answer
        for(auto i: mp){
            if(i.second == max_cnt){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};