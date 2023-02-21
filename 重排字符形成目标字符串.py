class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        cnt1 = [0 for i in range(26)]
        cnt2 = [0 for i in range(26)]
        for c in s:
            cnt1[ord(c) - ord('a')] += 1

        for c in target:
            cnt2[ord(c) - ord('a')] += 1

        res = 10000
        for c in target:
            res = min(res, cnt1[ord(c)-ord('a')] // cnt2[ord(c)-ord('a')])

        return res


        