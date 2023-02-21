class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        def Rev(n):
            res = 0
            while n > 0:
                res = res * 10 + n % 10
                n //= 10
            return res


        rev = {}
        good_list = {}
        n = len(nums)

        for i in range(n):
            if nums[i] not in rev:
                rev[nums[i]] = Rev(nums[i])
            if nums[i]-rev[nums[i]] not in good_list:
                good_list[nums[i]-rev[nums[i]]] = [i]
            else:
                good_list[nums[i]-rev[nums[i]]].append(i)

        res = 0
        for key, val in good_list.items():
            res = (res + len(val) * (len(val)-1) // 2) % (1000000007)

        return res




                