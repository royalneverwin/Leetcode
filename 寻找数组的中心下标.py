class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total = sum(nums)
        n = len(nums)
        cur_sum = 0
        for i in range(n):
            if cur_sum * 2 + nums[i] == total:
                return i
            
            cur_sum += nums[i]
        
        return -1


