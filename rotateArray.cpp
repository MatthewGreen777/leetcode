// leetcode problem #189: Rotate Array

/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            vector<int> copy = nums; // create a copy vector
            for (int i = 0; i < nums.size(); i++) { 
                if ((i + k) >= nums.size()) { // wrap around
                    int wrap = i + k;
                    while (wrap >= nums.size()) { // get back to valid number
                        wrap = wrap - nums.size();
                    }
                    nums.at(wrap) = copy.at(i);
                } else { // rotate value
                    nums.at(i + k) = copy.at(i);
                }
            }
        }
};

int main() {    
    srand(time(0));
    vector<int> vector; 
    Solution solute;
    
    int size = 10;
    for (int i = 0; i < size; i++) {
        int insert = rand() % (100 - 1 + + 1) + 1; // insert number between 1 and 10
        vector.push_back(insert);
    }
    cout << "Vector Before Rotation: ";
    for (int i = 0; i < vector.size(); i++) {
        if (i == vector.size() - 1) {
            cout << vector.at(i) << endl;
        } else {
            cout << vector.at(i) << ", ";
        }
    }
    solute.rotate(vector, 3);
    cout << "Vector After Rotation: ";
    for (int i = 0; i < vector.size(); i++) {
        if (i == vector.size() - 1) {
            cout << vector.at(i) << endl;
        } else {
            cout << vector.at(i) << ", ";
        }
    }

    return 0;
}