class Solution:
    def countEven(self, num: int) -> int:
        def func(a):
            res = 0
            while a > 0:
                res += a % 10
                a = a // 10
            return res

        res = 0
        for i in range(1, num+1):
            if func(i) % 2 == 0:
                res += 1

        return res

