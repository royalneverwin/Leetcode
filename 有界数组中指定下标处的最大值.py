class Solution:
    def maxValue(self, n: int, index: int, maxSum: int) -> int:
        def cal(cnt):
            nonlocal n, index
            res = cnt
            # left side
            if cnt-index >= 1:
                res += ((cnt-index)+(cnt-1)) * index // 2
            else:
                res += index - (cnt-1)
                res += (1+cnt-1) * (cnt-1) // 2

            # right side
            if cnt-(n-index-1) >= 1:
                res += (cnt-(n-index-1)+(cnt-1)) * (n-index-1) // 2
            else:
                res += (n-index-1) - (cnt-1)
                res += (1+cnt-1) * (cnt-1) // 2

            return res


        # nums[i]正整数 所以要二分
        left, right = 1, maxSum
        while left < right:
            mid = (left+right) // 2
            if cal(mid) <= maxSum:
                if left == mid:
                    if cal(right) <= maxSum:
                        return right
                    else:
                        return left
                else:
                    left = mid
            else:
                right = mid-1

        return left