class Solution:
    def minPushBox(self, grid: List[List[str]]) -> int:
        # 记录箱子的位置和终点的位置
        tx, ty, bx, by, sx, sy = 0, 0, 0, 0, 0, 0
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 'B':
                    bx, by = i, j
                elif grid[i][j] == 'T':
                    tx, ty = i, j
                elif grid[i][j] == 'S':
                    sx, sy = i, j
        flag = dict()
        qu = deque()
        qu.append((bx, by, sx, sy, 0))
        status = (bx << 15) + (by << 10) + (sx << 5) + sy # 用status避免重复搜索
        flag[status] = 0
        res = 1e9
        while qu:
            bx, by, sx, sy, step = qu.popleft()
            # print(bx, by, sx, sy, step)
            directs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
            for d in directs:
                new_x, new_y = sx+d[0], sy+d[1]
                if new_x < 0 or new_x == m or new_y < 0 or new_y == n:
                    continue
                if bx == new_x and by == new_y: # 要推箱子
                    if bx == sx-1: # 向上
                        if bx > 0 and grid[bx-1][by] != '#': # 可以推
                            new_bx, new_by = bx-1, by
                            if new_bx == tx and new_by == ty:
                                res = min(res, step+1)
                                continue
                            new_status = (new_bx << 15) + (new_by << 10) + (new_x << 5) + new_y
                            if new_status not in flag or flag[new_status] > step+1:
                                flag[new_status] = step+1
                                qu.append((new_bx, new_by, new_x, new_y, step+1))
                    elif bx == sx+1: # 向下
                        if bx < m-1 and grid[bx+1][by] != '#': # 可以推
                            new_bx, new_by = bx+1, by
                            if new_bx == tx and new_by == ty:
                                res = min(res, step+1)
                                continue
                            new_status = (new_bx << 15) + (new_by << 10) + (new_x << 5) + new_y
                            if new_status not in flag or flag[new_status] > step+1:
                                flag[new_status] = step+1
                                qu.append((new_bx, new_by, new_x, new_y, step+1))
                    elif by == sy-1: # 向左
                        if by > 0 and grid[bx][by-1] != '#': # 可以推
                            new_bx, new_by = bx, by-1
                            if new_bx == tx and new_by == ty:
                                res = min(res, step+1)
                                continue
                            new_status = (new_bx << 15) + (new_by << 10) + (new_x << 5) + new_y
                            if new_status not in flag or flag[new_status] > step+1:
                                flag[new_status] = step+1
                                qu.append((new_bx, new_by, new_x, new_y, step+1))
                    elif by == sy+1: # 向右
                        if by < n-1 and grid[bx][by+1] != '#': # 可以推
                            new_bx, new_by = bx, by+1
                            if new_bx == tx and new_by == ty:
                                res = min(res, step+1)
                                continue
                            new_status = (new_bx << 15) + (new_by << 10) + (new_x << 5) + new_y
                            if new_status not in flag or flag[new_status] > step+1:
                                flag[new_status] = step+1
                                qu.append((new_bx, new_by, new_x, new_y, step+1))
                    else:
                        assert False
                elif grid[new_x][new_y] != '#': # 不是障碍物
                    # 检查是否出现过这种情况
                    new_status = (bx << 15) + (by << 10) + (new_x << 5) + new_y
                    if new_status not in flag or flag[new_status] > step+1:
                        flag[new_status] = step+1
                        qu.append((bx, by, new_x, new_y, step))
        if res == 1e9:
            return -1
        else:
            return res




                    