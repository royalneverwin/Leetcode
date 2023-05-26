class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        flag = [[0 for i in range(n)] for j in range(n)]

        if grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return -1

        qu = deque()
        flag[0][0] = 1
        qu.append((0, 0, 1))

        while qu:
            x, y, step = qu.popleft()
            if x == n-1 and y == n-1:
                return step
            dis = [[0, 1], [0, -1], [1, 0], [-1, 0], [1, 1], [1, -1], [-1, 1], [-1, -1]]
            for d in dis:
                new_x = x+d[0]
                new_y = y+d[1]
                if new_x >= 0 and new_x <= n-1 and new_y >= 0 and new_y <= n-1:
                    if grid[new_x][new_y] == 0 and flag[new_x][new_y] == 0:
                        flag[new_x][new_y] = 1
                        qu.append((new_x, new_y, step+1))

        return -1


