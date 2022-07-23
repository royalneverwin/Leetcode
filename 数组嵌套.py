class Solution:

    def arrayNesting(self, nums: List[int]) -> int:
        res = 0
        flag = [False for i in nums]
        for i in range(len(nums)):
            if flag[i] == False:
                cnt = 1
                idx = i
                flag[idx] = True
                while flag[nums[idx]] == False:
                    flag[nums[idx]] = True
                    idx = nums[idx]
                    cnt += 1
                res = max(res, cnt)
        return res





