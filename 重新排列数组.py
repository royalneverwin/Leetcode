class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        return [nums[i//2] if i%2 == 0 else nums[len(nums)//2+i//2] for i in range(len(nums))]