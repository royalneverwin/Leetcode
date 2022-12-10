class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        check = set()
        flag = False
        cur = 0
        for w in word:
            if w >= 'a' and w <= 'z':
                if flag:
                    check.add(cur)
                    cur = 0
                    flag = False

            else:
                cur = cur * 10 + int(w)
                flag = True

        if flag:
            check.add(cur)
        return len(check)
