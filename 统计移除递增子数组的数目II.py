class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        n = len(nums)

        prev = None
        idx1 = 0
        while idx1 < n:
            if prev != None and prev >= nums[idx1]: # 最长的初始连续递增
                break
            prev = nums[idx1]
            idx1 += 1
        
        if idx1 == n: # 连续递增
            return n*(1+n)//2
        
        prev = None
        idx2 = n-1
        while idx2 >= 0:
            if prev != None and prev <= nums[idx2]: # 最长的末尾连续递增
                break
            prev = nums[idx2]
            idx2 -= 1
        
        # idx1 <= idx2
        res = 1 # 全移除
        # 只保留后面
        res += n-1-idx2

        x, y = 0, idx2+1
        while x < idx1:
            while y < n and nums[x] >= nums[y]:
                y += 1
            
            res += n-y+1
            
            x += 1
        
        return res




