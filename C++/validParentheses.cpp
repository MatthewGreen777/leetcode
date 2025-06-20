/*
leetcode problem #20: Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sol;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                sol.push(s[i]);
            } else {
                if (sol.empty()) return false;
                char top = sol.top();
                if (s[i] == ')' && top != '(') return false;
                if (s[i] == '}' && top != '{') return false;
                if (s[i] == ']' && top != '[') return false;
                sol.pop();
            }
        }
        return sol.empty();
    }
};