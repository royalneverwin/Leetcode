class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        return True if len(s1) == len(s2) and s1 in s2 * 2 else False