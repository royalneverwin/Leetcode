class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        n = len(values)
        # dp[i][j]表示从第i个开始连续j个组成的多边形的最低分
        dp = [[0 for i in range(n+1)] for j in range(n)]
        # 初始值
        for i in range(n):

            dp[i][3] = values[i]*values[(i+1)%n]*values[(i+2)%n]

        # 注意l和i顺序
        for l in range(4, n+1):
            for i in range(n):
                val = 1e9
                for mid in range(i+1, i+l-1):
                    val = min(val, dp[i][mid-i+1] + \
                              values[i]*values[mid%n]*values[(i+l-1)%n] + \
                              dp[mid%n][i+l-mid])
                dp[i][l] = val

        return dp[0][n]


