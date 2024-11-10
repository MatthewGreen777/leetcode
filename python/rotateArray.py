# Leetcode Problem #189: Rotate Array

"""
Given an integer array nums, rotate the array to the 
right by k steps, where k is non-negative.
"""


"""
brute force method that was to slow for leetcode

origin, target = None, None
for i in range(k):
    if origin == None:
        origin = nums[0]
    for j in range(len(nums)):
        if j == len(nums) - 1:
            target = nums[0]
            nums[0] = origin
        else:
            target = nums[j + 1]
            nums[j +1] = origin
            origin = target
"""

class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        copy = nums.copy() # create copy of array
        for i in range(len(nums)): # go through array
            if k + i < len(nums):  # copying elemnt does not overflow
                nums[i + k] = copy[i] # copy element up k spaces
            else: # copying element would cause overflow error
                num = i + k # variable to find which index to copy to
                while num >= len(nums): # subtract from variable until in valid location
                    num = num - len(nums)
                nums[num] = copy[i] # copy element
        return nums

        
solution = Solution()

array = [1, 2, 3, 4, 5, 6, 7]
right = 9

result = solution.rotate(array, right)
print(result)