class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        idx1, idx2 = 0, 0
        word1 = list(word1)
        word2 = list(word2)
        res = ''
        while idx1 < len(word1) and idx2 < len(word2):
            res += word1[idx1]
            res += word2[idx2]
            idx1, idx2 = idx1+1, idx2+1

        while idx1 < len(word1):
            res += word1[idx1]
            idx1 += 1

        while idx2 < len(word2):
            res += word2[idx2]
            idx2 += 1

        return res