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
    int min_swaps(vector<int>& arr)
    {
        int size = arr.size();
        // This pair will contain array element and its position
        pair<int, int> position[size];
        for (int i = 0; i < size; i++)
        {
            position[i].first = arr[i];
            position[i].second = i;
        }
        // Sort the position 
        sort(position, position + size);
        
        // Visited arrat
        vector<bool> visited(size, false);
        int ans = 0;
        for (int i = 0; i < size; i++)
        {
            // If element is already visited
            if (visited[i] || position[i].second == i)
            {
                continue;
            }
            // Otherwise calculate number of elements and add it to ans
            int cnt = -1;
            int j = i;
            while (!visited[j])
            {
                visited[j] = 1;
                j = position[j].second;
                cnt++;
            }
            if (cnt > 0)
            {
                ans += cnt;
            }
        }
        return ans;
    }
    int solve(TreeNode*& root) {
        // Level order traversal
        int ans = 0;
        // If tree is empty
        if(root == NULL ){
            return ans;
        }
        // Initialize queue
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        // Algo
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp != NULL)
            {
                // We are currently traversing one level
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
                ans += min_swaps(v);
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
public:
    int minimumOperations(TreeNode* root) {
        return solve(root);
    }
};