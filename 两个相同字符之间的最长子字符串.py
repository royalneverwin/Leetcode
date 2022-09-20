class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        std = 'abcdefghijklmnopqrstuvwxyz'
        cnt_dict = {}
        for i in std:
            cnt_dict[i] = -1
        res = -1
        for i in range(len(s)):
            if cnt_dict[s[i]] == -1:
                cnt_dict[s[i]] = i
            else:
                res = max(res, i - cnt_dict[s[i]]-1)

        return res
