class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        if n == 1:
            return 0
        else:
            if k % 2 == 0:
                return 0 if self.kthGrammar(n-1, k // 2) else 1
            else:
                return self.kthGrammar(n-1, (k+1) // 2)