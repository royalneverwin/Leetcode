class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        res = 0
        left, right = 0, 0
        for i in range(nums[0]-k, nums[-1]+k+1):
            while right < n and nums[right] - i <= k:
                right += 1
            while left < n and i - nums[left] > k:
                left += 1

            if right == n:
                res = max(right-left, res)
                break
                
            res = max(right-left, res)
        
        return res
        
        return ans
            
