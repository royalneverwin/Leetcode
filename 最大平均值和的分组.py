class Solution:
    def largestSumOfAverages(self, nums: List[int], k: int) -> float:
        # 遍历就可以
        # 如何快速得到子数组和？用前缀和
        n = len(nums)
        preSum = [0 for i in range(n)]
        sum = 0
        for i in range(n):
            sum += nums[i]
            preSum[i] = sum

        dp = [[0.0 for i in range(k+1)] for i in range(n+1)]
        for i in range(1, n+1):
            dp[i][1] = preSum[i-1] / i
        for i in range(2, n+1):
            for j in range(2, min(i, k)+1):
                cur_max = 0

                for l in range(j-1, i):
                    cur_max = max(cur_max, dp[l][j-1] + (preSum[i-1]-preSum[l-1]) / (i-l))
                dp[i][j] = cur_max

        return dp[n][k]

