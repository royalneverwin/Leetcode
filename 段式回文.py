class Solution:
    def longestDecomposition(self, text: str) -> int:
        n = len(text)
        if text == '':
            return 0
        res = 1
        for i in range(1, n//2+1):
            if text[:i] == text[n-i:]:
                res = 2+self.longestDecomposition(text[i:n-i])
                break

        return res