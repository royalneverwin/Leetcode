class Solution:
    def baseNeg2(self, n: int) -> str:
        if n == 0:
            return '0'
        ans = []
        while n != 0:
            if n % 2 == 1:
                n -= 1
                ans.insert(0, '1')
            else:
                ans.insert(0, '0')
            n //= -2

        return ''.join(ans)