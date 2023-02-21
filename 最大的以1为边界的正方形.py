class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        # 用left和up可以正向遍历
        left = [[0 for j in range(n)] for i in range(m)]
        up = [[0 for j in range(n)] for i in range(m)]
        max_border = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    left[i][j] = 0
                    up[i][j] = 0
                else:
                    if j > 0:
                        left[i][j] = left[i][j-1] + 1
                    else:
                        left[i][j] = 1

                    if i > 0:
                        up[i][j] = up[i-1][j] + 1
                    else:
                        up[i][j] = 1
                    border = min(left[i][j], up[i][j])

                    while border > 1:
                        if up[i][j-border+1] >= border and left[i-border+1][j] >= border:
                            break
                        else:
                            border -= 1

                    max_border = max(border, max_border)

        return max_border ** 2
                    