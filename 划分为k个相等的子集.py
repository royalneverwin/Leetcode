class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total = sum(nums)
        if total % k != 0:
            return False
        per = total // k
        nums.sort() # 排序 进行简单剪枝
        if nums[-1] > per: # 否则下面会死循环
            return False

        @cache
        def DFS(valid, cur): # 计算出每组的sum 然后用cur和nums的valid组合出sum 计算每一种可能
            nonlocal per
            nonlocal nums
            if valid == 0:
                return True
            for i in range(len(nums)):
                if cur + nums[i] <= per:
                    if (valid & (1 << i)) and DFS(valid ^ (1 << i), (cur + nums[i]) % per):
                        return True
            return False

        return DFS((1 << len(nums)) - 1, 0)