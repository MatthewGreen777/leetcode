// leetcode problem #27: Remove Element

/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The order of the elements may be changed. Then return the number of elements 
in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get 
accepted, you need to do the following things:

    Change the array nums such that the first k elements of nums contain the elements 
    which are not equal to val. The remaining elements of nums are not important as well 
    as the size of nums.

    Return k.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int notRemoved = 0; // number of elements not removed
            for (int i = 0; i < nums.size(); i++) { // loop through vector
                if (nums.at(i) == val) { // if element = value we want to remove
                    nums.erase(nums.begin() + i); // remove element from vector
                    i--; // decrease counter by 1 because we erased the i'th element
                } else { // element was not removed, increase conter
                    notRemoved++;
                }
            }
            return notRemoved; // return number of elements that were not removed
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
    
    cout << "Vector before removal: ";
    for (int i = 0; i < vector.size(); i++) {
        if (i == vector.size() - 1) {
            cout << vector.at(i) << endl;
        } else {
            cout << vector.at(i) << ", ";
        }
    }

    int numRemoved = solute.removeElement(vector, 3);
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