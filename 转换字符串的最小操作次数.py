class Solution:
    def minimumMoves(self, s: str) -> int:
        idx = 0
        res = 0
        while idx < len(s):
            if s[idx] == 'X':
                res += 1
                idx += 3
            else:
                idx += 1

        return res