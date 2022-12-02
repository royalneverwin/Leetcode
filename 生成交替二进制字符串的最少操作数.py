class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)
        s = list(s)
        res1, res2 = 0, 1
        prev1 = s[0]
        for i in range(1, n):
            if prev1 == '1':
                if s[i] == '0':
                    res2 += 1
                else:
                    res1 += 1
                prev1 = '0'
            else:
                if s[i] == '0':
                    res1 += 1
                else:
                    res2 += 1
                prev1 = '1'
        return min(res1, res2)



            