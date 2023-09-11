class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        mod_0 = []
        mod_1 = []
        mod_2 = []
        for i in nums:
            if i % 3 == 0:
                mod_0.append(i)
            elif i % 3 == 1:
                mod_1.append(i)
            else:
                mod_2.append(i)

        min_one = min(len(mod_1), len(mod_2))
        mod_1.sort()
        mod_2.sort()
        total = sum(nums)
        if total % 3 == 0:
            return total
        elif total % 3 == 1:
            if len(mod_1) == 0 and len(mod_2) < 2:
                return 0
            elif len(mod_1) == 0:
                return total-mod_2[0]-mod_2[1]
            elif len(mod_2) < 2:
                return total-mod_1[0]
            else:
                return max(total-mod_1[0], total-mod_2[0]-mod_2[1])
        else:
            if len(mod_2) == 0 and len(mod_1) < 2:
                return 0
            elif len(mod_2) == 0:
                return total-mod_1[0]-mod_1[1]
            elif len(mod_1) < 2:
                return total-mod_2[0]
            else:
                return max(total-mod_2[0], total-mod_1[0]-mod_1[1])
