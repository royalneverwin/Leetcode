class Solution:
    def countAlternatingSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0

        if n == 1:
            return 1
        
        idx1, idx2 = 0, 1
        while idx1 < n:
            while idx2 < n and nums[idx2] != nums[idx2-1]:
                idx2 += 1
        
            # idx1 ~ idx2-1
            cnt = idx2-idx1
            res += (1+cnt)*cnt//2
            idx1, idx2 = idx2, idx2+1
        
        return res

        
