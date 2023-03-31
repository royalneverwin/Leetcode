class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        # ax+by=1如果存在解x,y 等价于 gcd(a, b) = 1
        #「裴蜀定理」的内容为：对于不全为零的任意整数 a 和 b，记 g=gcd(a,b)，其中 gcd(a,b) 为 a 和 b 的最大公约数，
        # 则对于任意整数 x 和 y 都满足 a×x+b×y 是 g 的倍数，特别地，存在整数 x 和 y 满足 a×x+b×y=g。
        #「裴蜀定理」也可以推广到多个整数的情况。对于不全为零的任意 n 个整数 a1 ,a2 ,…an，记这 n 个数的最大公约数为
        # g，则对于任意 n 个整数 x1 ,x2 ,…xn 都满足 ∑ i=1 ^n ai×xi 是 g 的倍数。一个重要的推论是：正整数 a1 到
        # an 的最大公约数是 1 的充分必要条件是存在 n 个整数 x1  到 xn  满足 ∑ i=1 ^n ai×xi=1。

        return reduce(gcd, nums) == 1
