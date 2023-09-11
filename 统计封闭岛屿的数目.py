class Solution:

    def closedIsland(self, grid: List[List[int]]) -> int:
        def BFS(grid, i, j, m, n):
            nonlocal res
            nonlocal flag
            grid[i][j] = 2
            if i-1 >= 0:
                if grid[i-1][j] == 0:
                    BFS(grid, i-1, j, m, n)
            else:
                flag = False
            if i+1 < m:
                if grid[i+1][j] == 0:
                    BFS(grid, i+1, j, m, n)
            else:
                flag = False

            if j-1 >= 0:
                if grid[i][j-1] == 0:
                    BFS(grid, i, j-1, m, n)
            else:
                flag = False

            if j+1 < n:
                if grid[i][j+1] == 0:
                    BFS(grid, i, j+1, m, n)
            else:
                flag = False
        m = len(grid)
        n = len(grid[0])
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    flag = True
                    BFS(grid, i, j, m, n)
                    if flag:
                        res += 1
        return res
    