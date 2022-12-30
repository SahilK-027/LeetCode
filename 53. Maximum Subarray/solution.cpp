/*
127 ms
67.7 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Iterative 
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Keep track of current sum and maxSum
        int maxi = INT_MIN;
        int currSum = 0;
        for(auto i: nums){
            // If at any point current Sum is decrasing set it back to 0
            if(currSum < 0){
                currSum = 0;
            }
            // Add current num to sum
            currSum += i;
            // Update maxi
            maxi = max(maxi, currSum);
        }
        return maxi;
    }
};