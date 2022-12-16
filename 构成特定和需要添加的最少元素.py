class Solution:
    def minElements(self, nums: List[int], limit: int, goal: int) -> int:
        return (abs(goal - sum(nums)) + limit - 1) // limit