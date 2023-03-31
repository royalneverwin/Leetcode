class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:

        n = len(nums)
        if n == 1:
            return 0
        # 偶数更大
        res1 = 0
        for i in range(n):
            if i % 2 != 0:
                if i != n-1:
                    min_one = min(nums[i-1], nums[i+1])
                else:
                    min_one = nums[i-1]
                res1 += max(0, nums[i]-min_one+1)

        # 奇数更大
        res2 = 0
        for i in range(n):
            if i % 2 == 0:
                if i == 0:
                    min_one = nums[i+1]
                elif i == n-1:
                    min_one = nums[i-1]
                else:
                    min_one = min(nums[i-1], nums[i+1])
                res2 += max(0, nums[i]-min_one+1)
        return min(res1, res2)