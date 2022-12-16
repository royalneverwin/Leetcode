class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        ls = [False] * 26
        for c in sentence:
            ls[ord(c)-ord('a')] = True
        for f in ls:
            if not f:
                return False
        return True