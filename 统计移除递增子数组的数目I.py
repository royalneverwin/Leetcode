class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        n = len(nums)
        res = 1 # 空也是递增

        # 空数组不是
        
        for l in range(1, n):
            for j in range(n-l+1):
                cur = None
                flag = True
                for i in range(n):
                    if i >= j and i < j+l:
                        continue
                    
                    elif cur == None:
                        cur = nums[i]
                    
                    elif cur < nums[i]:
                        cur = nums[i]
                    
                    else:
                        flag = False
                        break
                
                if flag:
                    res += 1

        return res
            
