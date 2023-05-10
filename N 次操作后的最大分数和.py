class Solution:
    def maxScore(self, nums: List[int]) -> int:
        n = len(nums)
        status = 0
        for i in range(n):
            status |= (1<<i)

        @cache
        def dp(status, idx):
            nonlocal n
            nonlocal nums
            res = 0
            for i in range(n):
                for j in range(i+1, n):
                    if status & (1<<i) and status & (1<<j): # 存在这两个数
                        new_status = status ^ (1<<i) ^ (1<<j)
                        res = max(res, idx*gcd(nums[i], nums[j])+dp(new_status, idx+1))
            return res

        return dp(status, 1)

