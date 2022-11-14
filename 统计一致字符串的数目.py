class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        res = 0
        for word in words:
            flag = True
            for w in word:
                if w not in allowed:
                    flag = False
                    break
            if flag:
                res += 1
        return res

                    