/*
leetcode problem #7: Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range 
[-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


*/

#include <iostream>
#include <math.h>

int reverse(int x) {
    int answer = 0;
    if (x > 0) {
        while (x > 0) {
        if (answer > std::numeric_limits<int>::max() / 10) {
            return 0; // Overflow detected, return 0 as specified
        }

        if (answer == std::numeric_limits<int>::max() / 10 && x > std::numeric_limits<int>::max() % 10) {
            return 0; // Overflow detected, return 0 as specified
        }
            answer = answer * 10 + x % 10;
            x = x / 10;
        }
    } else {
        while (x < 0) {
        if (answer < std::numeric_limits<int>::min() / 10) {
            return 0; // Overflow detected, return 0 as specified
        }

        if (answer == std::numeric_limits<int>::min() / 10 && x < std::numeric_limits<int>::min() % 10) {
            return 0; // Overflow detected, return 0 as specified
        }
            answer = answer * 10 + x % 10;
            x = x / 10;
        }
    }
    return answer;

}