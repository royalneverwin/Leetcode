class Solution:
    def countVowelStrings(self, n: int) -> int:
        dp = [[0]*5 for i in range(n+1)]
        dp[1] = [1,1,1,1,1]
        for i in range(2, n+1):
            for j in range(5):
                dp[i][j] = sum(dp[i-1][j:])
        return sum(dp[n])

