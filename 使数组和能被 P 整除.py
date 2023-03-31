class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        # presum[j] mod p = (presum[i] - x) mod p, x = sum mod p, j > i
        # 遍历j 找 i, 因为最短所以找i最大，存presum[i] mod p 最大即可
        n = len(nums)
        total = sum(nums)
        left = total % p
        if left == 0:
            return 0

        left_dict = {0: -1}
        presum = [0 for i in range(n+1)] # 不包括nums[i]的前缀和
        res = 1000000000

        for i in range(n):
            presum[i+1] = presum[i] + nums[i]
            cur_left = presum[i+1] % p
            if cur_left in left_dict:
                left_dict[cur_left] = max(left_dict[cur_left], i)
            else:
                left_dict[cur_left] = i

            if cur_left-left in left_dict:
                res = min(res, i-left_dict[cur_left-left])

            elif cur_left-left+p in left_dict:
                res = min(res, i-left_dict[cur_left-left+p])

        if res == n:
            return -1
        else:
            return res



