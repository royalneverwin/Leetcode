class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        check = defaultdict(int)
        for row in grid:
            check[tuple(row)] += 1

        n = len(grid)
        res = 0
        for j in range(n):
            col = []
            for i in range(n):
                col.append(grid[i][j])

            col = tuple(col)
            res += check[col]

        return res



