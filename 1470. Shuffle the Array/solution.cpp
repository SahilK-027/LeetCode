/*
7 ms
9.7 MB
*/

/**
 * TC: O(n)
 * SC: O(1)
 */

/**
 * @author : SahilK-027
 * @brief : Traversal
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0;
        int j = n;
        vector<int> ans;
        while(j < 2*n){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;
            j++;
        }
        return ans;
    }
};