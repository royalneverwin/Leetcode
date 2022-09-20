class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        prev = 0
        for i in range(len(nums)):
            x = len(nums) - i
            if x > prev and x <= nums[i]:
                return x
            prev = nums[i]
        return -1