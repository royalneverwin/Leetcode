class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        n = len(nums)
        pre_sum1 = [0 for i in range(n)] # 奇数位前缀和
        pre_sum2 = [0 for i in range(n)] # 偶数位前缀和
        cur_sum1, cur_sum2 = 0, 0
        for i in range(n):
            if i % 2 == 1:
                cur_sum1 += nums[i]
            else:
                cur_sum2 += nums[i]

            pre_sum1[i] = cur_sum1
            pre_sum2[i] = cur_sum2

        res = 0
        if pre_sum2[n-1]-nums[0] == pre_sum1[n-1]: # 删去index = 0
            res += 1
        for i in range(1, n):
            pre1 = pre_sum1[i-1]
            pre2 = pre_sum2[i-1]
            nxt2 = pre_sum1[n-1]-pre_sum1[i]
            nxt1 = pre_sum2[n-1]-pre_sum2[i]
            if pre1 + nxt1 == pre2 + nxt2:
                res += 1

        return res
