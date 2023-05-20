class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        res = -1
        for i in nums:
            if i > 0:
                if -i in nums:
                    res = max(res, i)
        return res