class Solution:
    def fillCups(self, amount: List[int]) -> int:
        amount.sort()
        if amount[0]+amount[1] <= amount[2]:
            return amount[2]
        else:
            return (amount[0]+amount[1]+amount[2]+1) // 2
