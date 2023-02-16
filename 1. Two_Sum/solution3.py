"""
4739 ms
14.5 MB
TC : O(N^2)
SC : O(1)
"""

"""
 * @author : ShubhamAsbe
 * @brief : Iteration
"""

class Solution(object):
    def twoSum(self, nums, target):
      #for each number in the array we will check there exist another which will sum up to give the target
      for i in range(len(nums)):
            for j in range(len(nums)):
                if nums[i]+nums[j]==target and j!=i:
                    return [i,j]
