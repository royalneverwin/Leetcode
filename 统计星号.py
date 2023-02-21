class Solution:
    def countAsterisks(self, s: str) -> int:
        flag = False
        res = 0
        for c in s:
            if c == '|':
                if flag == False:
                    flag = True
                else:
                    flag = False

            elif c == '*':
                if flag == False:
                    res += 1

        return res