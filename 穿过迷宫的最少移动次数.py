class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        qu = deque()
        n = len(grid)
        qu.append((0, 1, 0, 0)) # 蛇头x, y, 蛇身z（0水平，1竖直）, 步数n
        visited = set()
        visited.add((0, 1, 0))
        while qu:
            x, y, pos, cnt = qu.popleft()
            if x == n-1 and y == n-1 and pos == 0:
                return cnt
            # 旋转
            if pos == 0:
                if x != n-1:
                    if grid[x+1][y-1] == 0 and grid[x+1][y] == 0: # 可以旋转
                        if (x+1, y-1, 1) not in visited:
                            qu.append((x+1, y-1, 1, cnt+1))
                            visited.add((x+1, y-1, 1))
            else:
                if y != n-1:
                    if grid[x-1][y+1] == 0 and grid[x][y+1] == 0: # 可以旋转
                        if (x-1, y+1, 0) not in visited:
                            qu.append((x-1, y+1, 0, cnt+1))
                            visited.add((x-1, y+1, 0))

            # 向右
            if y != n-1:
                if (pos == 0 and grid[x][y+1] == 0) or \
                        (pos == 1 and grid[x][y+1] == 0 and grid[x-1][y+1] == 0):
                    if (x, y+1, pos) not in visited:
                        qu.append((x, y+1, pos, cnt+1))
                        visited.add((x, y+1, pos))
            # 向下
            if x != n-1:
                if (pos == 1 and grid[x+1][y] == 0) or \
                        (pos == 0 and grid[x+1][y] == 0 and grid[x+1][y-1] == 0):
                    if (x+1, y, pos) not in visited:
                        qu.append((x+1, y, pos, cnt+1))
                        visited.add((x+1, y, pos))

        return -1