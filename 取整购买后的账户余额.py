class Solution:
    def accountBalanceAfterPurchase(self, purchaseAmount: int) -> int:
        res = 0
        dis = purchaseAmount
        while res < purchaseAmount:
            res += 10
        
        if purchaseAmount-(res-10) < res-purchaseAmount:
            return 100-(res-10)
        else:
            return 100-res
