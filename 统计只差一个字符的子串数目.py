class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        # 找到s和t不同
        m = len(s)
        n = len(t)
        res = 0
        for idx1 in range(m):
            for idx2 in range(n):
                diff = 0
                idx = 0
                while idx1+idx < m and idx2+idx < n:
                    if s[idx1+idx] == t[idx2+idx]:
                        if diff == 1:
                            res += 1
                        idx += 1
                    else:
                        diff += 1
                        if diff == 2:
                            break
                        idx += 1
                        res += 1
        return res


