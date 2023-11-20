// leetcode problem #55: Jump Game

/*
You are given an integer array nums. You are initially 
positioned at the array's first index, and each element 
in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/

// Solution provided is O(n^2)

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool finish = false; // flag
        int curr = 0; // tracker
        if (nums.size() == 1) { // only one element
            finish = true;
        }
        while (curr < nums.size() - 1 && nums.at(curr) != 0) { // loop while not at end or while current index is not 0
            if (nums.at(curr) > 1) { // can jump more then one space
                int jump = nums.at(curr); // how many spaced to jump
                int netPosition = 0; // sees if jumping to an earlier allows for more possibities on next jump
                if (nums.at(curr) + curr >= nums.size() - 1) { // jump goes out
                    jump = nums.at(curr); 
                } else { // jump stays in bounds
                    for (int i = 0; i < nums.at(curr); i++) { // find which jump space will give largest range for next move
                        if (netPosition < nums.at(curr + nums.at(curr) - i) - i) {  // next jump has larger potential next move
                            jump = nums.at(curr) - i;
                            netPosition = nums.at(curr + nums.at(curr) - i) - i;
                        }
                        
                    }
                }
                curr = curr + jump;
            } else { // jumps one space
                curr = curr + nums.at(curr);
            }
            if (curr >= nums.size() - 1) { // check if at end
                finish = true;
            }
        }
        return finish;
    }
};

int main() {
    srand(time(0)); 
    vector<int> one;
    Solution solute;
    int size = 5;
    for (int i = 0; i < size; i++) { // add 10 elements to each vector
        int insert = rand() % (10 - 1 + 1);
        one.push_back(insert);
    }
    cout << "Vector: "; // output both the vectors
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            cout << one.at(i) << endl;
        } else {
            cout << one.at(i) << ", ";
        }
    }
    cout << solute.canJump(one);
    return 0;
}