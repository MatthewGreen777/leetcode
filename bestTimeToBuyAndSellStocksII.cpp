// leetcode problem #122: Best Time to Buy and Sell Stocks II

/*
You are given an integer array prices where prices[i] is the 
price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. 
You can only hold at most one share of the stock at any time. 
However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int profit = 0; // profit
            int lowest = prices.at(0); // track highest price in vector
            int index = 0; // keep track of index of lowest
            int highest = prices.at(0); // track highest price in vector
            int index2 = 0; // keep track of index of highest
            for (int i = 0; i < prices.size(); i++) { // loop through vector
                if (prices.at(i) < lowest) { // lower price
                    lowest = prices.at(i);
                    index = i;
                } else if ((prices.at(i) > highest) || (index > index2)) { // higher price or index, buy date, is head of index2, sell date
                    highest = prices.at(i);
                    index2 = i;
                }
                if (index2 > index) { // see if profit needs to be changed, buy and sell date change
                    profit = profit + highest - lowest;
                    highest = prices.at(i);
                    lowest = prices.at(i);
                }
            }
            return profit;
        }
};

int main() {
    srand(time(0));
    vector<int> vector; 
    Solution solute;
    
    int size = 3;
    for (int i = 0; i < size; i++) {
        int insert = rand() % (100 - 1 + + 1) + 1; // insert number between 1 and 10
        vector.push_back(insert);
    }
    cout << "Contents of Vector: ";
    for (int i = 0; i < vector.size(); i++) {
        if (i == vector.size() - 1) {
            cout << vector.at(i) << endl;
        } else {
            cout << vector.at(i) << ", ";
        }
    }
    int profit = solute.maxProfit(vector);
    cout << "Max Profit Oppurtunity: " << profit << endl;
    return 0;
}