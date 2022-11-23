class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        cur, res = 0, 0
        for num in gain:
            cur += num
            res = max(res, cur)
        return res
