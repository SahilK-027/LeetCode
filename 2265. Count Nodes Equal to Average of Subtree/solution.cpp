/*
11 ms
12 MB

TC : O(N)
SC : O(height)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
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

// Recuirsive Solution
// We will use pair<pair<sum,number>,avg> to store ans...And a count
// For any node with avg == root->val count++
class Solution {
private:
    pair<pair<int,int>,int> solve(TreeNode* root, int& count){
        //Base case
        if(root == NULL){
            pair<int,int> a = make_pair(0,0);
            pair<pair<int,int>,int> p = make_pair(a,0);
            return p;
        }
        // Recursive Call
        pair<pair<int,int>,int> leftAns = solve(root->left,count);
        pair<pair<int,int>,int> rightAns = solve(root->right,count);
        
        int sum = leftAns.first.first + rightAns.first.first + root->val;
        int n = 1 + leftAns.first.second + rightAns.first.second;
        int avg = sum / n;
        if(avg == root->val){
            count = count+1;
        }
        
        pair<pair<int,int>,int> ans;
        ans.first.first = sum;
        ans.first.second = n;
        ans.second = avg;
        return ans;
        
    }
public:
    int averageOfSubtree(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int count = 0; 
        pair<pair<int,int>,int> ans = solve(root,count);
        return count;
    }
};