/*
Runtime : 87 ms
Memory : 31.5 MB

TC : O(nlogn)
SC : O(1)
*/

/**
 * @author : Shashank Bhosagi
 * @brief : Normal 'for' loop with Binary Search
 */
class Solution
{
private:
    int binarySearch(vector<int> &arr, int size, int key)
    {
        int start = 0;
        int end = size - 1;
        int mid = (start + end) / 2;

        // Binary search algorithm to find the index of key in arr
        while (start <= end)
        {
            if (arr[mid] == key)
            {
                return mid; // key found at mid index
            }
            if (key > arr[mid])
            {
                start = mid + 1; // search in right half of arr
            }
            if (key < arr[mid])
            {
                end = mid - 1; // search in left half of arr
            }
            mid = (start + end) / 2;
        }

        return -1; // key not found in arr
    }

public:
    int firstMissingPositive(vector<int> &nums)
    {
        int max = *max_element(nums.begin(), nums.end()); // find the maximum element in nums
        int size = nums.size();
        sort(nums.begin(), nums.end()); // sort the elements in nums in non-decreasing order

        // Check each positive integer from 1 to max for presence in nums
        for (int i = 1; i <= max; i++)
        {
            int temp = binarySearch(nums, size, i); // find the index of i in nums using binary search
            if (temp == -1)
            {
                return i; // i not found in nums, so it is the first missing positive integer
            }
        }

        // If all positive integers from 1 to max are present in nums, then the first missing positive integer is max + 1
        if (size == 1 && nums[0] < 0)
        {
            return 1; // special case for nums containing only negative integers
        }
        if (size == 2 && nums[0] < 0 && nums[1] < 0)
        {
            return 1; // special case for nums containing two negative integers
        }

        return max + 1; // all positive integers from 1 to max are present in nums, so the first missing positive integer is max + 1
    }
};
