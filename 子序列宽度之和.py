class Solution:
    def sumSubseqWidths(self, nums: List[int]) -> int:
        # 求所有最大数和 - 最小数和
        nums.sort()
        res, n = 0, len(nums)
        cur_pow = pow(2, n-1)
        for i in range(n):
            res = (res + (nums[n-i-1] - nums[i]) * cur_pow) % (1000000000+7)
            cur_pow //= 2
        return res
