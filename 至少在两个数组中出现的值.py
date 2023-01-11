class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        dp = {}
        flags = [set(), set(), set()]
        nums = [nums1, nums2, nums3]
        for idx in range(3):
            for num in nums[idx]:
                if num not in flags[idx]:
                    if num in dp:
                        dp[num] += 1
                    else:
                        dp[num] = 1
                    flags[idx].add(num)

        res = []
        for (key, value) in dp.items():
            if value >= 2:
                res.append(key)

        return res

