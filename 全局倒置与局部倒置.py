class Solution:
    def isIdealPermutation(self, nums: List[int]) -> bool:
        idx = 0
        while idx < len(nums):
            if idx != len(nums)-1 and nums[idx] > nums[idx+1]:
                if nums[idx] == idx+1 and nums[idx+1] == idx: # 显然
                    idx += 2
                else:
                    return False
            else:
                idx += 1

        return True

