# Leetcode problem #80: Remove duplicate from sorted array II

"""
Given an integer array nums sorted in non-decreasing order, remove some 
duplicates in-place such that each unique element appears at most twice. T
he relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, 
you must instead have the result be placed in the first part of the array nums. 
More formally, if there are k elements after removing the duplicates, then the 
first k elements of nums should hold the final result. It does not matter what 
you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying 
the input array in-place with O(1) extra memory.

"""

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        target = None # create target variabe to check for numplicat
        use = 0 # set variable for how many times variable has been used
        length = len(nums) - 1 # set variable to length of array
        while length >= 0: # loop through array from back to front
            if nums[length] != target: # New number detected, change target variabe and set use to 1
                target = nums[length]
                use = 1 
            elif nums[length] == target and use == 1: # second appearence of variable, set use to 2
                use =2
            elif nums[length] == target and use == 2: # Duplicate number found and has been used twice already, remove it from array
                del nums[length]
            length -= 1 # go back one spot in array

        return len(nums) # return array
    
# Test solution
solutions = Solution()

array = [1, 2, 2, 2, 3, 4, 4, 5]
array2 = [5, 4, 4, 3, 2, 2, 2, 1]
result = solutions.removeDuplicates(array)
print(array)