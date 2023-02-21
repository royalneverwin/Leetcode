class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        cnt = [0 for i in range(101)]
        for n in nums:
            cnt[n] += 1
        res = 0
        for c in cnt:
            res += c // 2

        return (res, len(nums)-2*res)