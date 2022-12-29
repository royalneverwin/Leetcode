class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        # 可以二分查找结果
        # 判断哪一个res正好对应了maxOperations
        left, right = 1, max(nums)

        while left < right:
            middle = (left+right)//2
            cur_op = 0
            for num in nums:
                cur_op += (num-1)//middle

            if cur_op <= maxOperations:
                right = middle
            else:
                left = middle+1

        return left

