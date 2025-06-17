/*
leetcode problem #380: Insert Delete GetRandom O(1)

Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true 
if the item was not present, false otherwise.

bool remove(int val) Removes an item val from the set if present. Returns true if 
the item was present, false otherwise.

int getRandom() Returns a random element from the current set of elements 
(it's guaranteed that at least one element exists when this method is called). 
Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works 
in average O(1) time complexity.
*/

#include <iostream>
#include<unordered_map>
#include <vector>

class RandomizedSet {
    std::unordered_map<int, int> set;
    std::vector<int> contains;

public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (set.find(val) != set.end()) {
            return false;
        }
        contains.push_back(val);
        set[val] = contains.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (set.find(val) == set.end()) {
            return false;
        }
        int index = set[val];
        int last = contains.back();

        contains[index] = last;
        set[last] = index;

        contains.pop_back();
        set.erase(val);

        return true;
    }
    
    int getRandom() {
        int get = rand() % contains.size();
        return contains.at(get);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */