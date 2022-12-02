class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        # left right都不知道 -> 遍历i in range(len(nums)) 固定right为i 讨论left的可能性即可
        l1, l2 = -1, -1
        res = 0
        for i in range(len(nums)):
            if nums[i] >= left and nums[i] <= right:
                l2 = i
            elif nums[i] > right:
                l1, l2 = i, -1

            if l2 != -1: # 存在这样的点
                res += l2 - l1

        return res