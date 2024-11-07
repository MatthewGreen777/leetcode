// leetcode problem #80: Remove Duplicate from Sorted Array II

/*
Given an integer array nums sorted in non-decreasing order, remove some 
duplicates in-place such that each unique element appears at most twice. 
The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you 
must instead have the result be placed in the first part of the array nums. More 
formally, if there are k elements after removing the duplicates, then the first 
k elements of nums should hold the final result. It does not matter what you leave 
beyond the first k elements.


    Return k after placing the final result in the first k slots of nums.

    Do not allocate extra space for another array. 
    You must do this by modifying the input array in-place with O(1) extra memory.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            // assumes that vector has more than 2 elements
            int notRemoved = 1; // number of elements not removed
            int value = nums.at(0);
            int usedCounter = 0;
            for (int i = 1; i < nums.size(); i++) { // loop through vector
                if ((nums.at(i) == value) && (usedCounter == 1)) { // element has been used two time before
                    nums.erase(nums.begin() + i);
                    i--;
                } else if ((nums.at(i) == value) && (usedCounter == 0)) { // second occurance of element
                    notRemoved++; // increase counter
                    usedCounter++;
                } else { // new number
                    value = nums.at(i);
                    usedCounter = 0;
                    notRemoved++;
                }
            }
            return notRemoved; // return number of elements that were not removed
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