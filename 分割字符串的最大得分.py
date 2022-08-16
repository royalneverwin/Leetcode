class Solution:
    def maxScore(self, s: str) -> int:
        ret = 0
        right = 0
        for i in s:
            if i == '1':
                right += 1
        left = 0
        idx = 0
        while idx < len(s)-1:
            if s[idx] == '0':
                left += 1
            else:
                right -= 1
            ret = max(ret, left + right)
            idx += 1
        return ret