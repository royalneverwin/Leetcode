class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        # 用动态规划找到1以s1[i:]和s2[j:]为子序列的最短子序列长度
        # 注意不要直接记录str，对str的操作很费时间 要记录构造路径 dp完了根据路径得到ans
        m = len(str1)
        n = len(str2)
        # 一定不要[[]*n]*m ! python中对列表的*是浅拷贝，实际上都指向一个list！
        dp = [[0 for j in range(n+1)] for i in range(m+1)]
        ans = [[[0, 0] for j in range(n+1)] for i in range(m+1)] # ans[i][j][0]=1表示idx1+1, ans[i][j][1]=1表示idx2+1
        for i in range(m-1, -1, -1):
            dp[i][n] = m-i
            ans[i][n] = [1, 0]
        for j in range(n-1, -1, -1):
            dp[m][j] = n-j
            ans[m][j] = [0, 1]

        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if str1[i] == str2[j]:
                    dp[i][j] = dp[i+1][j+1]+1
                    ans[i][j] = [1, 1]
                else:
                    if dp[i+1][j] <= dp[i][j+1]:
                        dp[i][j] = dp[i+1][j]+1
                        ans[i][j] = [1, 0]
                    else:
                        dp[i][j] = dp[i][j+1]+1
                        ans[i][j] = [0, 1]

        idx1, idx2 = 0, 0
        res = ''
        while idx1 < m or idx2 < n:
            if ans[idx1][idx2][0] == 1 and ans[idx1][idx2][1] == 1:
                res += str1[idx1]
                idx1, idx2 = idx1+1, idx2+1
            elif ans[idx1][idx2][0] == 1:
                res += str1[idx1]
                idx1 += 1
            else:
                res += str2[idx2]
                idx2 += 1
        return res