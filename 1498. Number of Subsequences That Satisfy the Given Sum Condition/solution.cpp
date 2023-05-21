/*
142 ms
49.9 MB

TC : O(N log N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Sorting + Binary Search
*/

// Sort and then BS
#define M 1000000007
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int res=0,n=nums.size(),i=0,j=n-1;
        vector<int>pow2(n+1,1);
        for(int i=1;i<=n;i++)
        {
            pow2[i]=(2*pow2[i-1])%M;
        }
        while(i<=j)
        {
            if(nums[j]+nums[i]<=target)
            {
                res=(res+pow2[j-i])%M;
                i++;
            }
            else
                j--;
        }
        return res;
    }
};