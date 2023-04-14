class Solution:
    def mostFrequentEven(self, nums: List[int]) -> int:
        cnt = {}
        n = len(nums)
        for i in range(n):
            if nums[i] % 2 == 0:
                if nums[i] in cnt:
                    cnt[nums[i]] += 1
                else:
                    cnt[nums[i]] = 1

        res, max_cnt = 0, 0
        for key, val in cnt.items():
            if val > max_cnt:
                res = key
                max_cnt = val
            elif val == max_cnt:
                res = min(res, key)

        if max_cnt == 0:
            return -1
        return res