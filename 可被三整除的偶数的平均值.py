class Solution:
    def averageValue(self, nums: List[int]) -> int:
        total = 0
        cnt = 0
        for c in nums:
            if c % 2 == 0 and c % 3 == 0:
                total += c
                cnt += 1

        return total // cnt if cnt != 0 else 0
