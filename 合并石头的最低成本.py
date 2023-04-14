class Solution:
    def mergeStones(self, stones: List[int], k: int) -> int:
        # unable to handle 看题解了。。。
        n = len(stones)
        if (n-1) % (k-1) != 0:
            return -1

        dp = [[[-1 for i in range(k+1)] for j in range(n)] for l in range(n)]
        preSum = [0 for i in range(n+1)]
        for i in range(n):
            preSum[i+1] = preSum[i] + stones[i]
        for i in range(n):
            dp[i][i][1] = 0

        @cache
        def dfs(l, r, t):
            nonlocal dp
            nonlocal preSum
            nonlocal k
            if dp[l][r][t] != -1: # dfs过
                return dp[l][r][t]

            if r-l+1 < t: # 不成立
                return -1

            if t == 1: # t=1的递归方程
                val = dfs(l, r, k)
                if val == -1:
                    return -1
                dp[l][r][t] = val + (preSum[r+1]-preSum[l])
                return dp[l][r][t]

            # t!=1的递归方程
            val = 1e9
            for p in range(l, r, k-1):
                val1 = dfs(l, p, 1)
                val2 = dfs(p+1, r, t-1)
                if val1 == -1 or val2 == -1:
                    continue
                else:
                    val = min(val, dfs(l, p, 1) + dfs(p+1, r, t-1))
            if val == 1e9:
                val = -1

            dp[l][r][t] = val
            return val

        return dfs(0, n-1, 1)









