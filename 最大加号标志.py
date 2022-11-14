class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        grid = [[1 for i in range(n)] for j in range(n)]
        left = [[0 for i in range(n)] for j in range(n)]
        right = [[0 for i in range(n)] for j in range(n)]
        up = [[0 for i in range(n)] for j in range(n)]
        down = [[0 for i in range(n)] for j in range(n)]

        for mine in mines:
            grid[mine[0]][mine[1]] = 0

        for i in range(n):
            for j in range(n):
                if j == 0:
                    # left
                    if grid[i][j] == 1:
                        left[i][j] = 1
                    else:
                        left[i][j] = 0
                    # right
                    if grid[i][n-1-j] == 1:
                        right[i][n-1-j] = 1
                    else:
                        right[i][n-1-j] = 0
                    # up
                    if grid[j][i] == 1:
                        up[j][i] = 1
                    else:
                        up[j][i] = 0
                    # down
                    if grid[n-1-j][i] == 1:
                        down[n-1-j][i] = 1
                    else:
                        down[n-1-j][i] = 0
                else:
                    # left
                    if grid[i][j] == 1:
                        left[i][j] = left[i][j-1]+1
                    else:
                        left[i][j] = 0
                    # right
                    if grid[i][n-1-j] == 1:
                        right[i][n-1-j] = right[i][n-j]+1
                    else:
                        right[i][n-1-j] = 0
                    # up
                    if grid[j][i] == 1:
                        up[j][i] = up[j-1][i]+1
                    else:
                        up[j][i] = 0
                    # down
                    if grid[n-1-j][i] == 1:
                        down[n-1-j][i] = down[n-j][i]+1
                    else:
                        down[n-1-j][i] = 0

        res = 0
        for i in range(n):
            for j in range(n):
                res = max(res, min(left[i][j], right[i][j], up[i][j], down[i][j]))

        return res





