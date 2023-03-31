class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[0 for j in range(n)] for i in range(m)]
        if m == 1:
            return sum(grid[0])
        if n == 1:
            cur_sum = 0
            for i in range(m):
                cur_sum += grid[i][0]
            return cur_sum

        dp[m-1][n-1] = grid[m-1][n-1]
        for j in range(n-2, -1, -1):
            dp[m-1][j] = dp[m-1][j+1] + grid[m-1][j]
        for i in range(m-2, -1, -1):
            dp[i][n-1] = dp[i+1][n-1] + grid[i][n-1]

        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]) + grid[i][j]

        return dp[0][0]