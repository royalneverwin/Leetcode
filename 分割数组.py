class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        enum = list(enumerate(nums))
        enum.sort(key=lambda a: a[1])
        cnt = 0
        max_idx = 0
        for i in enum:
            cnt += 1
            max_idx = max(max_idx, i[0])
            if cnt == max_idx+1:
                return cnt
        return -1