/*
10 ms
10.1 MB
*/
/**
 * TC: O( nums[i] * nums.length)
 * SC: O(1)
*/
/**
 * @author : SahilK-027
 * @brief : Array traversal
 */

class Solution {
public:
    vector<int> separateDigits(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size()-1;
        // Traverse array from back
        for(int i = n; i >= 0; i--){
            // For each number in array extract digits and store in answer
            while(arr[i]){
                ans.push_back(arr[i] % 10);
                arr[i] /= 10;
            }
        }
        // Reverse the ans as we had traversed from back
        reverse(ans.begin(), ans.end());
        return ans;
    }
};