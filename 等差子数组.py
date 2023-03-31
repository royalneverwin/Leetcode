class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        m = len(l)
        n = len(nums)
        res = [False] * m
        for i in range(m):
            sub_nums = nums[l[i]:r[i]+1]
            sub_nums.sort()
            flag = True
            for j in range(1, r[i]-l[i]):
                if sub_nums[j+1]-sub_nums[j] != sub_nums[1]-sub_nums[0]:
                    flag = False
                    break
            if flag:
                res[i] = True

        return res