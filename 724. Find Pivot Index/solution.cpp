/*
Runtime : 20 ms
Memory : 31.1 MB

TC : O(n)
SC : O(1)
*/

/**
 * @author : Shashank Bhosagi
 * @brief : Array
 */

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int totalsum = 0;
        int leftsum = 0;

        for (auto i : nums)
        {
            totalsum = totalsum + i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (leftsum == totalsum - nums[i])
            {
                return i;
            }
            leftsum = leftsum + nums[i];
            totalsum = totalsum - nums[i];
        }

        return -1;
    }
};