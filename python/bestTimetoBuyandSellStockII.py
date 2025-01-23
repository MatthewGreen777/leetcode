# Leetcode problem #122

"""
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share 
of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
"""

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        # Declare helper variable
        profit = 0
        lowest = prices[0]
        index = 0
        highest = prices[0]
        index2 = 0
        
        # Go through list
        for i in range(len(prices)):
            #  Buy if price is lower then previous day
            if prices[i] < lowest:
                lowest = prices[i]
                index = i
            # Change high price if needed
            elif prices[i] > highest or index > index2:
                highest = prices[i]
                index2 = i

            # Sell and calculate profit if index2 has higher price
            if index2 > index:
                profit = profit + highest - lowest
                highest = prices[i]
                lowest = prices[i]

        return profit