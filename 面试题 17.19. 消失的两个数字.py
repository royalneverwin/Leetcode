class Solution:
    def missingTwo(self, nums: List[int]) -> List[int]:
        flag1, flag2 = False, False # 记录放不到nums里的两个大数
        idx = 0
        res1, res2 = 0, 0
        while idx < len(nums):
            if nums[idx] != idx+1:
                nxt_idx = nums[idx]-1
                while nxt_idx < len(nums) and nxt_idx != idx:
                    if nums[nxt_idx] == nxt_idx+1:
                        break
                    tmp = nums[nxt_idx]
                    nums[nxt_idx] = nxt_idx+1
                    nxt_idx = tmp-1


                if nxt_idx == len(nums):
                    flag1 = True
                elif nxt_idx == len(nums)+1:
                    flag2 = True
                else:
                    nums[nxt_idx] = nxt_idx+1

            idx += 1


        for i in range(len(nums)):
            if nums[i] != i+1:
                if res1 == 0:
                    res1 = i+1
                else:
                    res2 = i+1

        if res1 == 0:
            return [len(nums)+1, len(nums)+2]

        if flag1 == False:
            res2 = len(nums)+1

        if flag2 == False:
            res2 = len(nums)+2

        return [res1, res2]

