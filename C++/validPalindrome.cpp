/*
leetcode problem #125: Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters 
into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome(std::string s) {
    bool palindrome = true;
    std::string noSpace = "";
    for (int i = 0; i < s.length(); i++) {
        if (std::isalnum(s.at(i))) {
            noSpace += std::tolower(s.at(i));
        }
    }
    
    int one = 0;
    int two = noSpace.length() - 1;
    
    while (one < two) {
        if (noSpace.at(one) != noSpace.at(two)) {
            return false;
        }
        one++;
        two--;
    }
    return palindrome;
}

int main() {
    std::string test = "A man, a plan, a canal: Panama";
    std::cout << isPalindrome(test);
    return 0;
}