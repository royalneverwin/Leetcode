class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        MOD = int(1e9+7)
        dp = [[0 for j in range(6)] for i in range(n+1)] # dp[i][j]表示目前是第i步，且最后一步是数字j的次数
        for i in range(6):
            dp[1][i] = 1

        for i in range(2, n+1):
            for j in range(6):
                for k in range(6):
                    if k != j: # 不可能连续 一定可以有
                        dp[i][j] += dp[i-1][k]
                if rollMax[j] >= i: # 无论前面有几个j都可以
                    dp[i][j] += dp[i-1][j]
                else: # 减去连续个j的情况
                    dp[i][j] += dp[i-1][j]
                    if i-rollMax[j] == 1:
                        dp[i][j] -= dp[i-rollMax[j]][j] # 直接算第一
                    else: # 累加算第一
                        for k in range(6):
                            if k != j:
                                dp[i][j] -= dp[i-rollMax[j]-1][k]
                dp[i][j] %= MOD
        return sum(dp[n])%MOD


