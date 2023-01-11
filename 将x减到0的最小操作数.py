class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        # 逆向思维 不去找 = x 的最小的前后缀和
        # 而是去找 = sum-x的最长的子序列
        left, right = 0, 0
        cur = 0
        res = -1
        target = sum(nums) - x
        if target < 0:
            return -1
        if target == 0:
            return len(nums)
        while right < len(nums):
            while right < len(nums) and cur < target:
                cur += nums[right]
                right += 1
            if cur > target:
                while left < len(nums) and cur > target:
                    cur -= nums[left]
                    left += 1
            if cur == target:
                res = max(res, right-left)
                cur -= nums[left]
                left += 1

        return len(nums) - res if res != -1 else -1
        