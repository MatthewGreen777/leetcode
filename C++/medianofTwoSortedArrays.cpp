/*
leetcode problem #4: Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, 
return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    // Ensure nums1 is the smaller array
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

    int x = nums1.size();
    int y = nums2.size();
    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        // If partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
        // If partitionX is length of input then there is nothing on right side. Use +INF for minRightX
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            // Found correct partition
            if ((x + y) % 2 == 0)
                return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
            else
                return std::max(maxLeftX, maxLeftY);
        } else if (maxLeftX > minRightY) {
            // Move partitionX to left
            high = partitionX - 1;
        } else {
            // Move partitionX to right
            low = partitionX + 1;
        }
    }

    throw std::invalid_argument("Input arrays are not sorted or invalid");
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed with current time

    std::vector<int> test;
    std::vector<int> test2;
    
    for (int i = 0; i < 20; i++) {
        test.push_back(rand() % 200);
    }
    for (int i = 0; i < 20; i++) {
        test2.push_back(rand() % 100);
    }

    std::sort(test.begin(), test.end());
    std::sort(test2.begin(), test2.end());
    
    double median = findMedianSortedArrays(test, test2);
    std::cout << median;
    
    return 0;
}