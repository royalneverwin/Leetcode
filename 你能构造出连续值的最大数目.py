class Solution:
    def getMaximumConsecutive(self, coins: List[int]) -> int:
        coins.sort()
        cur = 0
        idx = 0
        n = len(coins)
        while True:
            if idx < n and coins[idx] <= cur+1:
                cur = cur + coins[idx]
                idx += 1
            else:
                return cur+1

