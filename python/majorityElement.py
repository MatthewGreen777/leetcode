# Leetcode Promble #169: Majority Element

"""
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.
"""

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0 # variable to track frequency
        target = None # variable to track target number

        for i in range(len(nums)):
            if target == None: # set target to first element
                target = nums[i]
            if nums[i] == target: # increase count of target if number matches
                count += 1
            elif nums[i] != target and count > 0: # decrease count of target as long as it has a count > than 0
                count -= 1
            else: # new target number 
                target = nums[i]
        return target
    
solution = Solution()

array = [1, 2, 3, 1, 2, 1, 3, 1, 2, 1, 1, 1, 2, 4]

result = solution.majorityElement(array)
print(result)
        