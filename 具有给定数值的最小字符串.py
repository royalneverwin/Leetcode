class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        if k == n:
            return 'a' * n
        elif n == 1:
            return chr(ord('a')+k-1)

        else:
            if k > 26 + n - 1:
                return self.getSmallestString(n-1, k-26) + 'z'
            else:
                return 'a' * (n-1) + chr(ord('a')+k-n)