// leetcode problem #88: Merge Sorted Array

/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and 
two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored 
inside the array nums1. To accommodate this, nums1 has a length of m + n, where the 
first m elements denote the elements that should be merged, and the last n elements 
are set to 0 and should be ignored. nums2 has a length of n
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <time.h>
using namespace std;

class Solution {
public:
    // merge function to merge the two array
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // trackers, set to end of vectors
        int i=m-1; // this is the last element of vector num1 that is not 0
        int j=n-1; // this is the last element of vecotr num2
        int k=m+n-1; // this is the last position of vector num1
        // loop through vectors while
        while(i>=0 && j>=0){ // elements are added to num1 vector from right to left, greatest to least
            if (nums1[i]>nums2[j]) { // element i in vector 1 i > element j in vector 2
                nums1[k]=nums1[i]; // element position k in vector num1 is set to value of element in position i of vector num1
                i--; // decrement tracker
                k--; // decrement tracker
            }
            else{ // elemnt j in vector 2 > element i in vector 1
                nums1[k]=nums2[j]; //  element position k in vector num1 is set to value of element in position j of vector num2
                j--; // decrement tracker
                k--; // decrement tracker
            }
        }
        // loop through remaining elements of vector num2, would happen if all elements of num1 are > then element j in num2 or if num1 is empty
        while(j>=0){ 
            nums1[k]=nums2[j];
            j--;
            k--;
        }
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
    vector<int> one;
    vector<int> two;
    Solution solute;
    int size = 10;
    for (int i = 0; i < size; i++) { // add 10 elements to each vector
        int insert = rand() % (100 - 1 + 1) + 1;
        one.push_back(insert);
        insert = rand() % (100 - 1 + 1) + 1;
        two.push_back(insert);
    }
    solute.sort(one); // sort the vectors
    solute.sort(two);

    cout << "Vector One: "; // output both the vectors
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            cout << one.at(i) << endl;
        } else {
            cout << one.at(i) << ", ";
        }
    }

    cout << "Vector Two: ";
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            cout << two.at(i) << endl;
        } else {
            cout << two.at(i) << ", ";
        }
    }

    for (int i = 0; i < size; i++) { // add size of vector 2 elements to vector 1 as 0's
        one.push_back(0);
    }
    
    cout << "Merged Vector: "; // merge vectors
    solute.merge(one, size, two, size); // output merge
    for (int i = 0; i < one.size(); i++) {
        if (i == one.size() - 1) {
            cout << one.at(i) << endl;;
        } else {
            cout << one.at(i) << ", ";
        }
    }
    return 0;
}