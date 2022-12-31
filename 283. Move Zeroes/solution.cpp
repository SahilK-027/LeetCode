/*
59 ms
19.2 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Iterative + Two Pointer
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int n=nums.size();
        int i=0;
        for (int j = 0; j < n; j++)       // N rounds 
        {
            if(nums[j]!=0)         //whenever non zero number is found swap
            {
                swap(nums[j],nums[i]);
                i++;
            }
            /*else
            {
                continue;
            }*/
        }
     }
};