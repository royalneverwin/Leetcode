class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        la = len(a)
        lb = len(b)
        if la > lb:
            return la
        elif la < lb:
            return lb
        elif a == b:
            return -1
        else:
            return la
