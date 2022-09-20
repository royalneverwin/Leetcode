class Solution:
    def preimageSizeFZF(self, k: int) -> int:
        # 2*5 = 10 且2的个数一定>5 所以只要计算5的个数即可
        # 计算5的个数可以用x // 5得到: 是1到x中5的因子的个数之和
        # 有x // 5个数字有1个5 有 x // 25个数字有2个5 以此类推
        # 所以total = sum x // 5**i (i = 1, 2, ...)
        # 由于k很大 我们用二分法
        def f(n):
            res = 0
            while n >= 5:
                n //= 5
                res += n
            return res

        def n(k):
            return bisect_left(range(5 * k), k, key = f)

        return n(k+1) - n(k)