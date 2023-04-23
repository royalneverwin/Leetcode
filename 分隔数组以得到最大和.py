class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        # 动归
        n = len(arr)
        dp = [0 for i in range(n)]
        cur_max = 0
        for i in range(k):
            cur_max = max(cur_max, arr[i])
            dp[i] = cur_max * (i+1)

        for i in range(k, n):
            cur_max = 0
            for j in range(1, k+1):
                cur_max = max(cur_max, arr[i-j+1])
                dp[i] = max(cur_max * j + dp[i-j], dp[i])

        return dp[n-1]

