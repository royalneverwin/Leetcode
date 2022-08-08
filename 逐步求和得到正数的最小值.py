class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        sum = 0
        minSum = 0
        for num in nums:
            sum += num
            minSum = min(minSum, sum)

        return 1-minSum