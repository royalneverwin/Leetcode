class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        import numpy as np

        n = len(nums)
        array = np.array(nums)
        idx = np.argmax(array)

        stack = []
        res = [0 for i in range(n)]

        cnt = 0
        while cnt < n:
            while len(stack) != 0:
                if nums[idx] >= stack[0]:
                    stack.pop(0)
                else:
                    break

            if len(stack) == 0:
                res[idx] = -1
            else:
                res[idx] = stack[0]
            
            stack.insert(0, nums[idx])
            cnt += 1
            idx -= 1
            if idx < 0:
                idx += n
        
        return res


