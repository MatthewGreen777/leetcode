/*
leetcode problem #3: Longest Substring Without Repeating Charactrs

Given a string s, find the length of the longest substring without duplicate characters.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <unordered_set>


int lengthOfLongestSubstring(std::string s) {
    std::vector<int> index(128, -1);  // ASCII size
    int maxLength = 0;
    int start = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (index[s[i]] >= start) {
            start = index[s[i]] + 1;
        }
        index[s[i]] = i;
        maxLength = std::max(maxLength, i - start + 1);
    }

    return maxLength;
}

int main() {
    std::string test = "dvdf";
    int longest = lengthOfLongestSubstring(test);
    std::cout << longest;
    return 0;
}