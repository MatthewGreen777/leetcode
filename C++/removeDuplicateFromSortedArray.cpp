// leetcode problem #26: Remove Duplicate from Sorted Array

/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates 
in-place such that each unique element appears only once. The relative order of the 
elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need 
to do the following things:

    Change the array nums such that the first k elements of nums 
    contain the unique elements in the order they were present in nums initially. 
    The remaining elements of nums are not important as well as the size of nums.

    Return k.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            // this solution assumes that the vector is not empty and has more than 1 element
            int notRemoved = 0;
            int value = nums.at(0);
            for (int i = 1; i < nums.size(); i++) {
                if (nums.at(i) == value) {
                    nums.erase(nums.begin() + i);
                    i--;
                } else {
                    value = nums.at(i);
                    notRemoved++;
                }
            }
            return notRemoved;
        }

    // sort function to sort the two unsorted array before merging them
    // this is an insertion sort as we are only sorting a small vector
    void sort(std::vector<int>& nums1) {
        int n = nums1.size();

        for (int i = 1; i < n; ++i) {
            int key = nums1[i];
            int j = i - 1;

            // Move elements of nums1[0..i-1] that are greater than key
            // to one position ahead of their current position
            while (j >= 0 && nums1[j] > key) {
                nums1[j + 1] = nums1[j];
                --j;
            }

            nums1[j + 1] = key;
        }
    }
};

int main() {
    srand(time(0));
    vector<int> vector; 
    Solution solute;
    
    int size = 100;
    for (int i = 0; i < size; i++) {
        int insert = rand() % (10 - 1 + + 1) + 1; // insert number between 1 and 10
        vector.push_back(insert);
    }
    solute.sort(vector);
    
    cout << "Vector before removal: ";
    for (int i = 0; i < vector.size(); i++) {
        if (i == vector.size() - 1) {
            cout << vector.at(i) << endl;
        } else {
            cout << vector.at(i) << ", ";
        }
    }

    int numRemoved = solute.removeDuplicates(vector);
    cout << "Number of elements remaining: " << numRemoved << endl;
    cout << "Vector after removal: ";
    for (int i = 0; i < vector.size(); i++) {
        if (i == vector.size() - 1) {
            cout << vector.at(i) << endl;
        } else {
            cout << vector.at(i) << ", ";
        }
    }
    return 0;
}