class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        res = 0
        words = word
        while True:
            if words in sequence:
                res += 1
                words += word
            else:
                break
        return res
