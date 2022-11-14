class Solution:
    def numTilings(self, n: int) -> int:
        dp = [0 for i in range(n+1)]
        dp[1] = 1
        if n >= 2:
            dp[2] = 2
        if n >= 3:
            dp[3] = 5
        sum = 8

        for i in range(4, n+1):
            dp[i] = (sum * 2 - dp[i-1] - dp[i-2] + 2) % (1000000000+7)
            sum = (sum + dp[i]) % (1000000000+7)
        return dp[n]

