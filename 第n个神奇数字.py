class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        # 容斥原理
        # 二分搜素
        c = a * b // gcd(a, b)
        left, right = 0, n * a
        while left < right:
            middle = (left + right) // 2
            idx = middle // a + middle // b - middle // c
            if idx == n:
                if middle % a and middle % b: # 要保证能整除
                    sub = min(middle%a, middle%b)
                    return (middle - sub) % 1000000007
                return middle % 1000000007
            elif idx > n:
                right = middle
            else:
                left = middle+1

        return left % 1000000007

