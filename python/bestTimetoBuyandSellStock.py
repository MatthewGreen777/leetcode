# Leetcode Problem #121 Best Time to Buy and Sell Stock

"""
You are given an array prices where prices[i] is the price of a 
given stock on the ith day.

You want to maximize your profit by choosing a single day to buy 
one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.
"""

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # profit keeps track of profit, index keeps track of lowest price index
        # index2 keeps track of index of highest price ]
        profit = 0
        lowest = prices[0]
        index = 0
        highest = prices[0]
        index2 = 0
        for i in range(len(prices)):
            if prices[i] < lowest:
                lowest = prices[i]
                index = i
            elif prices[i] > highest or index > index2:
                highest = prices[i]
                index2 = i
            if (profit < (highest - lowest)) and (index2 > index):
                profit = highest - lowest
        return profit

solution = Solution()

array = [2,1,2,0,1]

result = solution.maxProfit(array)
print(result)