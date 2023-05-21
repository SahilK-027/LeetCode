/*
308 ms
117.6 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : LIS
*/

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        vector<int> LongestIncSubseq;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            if (LongestIncSubseq.empty() || LongestIncSubseq[LongestIncSubseq.size() - 1] <= x) { 
                // Append to LIS if new element is >= last element in LIS
                LongestIncSubseq.push_back(x);
                nums[i] = LongestIncSubseq.size();
            } 
            else {
                int idx = upper_bound(LongestIncSubseq.begin(), LongestIncSubseq.end(), x) -      LongestIncSubseq.begin(); 
                // Find the index of the smallest number > x
                LongestIncSubseq[idx] = x; // Replace that number with x
                nums[i] = idx + 1;
            }
        }
        return nums;
    }
};