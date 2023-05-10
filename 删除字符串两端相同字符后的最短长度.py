class Solution:
    def minimumLength(self, s: str) -> int:
        while True:
            n = len(s)
            if n == 1: # 只有一个
                return n
            idx1, idx2 = 1, n-1
            if s[0] != s[-1]:
                return n
            else:
                while idx1 < n and s[idx1] == s[idx1-1]:
                    idx1 += 1
                while idx2 > 0 and s[idx2-1] == s[idx2]:
                    idx2 -= 1

                if idx1 > idx2:
                    return 0
                else:
                    s = s[idx1:idx2]


