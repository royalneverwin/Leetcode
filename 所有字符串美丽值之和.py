class Solution:
    def beautySum(self, s: str) -> int:
        n = len(s)
        res = 0
        for i in range(n):
            preSum = [0 for i in range(26)]
            cur_max = 0
            for j in range(i, n):
                cur_min = 1000
                idx = ord(s[j])-ord('a')
                preSum[idx] += 1
                cur_max = max(preSum[idx], cur_max)
                for k in range(26):
                    if preSum[k] != 0:
                        cur_min = min(cur_min, preSum[k])

                res += cur_max - cur_min

        return res
