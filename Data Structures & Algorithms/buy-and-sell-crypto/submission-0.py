class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        i = 0
        j = 1
        while(j < len(prices)):
            if  prices[j] < prices[i]:
                i = j
            profit = max(profit, prices[j] - prices[i])
            j+=1
        return profit