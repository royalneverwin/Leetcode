class Solution:
    def countHomogenous(self, s: str) -> int:
        def f(n):
            return (1+n)*n//2

        res = 0
        idx1, idx2 = 0, 0
        while idx1 < len(s):
            while idx2 < len(s) and s[idx2] == s[idx1]:
                idx2 += 1
            l = idx2 - idx1
            res = (res + (1+l)*l//2) % (1000000000+7)
            idx1 = idx2

        return res



