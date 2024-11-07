// leetcode problem #169: Majority Element

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            // moores voting algorithm is more efficient
            // answer provided is O(n^2)
            int mostCommon = 0; // most common element
            int count = 0; // number of times most common element occurs
            int tempCommon = 0; // count certain number
            int tempCount = 0; // keep track of frequency
            for (int i = 0; i < nums.size(); i++) {
                if (nums.at(i) != mostCommon) { // skip if number is already most common
                    tempCommon = nums.at(i);
                    tempCount = 0; // set counter

                    for (int j = i; j < nums.size(); j++) { // second loop to count num of occurances in vector
                        if (tempCommon == nums.at(j)) { // add count 
                            tempCount++;
                        }
                    }
                    if (tempCount > count) { // change most common if tempCount is more then previous count
                        mostCommon = tempCommon;
                        count = tempCount;
                    }
                }
            }
            return mostCommon;
        }
};

int main() {
    srand(time(0));
    vector<int> vector; 
    Solution solute;
    
    int size = 100;
    for (int i = 0; i < size; i++) {
        int insert = rand() % (100 - 1 + + 1) + 1; // insert number between 1 and 10
        vector.push_back(insert);
    }
    int mostCommon = solute.majorityElement(vector);
    cout << "Most Common Number: " << mostCommon << endl;
    return 0;
}