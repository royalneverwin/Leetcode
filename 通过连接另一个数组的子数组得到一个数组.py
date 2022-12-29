class Solution:
    def canChoose(self, groups: List[List[int]], nums: List[int]) -> bool:
        idx = 0
        for group in groups:
            while idx <= len(nums) - len(group):
                if nums[idx:idx+len(group)] == group:
                    idx += len(group)
                    break
                else:
                    idx += 1

            else:
                return False


        return True

