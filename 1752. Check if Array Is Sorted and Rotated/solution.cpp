/*
43 ms
8.3 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : counting
*/

class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int break_pt=0; //Keeping count of break_pts
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]<nums[i])   //if next element is small means breakpt
                break_pt++;
        }
        if(nums[0] < nums[nums.size()-1])
            break_pt++;         //checking for first and last element
        return break_pt<=1;

    }
};