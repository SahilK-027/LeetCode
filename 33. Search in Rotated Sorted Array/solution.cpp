/*
8 ms
10.9 MB

TC : O(log N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Binary search
*/

class Solution
{
private:
  int binary_search(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;
    int m = s + (e - s) / 2;
    while (s < e)
    {
        if (nums[m] >= nums[0])
        {
            s = m + 1;
        }
        else
        {
            e = m;
        }
        m = s + (e - s) / 2;
    }
    int pivot_index = s;
    int start, end, mid;
    if (nums[pivot_index] <= target && target <= nums[nums.size() - 1])
    {
        start = pivot_index;
        end = nums.size() - 1;
        mid = start + (end - start) / 2;
    }
    else
    {
        start = 0;
        end = pivot_index - 1;
        mid = start + (end - start) / 2;
    }
    while (start <= end)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
public:
    int search(vector<int> &nums, int target)
    {
        int ans = -1;
        ans = binary_search(nums, target);
        return ans;
    }
};
