class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort()
        standard = sum(nums) / 2
        ans = []
        total = 0
        idx = -1
        while total <= standard:
            total += nums[idx]
            ans.append(nums[idx])
            idx -= 1
        return ans