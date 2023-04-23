class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[1 for i in range(1002)] for j in range(n)]
        for i in range(1, n):
            for j in range(i):
                dp[i][nums[i]-nums[j]+500] = dp[j][nums[i]-nums[j]+500]+1
        return max([max(dp[i]) for i in range(n)])
            