class Solution:
    #设 n 是一个十进制的 k 位数，所有数字位数小于 k 且由 digits 组成的数字则一定是小于 n 的。
    #我们用 dp[i][0] 表示由 digits 构成且小于 n 的前 i 位的数字的个数，
    #dp[i][1] 表示由 digits 构成且等于 n 的前 i 位的数字的个数，可知 dp[i][1] 的取值只能为 0 和 1。
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        str_n = str(n)
        dp = [[0, 0] for i in range(len(str_n))]
        # 边界
        for digit in digits:
            if digit < str_n[0]:
                dp[0][0] += 1
            elif digit == str_n[0]:
                dp[0][1] += 1
                break
            else:
                break

        for i in range(1, len(str_n)):
            cnt = 0
            flag = 0
            for digit in digits:
                if digit < str_n[i]:
                    cnt += 1
                elif digit == str_n[i]:
                    flag = 1
                    break
                else:
                    break
            dp[i][0] = len(digits) + dp[i-1][0]*len(digits) + dp[i-1][1]*cnt
            dp[i][1] = dp[i-1][1] * flag

        return dp[len(str_n)-1][0] + dp[len(str_n)-1][1]