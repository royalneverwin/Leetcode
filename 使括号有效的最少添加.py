class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        cnt = 0
        res = 0
        for c in s:
            if c == '(':
                cnt += 1
            else:
                if cnt == 0:
                    res += 1
                else:
                    cnt -= 1

        return res + cnt