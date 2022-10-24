class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        idx1, idx2 = 0, 0
        res = 0
        while idx1 < len(s):
            if s[idx1] == '(':
                cnt = 1
                idx2 = idx1+1
                while cnt != 0:
                    if s[idx2] == ')':
                        cnt -= 1
                    else:
                        cnt += 1
                    idx2 += 1

                idx2 -= 1
                if idx2 == idx1+1:
                    res += 1
                else:
                    res += 2 * self.scoreOfParentheses(s[idx1+1:idx2])

                idx1 = idx2+1
            else:
                print("Wrong")

        return res