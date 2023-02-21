class Solution:
    def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
        n = len(queries)
        res = [0 for i in range(n)]
        i = 0
        for query in queries:
            for point in points:
                if (point[0] - query[0]) ** 2 + (point[1] - query[1]) ** 2 <= query[2] ** 2:
                    res[i] += 1

            i += 1

        return res