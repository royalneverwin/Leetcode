class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        ans = list(prices)
        for i in range(len(prices)):
            for j in range(i+1, len(prices)):
                if prices[j] <= prices[i]:
                    ans[i] -= prices[j]
                    break

        return ans
