"""
70 ms
14.4 MB
TC : O(logN)
SC : O(1)
*/

/**
 * @author : Shubham Asbe
 * @brief : Divide and conquer (binary search) 
"""

class Solution(object):
    def searchRange(self, nums, target):
        """
        we used binary search logic to find the occurance of the first and last element
        """
        s=0
        e=len(nums)-1
        m=(s+e)//2
        n=0
        if len(nums)==0:
            return [-1,-1]
        while(s<=e):
            if target==nums[m]:
                n=m
                if len(nums)==1:
                    return [0,0]
                while nums[m]==target:
                    m=m+1
                    if m>=len(nums):
                        break
                while nums[n]==target and n>-1:
                    n=n-1
                return [n+1,m-1]
            elif target>nums[m]:
                s=m+1
            else:
                e=m-1
            m=(s+e)//2
        return [-1,-1]
        
