class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        # 从一个岛BFS到另一个
        qu = []
        m, n = len(grid), len(grid[0])
        dis = [[0, 1], [0, -1], [-1, 0], [1, 0]]

        def add(grid, x, y, qu):
            qu.append((x, y, 0))
            grid[x][y] = 2
            nonlocal dis
            nonlocal m
            nonlocal n
            for d in dis:
                if x+d[0] >= 0 and x+d[0] < m and y+d[1] >= 0 and y+d[1] < n and grid[x+d[0]][y+d[1]] == 1:
                    add(grid, x+d[0], y+d[1], qu)

        for i in range(m):
            flag = False
            for j in range(n):
                if grid[i][j] == 1:
                    add(grid, i, j, qu)
                    flag = True
                    break
            if flag:
                break

        while qu != []:
            tmp = qu.pop(0)
            x, y = tmp[0], tmp[1]
            for d in dis:
                if x+d[0] >= 0 and x+d[0] < m and y+d[1] >= 0 and y+d[1] < n:
                    if grid[x+d[0]][y+d[1]] == 1:
                        return tmp[2]
                    elif grid[x+d[0]][y+d[1]] == 0:
                        qu.append((x+d[0], y+d[1], tmp[2]+1))
                        grid[x+d[0]][y+d[1]] = 2

        return -1






