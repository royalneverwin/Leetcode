class Solution:
    def numTimesAllBlue(self, flips: List[int]) -> int:
        n = len(flips)
        flags = [0] * n
        idx = 0
        res = 0
        for i in range(n):
            flags[flips[i]-1] = 1
            while idx < n and flags[idx] == 1:
                idx += 1
            if idx == i+1:
                res += 1

        return res

            