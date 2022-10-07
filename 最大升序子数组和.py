class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        res = nums[0]
        cur_sum = nums[0]
        idx = 1
        while idx < len(nums):
            if nums[idx] > nums[idx-1]:
                cur_sum += nums[idx]
            else:
                res = max(cur_sum, res)
                cur_sum = nums[idx]
            idx += 1

        return max(res, cur_sum)