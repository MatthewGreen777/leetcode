# Leetcode problem #26: Remove duplicate from sorted array 

"""
Given an integer array nums sorted in non-decreasing order, remove 
the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same. Then return 
the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, 
you need to do the following things:

Change the array nums such that the first k elements of nums contain 
the unique elements in the order they were present in nums initially. 
The remaining elements of nums are not important as well as the size of nums.

Return k.
"""

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        target = None # create target variabe to check for numplicat
        length = len(nums) - 1 # set variable to length of array
        while length >= 0: # loop through array from back to front
            if nums[length] != target: # New number detected, change target variabe
                target = nums[length]
            elif nums[length] == target: # Duplicate number found, delete it from array
                del nums[length]
            length -= 1 # go back one spot in array

        return len(nums) # return array
        
# Test solution
solutions = Solution()

array = [1, 2, 2, 3, 4, 4, 5]
array2 = [5, 4, 4, 3, 2, 2, 2, 1]
result = solutions.removeDuplicates(array)
print(array)