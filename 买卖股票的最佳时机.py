class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        cur_max = 0
        res = 0
        for i in range(len(prices)-1, -1, -1):
            cur_max = max(cur_max, prices[i])
            res = max(cur_max-prices[i], res)
        return res
            