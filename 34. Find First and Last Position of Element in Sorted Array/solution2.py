"""
70 ms
14.4 MB
TC : O(N)
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
        #check if the start is less than or equal to end
        while(s<=e):
            if target==nums[m]:
                n=m
                #When will check the starting and ending of the number
                while nums[m]==target:
                    m=m+1
                    if m>=len(nums):
                        break
                #check for the target varible and the bounds of array
                while nums[n]==target and n>-1:
                    n=n-1
                return [n+1,m-1]
            elif target>nums[m]:
                s=m+1
            else:
                e=m-1
            m=(s+e)//2
        return [-1,-1]
        
