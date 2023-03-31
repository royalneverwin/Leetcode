class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        # 本质：找不同 非0整数个数
        return len(set(nums) - {0})