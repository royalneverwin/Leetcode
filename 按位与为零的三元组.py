class Solution:
    def countTriplets(self, nums: List[int]) -> int:
        n = len(nums)
        my_hash = {}
        for i in range(n):
            for j in range(n):
                num = nums[i] & nums[j]
                if num in my_hash:
                    my_hash[num] += 1
                else:
                    my_hash[num] = 1

        res = 0
        for key, val in my_hash.items():
            for k in range(n):
                if key & nums[k] == 0:
                    res += val

        return res