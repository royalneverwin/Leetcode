class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        # 动态规划
        # 把jobDifficulty划分成d份，看哪种划分sum difficulty最小
        # dp[i][j]表示i是最后一个cut的位置（也就是从i开始给剩下的cut），j是还剩下多少cut
        n = len(jobDifficulty)
        # dp = [[0 for i in range(d+1)] for j in range(n)]
        @cache
        def dp(i, j):
            nonlocal n
            nonlocal jobDifficulty
            nonlocal d
            if n-i == j: # 正好一天一个
                return sum(jobDifficulty[i:])

            if j == 1: # 只能全部完成了
                return max(jobDifficulty[i:])
            # 看今天可以完成几个，至少完成一个
            res = 301*1001
            cur_max = 0
            for idx in range(i, n-j+1):
                cur_max = max(cur_max, jobDifficulty[idx])
                res = min(res, cur_max+dp(idx+1, j-1))

            return res

        if n < d:
            return -1

        return dp(0, d)
