class Solution:
    def distinctAverages(self, nums: List[int]) -> int:
        res = set()
        while nums != []:
            max_one = max(nums)
            min_one = min(nums)
            nums.remove(max_one)
            nums.remove(min_one)
            res.add((max_one+min_one)/2)
        return len(res)