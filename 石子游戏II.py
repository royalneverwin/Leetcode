class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        # 动态规划
        n = len(piles)
        if n == 1:
            return piles[0]

        dp = [[0 for j in range(n+1)] for i in range(n)] # dp[i][j]表述后i堆，m=j第一个最多能拿多少
        pre_sum = [0 for i in range(n)]
        cur_sum = 0
        for i in range(n):
            cur_sum += piles[i]
            pre_sum[i] = cur_sum

        def GET(i, M):
            nonlocal dp
            nonlocal n
            if i >= n:
                return 0
            M = min(M, (n-i+1)//2)
            return dp[i][M]

        for j in range(1, n+1):
            dp[n-1][j] = piles[n-1]
            dp[n-2][j] = piles[n-1]+piles[n-2]

        for i in range(n-3, -1, -1):
            left = n-i
            if i != 0:
                cur_sum = pre_sum[n-1] - pre_sum[i-1]
            else:
                cur_sum = pre_sum[n-1]
            for j in range(1, (left+1)//2+1):
                cur_max = 0
                for k in range(1, 2*j+1):
                    cur_max = max(cur_max, cur_sum-GET(i+k, max(j, k)))
                dp[i][j] = cur_max

        return dp[0][1]