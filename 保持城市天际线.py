class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        n = len(grid)
        max_row = [max(grid[i]) for i in range(n)]
        max_col = [max(grid[i][j] for i in range(n)) for j in range(n)]
        return sum([min(max_row[i//n]-grid[i//n][i%n], max_col[i%n]-grid[i//n][i%n]) for i in range(n**2)])
