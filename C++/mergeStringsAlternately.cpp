// problem #1768

/*
You are given two strings word1 and word2. Merge the strings by adding letters 
in alternating order, starting with word1. If a string is longer than 
the other, append the additional letters onto the end of the merged string.

Return the merged string.
*/

#include <iostream> 
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int length = 0;
        while ((length < word1.size()) || (length < word2.size())) {
            if (length < word1.size()) {
                result.push_back(word1.at(length));
            }

            if (length < word2.size()) {
                result.push_back(word2.at(length));
            }
            length++;
        }
        return result;
    }
};

int main() {
    Solution done;
    string name = "Math";
    string name2 = "Bio";
    //MBaitoh
    string name3 = done.mergeAlternately(name, name2);
    cout << name3 << endl;
    return 0;
}