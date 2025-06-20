/*
leetcode problem #3371: Identify the Largest Outlier in an Array


You are given an integer array nums. This array contains n elements, 
where exactly n - 2 elements are special numbers. One of the remaining 
two elements is the sum of these special numbers, and the other is an outlier.

An outlier is defined as a number that is neither one of the original 
special numbers nor the element representing the sum of those numbers.

Note that special numbers, the sum element, and the outlier must have 
distinct indices, but may share the same value.

Return the largest potential outlier in nums.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int total_sum = 0;
        std::unordered_map<int, int> counts;

        for (int num : nums) {
            total_sum += num;
            counts[num]++;
        }

        int max_outlier = std::numeric_limits<int>::min();

        for (int candidate_outlier : nums) {
            int sum_without_outlier = total_sum - candidate_outlier;

            if (sum_without_outlier % 2 != 0) {
                continue;
            }

            int potential_y = sum_without_outlier / 2;

            if (counts.count(potential_y) == 0) {
                continue;
            }

            if (candidate_outlier == potential_y) {
                if (counts[potential_y] < 2) {
                    continue;
                }
            }
            
            max_outlier = std::max(max_outlier, candidate_outlier);
        }

        return max_outlier;
    }
};