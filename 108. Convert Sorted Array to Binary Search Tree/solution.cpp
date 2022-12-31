/*
29 ms
21.4 MB

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
class Solution
{
private:
    TreeNode* solve(int s, int e, vector<int>& v){
        if(s > e){
            return NULL;
        }
        int m = (s + e)/2;
        TreeNode* root = new TreeNode(v[m]);
        root -> left = solve(s,m-1,v);
        root-> right = solve(m+1,e,v);
        return root;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &v)
    {
        int s = 0;
        int e = v.size()-1;
        TreeNode* ans = solve(s,e,v);
        return ans;
    }
};