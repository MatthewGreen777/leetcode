/*
leetcode problem #167: Two Sum II - Input Array Is Sorted

Given a 1-indexed array of integers numbers that is already sorted 
in non-decreasing order, find two numbers such that they add up to 
a specific target number. Let these two numbers be numbers[index1] 
and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by 
one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. 
You may not use the same element twice.

Your solution must use only constant extra space.
*/

#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    std::vector<int> solution;
    int begin = 0;
    int end = numbers.size() - 1;

    while (begin < end) {
        if (numbers[begin] + numbers[end] == target) {
            solution.push_back(begin + 1);
            solution.push_back(end + 1);
            break;
        } else if (numbers[begin] + numbers[end] < target) {
            begin++;
        } else {
            end--;
        }
    }
    return solution; 
}