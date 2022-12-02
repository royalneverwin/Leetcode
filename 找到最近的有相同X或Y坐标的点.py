class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        min_dis = 1000000
        res = -1
        for i in range(len(points)):
            if points[i][0] == x:
                if abs(points[i][1]-y) < min_dis:
                    min_dis = abs(points[i][1]-y)
                    res = i

            elif points[i][1] == y:
                if abs(points[i][0]-x) < min_dis:
                    min_dis = abs(points[i][0]-x)
                    res = i

        return res