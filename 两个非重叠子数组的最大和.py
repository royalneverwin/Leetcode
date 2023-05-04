class Solution:
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
        n = len(nums)
        # pre_sum = [0 for i in range(n)]
        # cur_sum = 0
        # for i in range(n):
        #     cur_sum += nums[i]
        #     pre_sum[i] = cur_sum

        dp1 = [0 for i in range(n)] # 在末尾为i的数组中 firstlen 长度数组最大值
        cur_sum = 0
        for i in range(n):
            cur_sum += nums[i]
            if i < firstLen-1:
                dp1[i] = 0
            else:
                if i >= firstLen:
                    cur_sum -= nums[i-firstLen]
                    dp1[i] = max(dp1[i-1], cur_sum)
                else:
                    dp1[i] = cur_sum

        dp2 = [0 for i in range(n)] # 在末尾为i的数组中 secondlen长度数组最大值
        cur_sum = 0
        for i in range(n):
            cur_sum += nums[i]
            if i < secondLen-1:
                dp2[i] = 0
            else:
                if i >= secondLen:
                    cur_sum -= nums[i-secondLen]
                    dp2[i] = max(dp2[i-1], cur_sum)
                else:
                    dp2[i] = cur_sum

        res = 0
        # f在s之后
        cur_sum = 0
        for i in range(secondLen, secondLen+firstLen):
            cur_sum += nums[i]
        res = max(res, cur_sum+dp2[secondLen-1])
        for i in range(secondLen+firstLen, n):
            cur_sum -= nums[i-firstLen]
            cur_sum += nums[i]
            res = max(res, cur_sum+dp2[i-firstLen])

        # s在f之后
        cur_sum = 0
        for i in range(firstLen, secondLen+firstLen):
            cur_sum += nums[i]
        res = max(res, cur_sum+dp1[firstLen-1])
        for i in range(secondLen+firstLen, n):
            cur_sum -= nums[i-secondLen]
            cur_sum += nums[i]
            res = max(res, cur_sum+dp1[i-secondLen])

        return res




