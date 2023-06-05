class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(n-1):
            if nums[i] == nums[i+1]:
                nums[i] = 2*nums[i]
                nums[i+1] = 0

        cnt = 0
        res = []
        for i in range(n):
            if nums[i] == 0:
                cnt += 1
            else:
                res.append(nums[i])

        res += [0] * cnt
        return res