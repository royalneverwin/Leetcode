class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[0])
        n = len(points)
        res = 0
        for i in range(n-1):
            res = max(points[i+1][0]-points[i][0], res)
        return res
