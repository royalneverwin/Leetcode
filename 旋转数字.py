class Solution:
    def rotatedDigits(self, n: int) -> int:
        dp = [-1 for i in range(10001)] #-1表明没有旋转有效数字
        dp[0] = 0
        dp[1] = 1
        dp[2] = 5
        dp[5] = 2
        dp[6] = 9
        dp[8] = 8
        dp[9] = 6
        res = 0
        for i in range(1, n+1):
            if i <= 9:
                if dp[i] != -1 and dp[i] != i:
                    res += 1
            else:
                tmp1 = i // 10
                tmp2 = i % 10
                if dp[tmp1] != -1 and dp[tmp2] != -1:
                    dp[i] = dp[tmp1] * 10 + dp[tmp2]
                    if dp[tmp1] == tmp1:
                        if dp[tmp2] != tmp2:
                            res += 1
                    else:
                        res += 1

        return res